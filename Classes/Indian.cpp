#include "Indian.h"
USING_NS_CC;

Indian::Indian(){
  _anim_stand = _anim_take = _anim_drop = _anim = NULL;
  _sphere_on_hands = NULL;

  _anim_stand = Animation::create();
  _anim_stand->addSpriteFrameWithFile("personajes/espera1.png");
  _anim_stand->addSpriteFrameWithFile("personajes/espera2.png");
  _anim_stand->addSpriteFrameWithFile("personajes/espera1.png");
  _anim_stand->addSpriteFrameWithFile("personajes/espera3.png");
  _anim_stand->setRestoreOriginalFrame(true);
  _anim_stand->setDelayPerUnit(0.5);
  _anim_stand->retain();

  _anim_take = Animation::create();
  _anim_take->addSpriteFrameWithFile("personajes/recibeotira3.png");
  _anim_take->addSpriteFrameWithFile("personajes/recibeotira2.png");
  _anim_take->addSpriteFrameWithFile("personajes/recibeotira1.png");
  _anim_take->setDelayPerUnit(0.03);
  _anim_take->setRestoreOriginalFrame(true);
  _anim_take->setLoops(1);
  _anim_take->retain();

  _anim_drop = Animation::create();
  _anim_drop->addSpriteFrameWithFile("personajes/recibeotira1.png");
  _anim_drop->addSpriteFrameWithFile("personajes/recibeotira2.png");
  _anim_drop->addSpriteFrameWithFile("personajes/recibeotira3.png");
  _anim_drop->setLoops(1);
  _anim_drop->setDelayPerUnit(0.05);
  _anim_drop->retain();

  _view = Sprite::create("personajes/espera1.png");
  animateStand();
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

void Indian::jumpTo(int col){

  Point pxy = PointGrid(col, 0).toPoint();
  pxy.x += _view->getContentSize().width/2;
  pxy.y = _view->getContentSize().height + 10;
  _view->setPosition(pxy);
}

bool Indian::takeSphere(Sphere** sphere){
  _hold_bag.push_back(*sphere);
  if(!_sphere_on_hands){
    _sphere_on_hands = Sphere::create((*sphere)->getType());
    _sphere_on_hands->retain();
    Node *sphere_view = _sphere_on_hands->getView();
    sphere_view->retain();
    Point pos = Point::ZERO;
    pos.x = _view->getContentSize().width/2;
    pos.y = _view->getContentSize().height/2;
    sphere_view->setPosition(pos);
    _view->addChild(sphere_view);
  }
  return true;
}

GroupSphere Indian::getBag(){
  GroupSphere new_bag;
  for(auto it = _hold_bag.begin(); it != _hold_bag.end(); it++){
    (*it)->retain();
    new_bag.push_back((*it));
  }
  _hold_bag.clear();
  if(_sphere_on_hands){
    _sphere_on_hands->viewRemoveFromParent();
    _sphere_on_hands->autorelease();
    CC_SAFE_DELETE(_sphere_on_hands);
    _sphere_on_hands = NULL;
  }
  return new_bag;
}

SphereType Indian::typeOnBag(){
  if(_hold_bag.size() > 0)
    return _hold_bag[0]->getType();
  return SPHERE_COUNT;
}

void Indian::animateStand(){
  //_view->stopAllActions();
  //_view->unscheduleAllSelectors();
  _view->runAction(RepeatForever::create(Animate::create(_anim_stand)));
}

void Indian::animateTake(){
  _view->runAction(Sequence::create(
				    Animate::create(_anim_take)
				    ,NULL
				    )
		   );
}

void Indian::animateDrop(){

  _view->runAction(Animate::create(_anim_drop));
}

Node* Indian::getView() {
  return _view;
}
