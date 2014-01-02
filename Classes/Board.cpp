#include "Board.h"
#include "Game.h"
USING_NS_CC;

Board::Board(): _grid(SCREEN_WIDTH/GRID_SIZE, SCREEN_HEIGHT/GRID_SIZE) {
  _node = Sprite::create("objetos/tablero_fondo.png");
  _populater = NULL;
}

Board* Board::create() {
  Board* obj = new Board();
  if(obj) {
    obj->autorelease();
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

  spheres.push_back(last_sphere);
  do{
    drop_sphere = _grid.pop(pos.x);
    if(drop_sphere->getType() == last_sphere->getType()) {
      spheres.push_back(drop_sphere);
    }else{
      _grid.push(pos.x, drop_sphere);
      break;
    }
  }while(1);
  return spheres;
}

void Board::takeSphere(int col, GroupSphere& spheres) {
  for(auto it = spheres.begin(); it != spheres.end(); it++) {
    _grid.push(col, (*it));
  }
}

void Board::attachMatch(std::function<void(GroupSphere)> func) {
  onAttachMatch.push_back(func);
}

void Board::attachEndBoard(std::function<void(void)> func) {
  onAttachEndBoard.push_back(func);
}

Node* Board::getView() {
  return _node;
}


void Board::_roll() {
}

GroupSphere Board::_match(PointGrid start) {
  GroupSphere spheres;
  return spheres;
}
