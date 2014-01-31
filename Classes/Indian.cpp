#include "Indian.h"
USING_NS_CC;

Indian::Indian() :  _pos(0,0){
}

bool Indian::init(){
  if(!Node::init()){
    return false;
  }
  _hold_bag = new GroupSphere;
  return true;
}

void Indian::update(float dt){
}

void Indian::jumpTo(PointGrid pg){
  _pos = pg;
  this->setPosition(_pos.toPoint());
}

bool Indian::grabSphere(Sphere* sphere){
  if(_hold_bag->size() == 0){
    sphere->retain();
    _hold_bag->push_back(sphere);
  }else{
    for(auto it = _hold_bag->begin(); it != _hold_bag->end(); it++){
      if((*it)->getType() != sphere->getType()) return false;
    }
  }
  return true;
}

GroupSphere* Indian::getBag(){
  GroupSphere* new_bag = new GroupSphere;
  for(auto it = _hold_bag->begin(); it != _hold_bag->end(); it++){
    (*it)->retain();
    new_bag->push_back((*it));
  }
  _hold_bag->clear();
  return new_bag;
}

void Indian::animateStand(){
}

void Indian::animateTake(){
}

void Indian::animateDrop(){
}

