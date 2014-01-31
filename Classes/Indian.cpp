#include "Indian.h"
USING_NS_CC;

bool Indian::init(){
  if(!Node::init()){
    return false;
  }
  _hold_bag = Array::createWithCapacity(30);
  return true;
}

void Indian::update(float dt){
}

void Indian::jumpTo(PointGrid pg){
  _pos = pg;
  this->setPosition(_pos.toPoint());
}

bool Indian::takeSphere(Sphere** sphere){
  Sphere* sp = Sphere::create(SPHERE_RED);
  std::cout << "capacity: " << _hold_bag->capacity() << std::endl;
  _hold_bag->addObject(sp);

  return true;
}

GroupSphere Indian::getBag(){
  GroupSphere new_bag;
  /*for(auto it = _hold_bag.begin(); it != _hold_bag.end(); it++){
    (*it)->retain();
    new_bag.push_back((*it));
  }
  _hold_bag.clear();
  return new_bag;*/
  return new_bag;
}

void Indian::animateStand(){
}

void Indian::animateTake(){
}

void Indian::animateDrop(){
}

