#include "Indian.h"
USING_NS_CC;

Indian::Indian(){
  
}

Indian* Indian::create(){
  Indian* _s = new Indian();
  if(_s){
    _s->autorelease();
    _s->retain();
    return _s;
  }
  CC_SAFE_DELETE(_s);
  return NULL;
}

void Indian::update(float dt){
}

void Indian::jumpTo(PointGrid pg){
  _pos = pg;
}

bool Indian::takeSphere(Sphere** sphere){
  _hold_bag.push_back(*sphere);
  return true;
}

GroupSphere Indian::getBag(){
  GroupSphere new_bag;
  for(auto it = _hold_bag.begin(); it != _hold_bag.end(); it++){
    (*it)->retain();
    new_bag.push_back((*it));
  }
  _hold_bag.clear();
  return new_bag;
}

SphereType Indian::typeOnBag(){
  if(_hold_bag.size() > 0)
    return _hold_bag[0]->getType();
  return SPHERE_COUNT;
}

void Indian::animateStand(){
}

void Indian::animateTake(){
}

void Indian::animateDrop(){
}

