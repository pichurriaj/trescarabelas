#ifndef INDIAN_H
#define INDIAN_H

#include "cocos2d.h"
#include "PointGrid.h"
#include "Sphere.h"
#include <vector>
/**
 *Representa el jugador
 *aunque este es atraves de comandos
 */
class Indian :  public cocos2d::Object
{
 public:
  Indian();
  static Indian* create();
  
  void update(float dt);
  void jumpTo(int);
  /**
   *Solo guarda si son del mismo tipo
   */
  bool takeSphere(Sphere** sphere);
  GroupSphere getBag();
  unsigned int countOnBag();
  SphereType typeOnBag();
  /*Animaciones*/
  void animateStand();
  void animateTake();
  void animateDrop();
  void animateLose(){}
  void animateWin(){}
  void animateWithoutTime(){}
  cocos2d::Node* getView();
  PointGrid getPosition() const { return _pos; }
  //CC_SYNTHESIZE(cocos2d::Array*, _hold_bag, HoldBag);
 private:
  cocos2d::Animation *_anim_stand;
  cocos2d::Animation *_anim_take;
  cocos2d::Animation *_anim_drop;
  cocos2d::Animation *_anim;
  GroupSphere _hold_bag;
  Sphere *_sphere_on_hands;
  PointGrid _pos;
  cocos2d::Node *_view;
};

#endif
