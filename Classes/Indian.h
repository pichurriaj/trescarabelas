#ifndef INDIAN_H
#define INDIAN_H

#include "cocos2d.h"
#include "PointGrid.h"
#include "Sphere.h"

/**
 *Representa el jugador
 *aunque este es atraves de comandos
 */
class Indian : public cocos2d::Node
{
 public:
  Indian();
  virtual bool init();
  CREATE_FUNC(Indian);
  
  void update(float dt);
  void jumpTo(PointGrid);
  /**
   *Solo guarda si son del mismo tipo
   */
  bool grabSphere(Sphere* sphere);
  GroupSphere* getBag();

  /*Animaciones*/
  void animateStand();
  void animateTake();
  void animateDrop();
  void animateLose(){}
  void animateWin(){}
  void animateWithoutTime(){}

 private:
  GroupSphere* _hold_bag;
  PointGrid _pos;
};

#endif
