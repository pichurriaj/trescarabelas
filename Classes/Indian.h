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
  void jumpTo(PointGrid);
  /**
   *Solo guarda si son del mismo tipo
   */
  bool takeSphere(Sphere** sphere);
  GroupSphere getBag();
  SphereType typeOnBag();
  /*Animaciones*/
  void animateStand();
  void animateTake();
  void animateDrop();
  void animateLose(){}
  void animateWin(){}
  void animateWithoutTime(){}

  //CC_SYNTHESIZE(cocos2d::Array*, _hold_bag, HoldBag);
 private:
  GroupSphere _hold_bag;

  PointGrid _pos;
};

#endif
