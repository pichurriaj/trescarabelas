#include "Board.h"
#include "Game.h"
USING_NS_CC;

Board::Board() : _grid(SCREEN_WIDTH/GRID_SIZE, SCREEN_HEIGHT/GRID_SIZE)  {
  _node = Sprite::create("objetos/tablero_fondo.png");
  _grid.setCols(_node->getContentSize().width/GRID_SIZE);
  _grid.setRows(_node->getContentSize().height/GRID_SIZE);
  _populater = NULL;
  _grid.setEmpty(NULL);
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


GroupSphere Board::dropSphere(PointGrid pos) {
  GroupSphere spheres;
  Sphere* last_sphere = _grid.pop(pos.x);
  Sphere* drop_sphere = NULL;
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

GroupSphere Board::dropSphere(int col){
  return dropSphere(PointGrid(col, 0));
}

GroupSphere Board::dropSphere(int col, SphereType sphere_type) {
  GroupSphere spheres;
  PointGrid pos(col, 0);

  Sphere* last_sphere = _grid.pop(pos.x);
  Sphere* drop_sphere = NULL;
  if(_grid.Empty(last_sphere)) return spheres;
  if(sphere_type != SPHERE_COUNT && last_sphere->getType() != sphere_type){
    _grid.push_front(col, last_sphere);
    return spheres;
  }
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

void Board::takeSphere(int col, GroupSphere& spheres) {
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
  
  _match(PointGrid(col,_grid.getRows()));
}

void Board::attachMatch(std::function<void(GroupSphere,unsigned int)> func) {
  onAttachMatch.push_back(func);
}

void Board::attachEndBoard(std::function<void(GroupSphere)> func) {
  onAttachEndBoard.push_back(func);
}

void Board::attachRoll(std::function<void(GroupSphere)> func) {
  onAttachRoll.push_back(func);
}

Node* Board::getView() {
  _node->retain();
  return _node;
}

void Board::updateView() {
  for(int col = _grid.getCols(); col > 0; col--){
    for(int row = _grid.getRows(); row > 0; row--){
      try{
	Sphere* data = static_cast<Sphere*>(_grid.get(PointGrid(col, row)));

	if(!_grid.Empty(data)){
	  data->updateView(GRID_SIZE/2, _node->getContentSize().height);
	}
      }catch(std::exception &re) {
	std::cerr << "Error:" << re.what() << std::endl;
      }
    }
  }
}

void Board::roll(GroupSphere spheres) {
  int col = 0;
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
      try{
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
	}
      }catch(std::exception &re) {
	std::cerr << "Error:" << re.what() << std::endl;
      }
    }
    col += 1;
  }
  
  for(auto &func: onAttachRoll) {
    func(spheres);
  }
}


void Board::updateMatch(){
}

GroupSphere Board::_match_right(PointGrid start){
  GroupSphere spheres;
  Sphere* start_sphere = _grid.getPop(start.x);
  int last_row = start.y;
  if(_grid.Empty(start_sphere)) return spheres;
  if(start.x + 1 >= _grid.getCols()){
    return spheres;
  }

  for(int row=last_row; row >= 0; row--){
    PointGrid pos_right_match(start.x + 1, row);
    Sphere* sphere_to_match_right = _grid.get(pos_right_match);
    if(pos_right_match.x >= _grid.getCols()){
      return spheres;
    }

    if(_grid.Empty(sphere_to_match_right) || sphere_to_match_right->getType() != start_sphere->getType()){
      return spheres;
    }
    spheres.push_back(sphere_to_match_right);
    std::cout << "Match::PosMatch:Right " << pos_right_match.x << "," << row  << "Type:" << sphere_to_match_right->getType() << std::endl;
    GroupSphere spheres_right = this->_match_right(pos_right_match);
    for(auto it = spheres_right.begin(); it != spheres_right.end(); it++){
      spheres.push_back((*it));
    }
  }
  return spheres;
}


GroupSphere Board::_match_left(PointGrid start){
  GroupSphere spheres;
  Sphere* start_sphere = _grid.getPop(start.x);
  int last_row = start.y;
  if(_grid.Empty(start_sphere)) return spheres;
  if(start.x - 1 < 0){
    return spheres;
  }

  for(int row=last_row; row >= 0; row--){
    PointGrid pos_left_match(start.x - 1, row);
    Sphere* sphere_to_match_left = _grid.get(pos_left_match);
    if(pos_left_match.x < 0){
      return spheres;
    }

    if(_grid.Empty(sphere_to_match_left) || sphere_to_match_left->getType() != start_sphere->getType()){
      return spheres;
    }
    spheres.push_back(sphere_to_match_left);
    std::cout << "Match::PosMatch:Left " << pos_left_match.x << "," << row  << "Type:" << sphere_to_match_left->getType() << std::endl;
    GroupSphere spheres_left = this->_match_left(pos_left_match);
    for(auto it = spheres_left.begin(); it != spheres_left.end(); it++){
      spheres.push_back((*it));
    }
  }
  return spheres;
}


GroupSphere Board::_match(PointGrid start) {
  GroupSphere spheres;
  Sphere* start_sphere = _grid.getPop(start.x);
  unsigned int start_count_match = 0;
  if(_grid.Empty(start_sphere)) return spheres;
  std::cout << "Match::PoinTStart:" << start.x << " LastRow:" << _grid.getLastRow(start.x) << std::endl;
  std::cout << "Match::StartSphereType:" << start_sphere->getType() << std::endl;
  //start_sphere->retain();
  if(!_grid.Empty(start_sphere)){
    start_count_match += 1;
    spheres.push_back(start_sphere);
    //vertical
    int last_row = _grid.getLastRow(start.x) - 1;
    if(last_row < 0) return spheres;
    for(int row=last_row; row >= 0; row--){
      PointGrid pos_match(start.x, row);

      Sphere* sphere_to_match = _grid.get(pos_match);
      //sphere_to_match->retain();
      if(!_grid.Empty(sphere_to_match) && sphere_to_match->getType() == start_sphere->getType()){
	spheres.push_back(sphere_to_match);
	start_count_match += 1;
      }else{
	break;
      }
      std::cout << "Match::PosMatch: " << start.x << "," << row  << "Type:" << sphere_to_match->getType() << std::endl;
      //por derecha

      GroupSphere spheres_right = _match_right(PointGrid(start.x, row));
      for(auto it = spheres_right.begin(); it != spheres_right.end(); it++){
	spheres.push_back((*it));
      }
      //por izquierda
      GroupSphere spheres_left = _match_left(PointGrid(start.x, row));
      for(auto it = spheres_left.begin(); it != spheres_left.end(); it++){
	spheres.push_back((*it));
      }
    }
  }

  for(auto it = onAttachMatch.begin(); it != onAttachMatch.end(); it++){
    (*it)(spheres, start_count_match);
  }
  return spheres;
}
