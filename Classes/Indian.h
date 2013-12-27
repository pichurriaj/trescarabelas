#ifndef INDIAN_H
#define INDIAN_H

#include "cocos2d.h"
#include "PointGrid.h"
/**
 *Representa el jugador
 *aunque este es atraves de comandos
 */
class Indian : public cocos2d::Sprite
{
 public:
  virtual bool init();
  CREATE_FUNC(Indian);
  
  void update(float dt);
  void jumpTo(PointGrid);

  /*Animaciones*/
  void animateStand();
  void animateStartJump();
  void animateJump();
  void animateStopJump();
  void animateTake();
  void animateDrop();
  void animateLose(){}
  void animateWin(){}
  void animateWithoutTime(){}
};

#endif
