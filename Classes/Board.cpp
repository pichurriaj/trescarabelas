#include "Board.h"
#include "Game.h"
#include <algorithm>

USING_NS_CC;

Board::Board() : _grid(SCREEN_WIDTH/GRID_SIZE, SCREEN_HEIGHT/GRID_SIZE)  {
  _node = Sprite::create("objetos/tablero_fondo.png");
  _grid.setCols(_node->getContentSize().width/GRID_SIZE);
  _grid.setRows(_node->getContentSize().height/GRID_SIZE + 1);
  _populater = NULL;
  _grid.setEmpty(NULL);

  _match_locker = false;
}

Board* Board::create() {
  Board* obj = new Board();
  if(obj) {

    obj->autorelease();
    obj->retain();
    return obj;
  }
  CC_SAFE_DELETE(obj);
  return NULL;
}

void Board::update(float dt) {
}

GroupSphere Board::dropSphere(PointGrid pos){
  GroupSphere spheres;
  Sphere* last_sphere = _grid.drop(pos);
  spheres.clear();
  if(_grid.Empty(last_sphere)) return spheres;
  last_sphere->getView()->setVisible(false);
  for(auto func = onDropSphere.begin(); func != onDropSphere.end(); func++){
    last_sphere->retain();
    (*func)(last_sphere);
  }
  last_sphere->getView()->setVisible(true);
  last_sphere->viewRemoveFromParent();
  spheres.push_back(last_sphere);
  return spheres;
}

GroupSphere Board::dropSphere(int col) {
  GroupSphere spheres;
  PointGrid pos(col,0);
  Sphere* last_sphere = _grid.pop(pos.x);
  Sphere* drop_sphere = NULL;
  spheres.clear();
  if(_grid.Empty(last_sphere)) return spheres;

  last_sphere->viewRemoveFromParent();
  spheres.push_back(last_sphere);
  do{

    drop_sphere = _grid.pop(pos.x);
    if(!_grid.Empty(drop_sphere)){
      drop_sphere->retain();
      if(drop_sphere->getType() == last_sphere->getType()) {
	drop_sphere->viewRemoveFromParent();
	spheres.push_back(drop_sphere);
      }else{
	_grid.push(pos.x, drop_sphere);
	break;
      }
    }else{
      break;
    }
  }while(1);
  updateView();
  return spheres;
}


GroupSphere Board::dropSphere(int col, SphereType sphere_type) {
  GroupSphere spheres;
  PointGrid pos(col, 0);

  Sphere* last_sphere = _grid.pop(pos.x);
  Sphere* drop_sphere = NULL;
  spheres.clear();
  if(_grid.Empty(last_sphere)) return spheres;
  if(sphere_type != SPHERE_COUNT && last_sphere->getType() != sphere_type){
    _grid.push(col, last_sphere);
    return spheres;
  }
  last_sphere->viewRemoveFromParent();
  spheres.push_back(last_sphere);
  do{
    drop_sphere = _grid.pop(pos.x);
    if(!_grid.Empty(drop_sphere)){
      drop_sphere->retain();
      if(drop_sphere->getType() == sphere_type) {
	drop_sphere->viewRemoveFromParent();
	spheres.push_back(drop_sphere);
      }else{
	_grid.push(col, drop_sphere);
	break;
      }
    }else{
      break;
    }
  }while(1);
  updateView();
  return spheres;
}

void Board::takeSphere(int col, GroupSphere& spheres) {
  populateCol(col, spheres);
  _match_lock();
  _match(PointGrid(col,_grid.getRows()));
  _match_unlock();
}

void Board::populateCol(int col, GroupSphere& spheres) {
  for(auto it = spheres.begin(); it != spheres.end(); it++) {
    (*it)->retain();
    auto pos = _grid.push(col, (*it));
    auto sphere_view = (*it)->getView();
    sphere_view->retain();
    _node->addChild(sphere_view);
    auto poss = pos.toPoint();
    poss.x += GRID_SIZE/2;
    poss.y *= -1; //invierte, para mostrar hacia abajo
    poss.y += _node->getContentSize().height;
    sphere_view->setPosition(poss);
    (*it)->setPosition(pos);
  }
}


void Board::attachMatch(std::function<void(GroupSphere&,unsigned int)> func) {
  onAttachMatch.push_back(func);
}

void Board::attachEndBoard(std::function<void(GroupSphere)> func) {
  onAttachEndBoard.push_back(func);
}

void Board::attachRoll(std::function<void(GroupSphere)> func) {
  onAttachRoll.push_back(func);
}

void Board::attachFall(std::function<void(GroupSphere&,std::vector<PointGrid>, std::vector<PointGrid>)> func) {
  onAttachFall.push_back(func);
}

void Board::attachDropSphere(std::function<void(Sphere*)> func)
{
  onDropSphere.push_back(func);
}

Node* Board::getView() {
  _node->retain();
  return _node;
}

void Board::updateView() {
  for(int col = _grid.getCols(); col > 0; col--){
    for(int row = _grid.getRows(); row > 0; row--){
      Sphere* data = static_cast<Sphere*>(_grid.get(PointGrid(col, row)));

      if(!_grid.Empty(data)){
	data->updateView(GRID_SIZE/2, _node->getContentSize().height);
      }

    }
  }
}

void Board::roll(GroupSphere spheres) {
  int col = 0;
  GroupSphere spheres_end_board;

  _match_lock();
  spheres_end_board.clear();
  for(auto &sphere: spheres) {

    _grid.push_front(col, sphere);

    auto pos = PointGrid(col, 0);
    sphere->setPosition(pos);
    auto sphere_view = sphere->getView();
    _node->addChild(sphere_view);
    auto poss = pos.toPoint();
    poss.x += GRID_SIZE/2;
    poss.y *= -1; //invierte, para mostrar hacia abajo
    poss.y += _node->getContentSize().height;
    sphere_view->setPosition(poss);
    
    //std::cout << "Rolling sphere first" << std::endl;
    for(int row = _grid.getRows(); row > 0; row--){
      Sphere* data = static_cast<Sphere*>(_grid.get(PointGrid(col, row)));

      if(!_grid.Empty(data)){
	auto pos = PointGrid(col, row);
	auto sphere_view = data->getView();
	data->setPosition(pos);
	auto poss = pos.toPoint();
	poss.x += GRID_SIZE/2;
	poss.y *= -1; //invierte, para mostrar hacia abajo
	poss.y += _node->getContentSize().height;
	sphere_view->setPosition(poss);
	sphere_view->retain();
	//std::cout << "Rolling sphere down" << std::endl;
	if(data->getPosition().y == _grid.getRows() - 1 //@patch para permitir colision ultima esfera
	   ){
	  data->retain();
	  spheres_end_board.push_back(data);
	}
      }
    }
    col += 1;
  }
  _match_unlock();

  for(auto &func: onAttachRoll) {
    func(spheres);
  }


  
  if(spheres_end_board.size()>0){
    for(auto &func: onAttachEndBoard) {
      func(spheres_end_board);
    }
  }


}


void Board::updateMatch(PointGrid start){
  _match_lock();
  _match(start);
  _match_unlock();
}

GroupSphere Board::_match_right(PointGrid start){
  GroupSphere spheres;
  Sphere* start_sphere = _grid.get(start);
  int last_row = start.y;
  if(_grid.Empty(start_sphere)) return spheres;
  if(start.x + 1 >= _grid.getCols()){
    return spheres;
  }
  if(_grid.getLastRow(start.x) == 0) return spheres;
  if(last_row < 0) return spheres;

  for(int row=last_row; row >= 0; row--){
    if(start.x + 1 >= _grid.getCols()) return spheres;
    if(start.x < 0) return spheres;
    
    PointGrid pos_right_match(start.x + 1, row);
    Sphere* sphere_to_match_right = _grid.get(pos_right_match);

    if(_grid.Empty(sphere_to_match_right) || sphere_to_match_right->getType() != start_sphere->getType()){
      return spheres;
    }
    spheres.push_back(sphere_to_match_right);
    std::cout << "Match::PosMatch:Right " << pos_right_match.x << "," << row  << "Type:" << sphere_to_match_right->getType() << std::endl;
    GroupSphere spheres_right = this->_match_right(pos_right_match);
    for(auto it = spheres_right.begin(); it != spheres_right.end(); it++){
      if((*it))
	spheres.push_back((*it));
    }
  }
  return spheres;
}


GroupSphere Board::_match_left(PointGrid start){
  GroupSphere spheres;
  Sphere* start_sphere = _grid.get(start);
  int last_row = start.y;
  spheres.clear();
  if(_grid.getLastRow(start.x) == 0) return spheres;
  if(_grid.Empty(start_sphere)) return spheres;
  if(start.x - 1 < 0 || start.x < 0){
    return spheres;
  }

  if(last_row < 0) return spheres;
  for(int row=last_row; row >= 0; row--){


    PointGrid pos_left_match(start.x - 1, row);
    Sphere* sphere_to_match_left = _grid.get(pos_left_match);


    if(_grid.Empty(sphere_to_match_left) || sphere_to_match_left->getType() != start_sphere->getType()){
      return spheres;
    }
    spheres.push_back(sphere_to_match_left);
    std::cout << "Match::PosMatch:Left " << pos_left_match.x << "," << row  << "Type:" << sphere_to_match_left->getType() << std::endl;
    GroupSphere spheres_left = this->_match_left(pos_left_match);
    for(auto it = spheres_left.begin(); it != spheres_left.end(); it++){
      if((*it))
	spheres.push_back((*it));
    }
  }
  return spheres;
}


GroupSphere Board::_match(PointGrid start) {
  GroupSphere spheres;


  spheres.clear();
  if(start.x < 0) { return spheres; }
  if(start.y < 0) { return spheres; }

  Sphere* start_sphere = _grid.getPop(start.x);
  unsigned int start_count_match = 0;
  if(_grid.Empty(start_sphere)) { return spheres; }
  if(_grid.getLastRow(start.x) == 0) { return spheres; }
  std::cout << "Match::PoinTStart:" << start.x << " LastRow:" << _grid.getLastRow(start.x) << std::endl;
  std::cout << "Match::StartSphereType:" << start_sphere->getType() << std::endl;

  //start_sphere->retain();
  if(!_grid.Empty(start_sphere)){
    start_count_match += 1;
    spheres.push_back(start_sphere);
    //vertical
    int last_row = _grid.getLastRow(start.x);
    if(last_row <= 0) { return spheres; }
    for(int row=last_row; row >= 0; row--){
      PointGrid pos_match(start.x, row);

      Sphere* sphere_to_match = _grid.get(pos_match);
      //sphere_to_match->retain();
      if(!_grid.Empty(sphere_to_match) && 
	 sphere_to_match->getType() == start_sphere->getType()
	 ){
	spheres.push_back(sphere_to_match);
	start_count_match += 1;
      }else{
	break;
      }
      std::cout << "Match::PosMatch: " << start.x << "," << row  << "Type:" << sphere_to_match->getType() << std::endl;
      //por derecha

      GroupSphere spheres_right = _match_right(PointGrid(start.x, row));
      for(auto it = spheres_right.begin(); it != spheres_right.end(); it++){
	if((*it))
	  spheres.push_back((*it));
      }
      //por izquierda
      GroupSphere spheres_left = _match_left(PointGrid(start.x, row));
      for(auto it = spheres_left.begin(); it != spheres_left.end(); it++){
	if((*it))
	  spheres.push_back((*it));
      }
    }
  }

  std::unique(spheres.begin(), spheres.end(),[](Sphere* a, Sphere *b) -> bool{
      return a == b;
    });

  for(auto it = onAttachMatch.begin(); it != onAttachMatch.end(); it++){
    (*it)(spheres, start_count_match);
  }

  return spheres;
}



void Board::fallSpheres(std::function<void(Sphere*,PointGrid)> logic){
  GroupSphere spheres_fall;
  std::vector<PointGrid> spheres_fall_old_pos;
  std::vector<PointGrid> spheres_fall_new_pos;

  _match_lock();

  //esto correge error de mal cambio de columna 0 a 11
  //imprevistamente
  spheres_fall.clear();

  std::cout << "GridCols:" << _grid.getCols() << " GridRows:" << _grid.getRows() << std::endl;
  for(int col=_grid.getCols()-1; col >= 0; col--){
    for(int row=0; row < _grid.getRows(); row++){

      PointGrid sphere_pos(col, row);
      Sphere* sphere = _grid.get(sphere_pos);
      //std::cout << "TryingFallingSphere:" << sphere_pos.x << "," << sphere_pos.y << std::endl;
      if(_grid.Empty(sphere)) continue;
      std::cout << "FallingSphere:" << sphere->getPosition().x << "," << sphere->getPosition().y << " Col: " << col << std::endl;
      sphere->retain();
      PointGrid sphere_new_pos = PointGrid::BAD;
      for(int row_row=row-1; row_row>=0; row_row--){
	if(_grid.Empty(PointGrid(col, row_row))){
	  std::cout << "FallingSphere::newpos:" << sphere_pos.x << "," << row_row << std::endl;
	  sphere_new_pos = PointGrid(col, row_row);
	}else{
	  break;
	}
      }
      if(sphere_new_pos != PointGrid::BAD){
	sphere->retain();
	spheres_fall.push_back(sphere);
	spheres_fall_new_pos.push_back(sphere_new_pos);
	spheres_fall_old_pos.push_back(sphere->getPosition());

	std::cout << "FallingSphere::newpos sended:" << sphere_new_pos.x << "," << sphere_new_pos.y << std::endl;
	
	if(logic)
	  logic(sphere, sphere_new_pos);
	_grid.move(sphere->getPosition(), sphere_new_pos);
	sphere->setPosition(sphere_new_pos);
      }

    }
  }
  _match_unlock();

  for(auto ifunc = onAttachFall.begin(); ifunc != onAttachFall.end(); ifunc++){
    (*ifunc)(spheres_fall, spheres_fall_old_pos, spheres_fall_new_pos);
  }
  std::cout << "FallingSphere::End" << std::endl;

}


void Board::_match_lock() {
  while(_match_locker == true)
    ; //spin
  _match_locker = true;
}

void Board::_match_unlock() {
  _match_locker = false;
}
