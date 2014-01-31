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
  if(last_sphere->getType() != sphere_type){
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
  
}

void Board::attachMatch(std::function<void(GroupSphere)> func) {
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

GroupSphere Board::_match(PointGrid start) {
  GroupSphere spheres;
  return spheres;
}
