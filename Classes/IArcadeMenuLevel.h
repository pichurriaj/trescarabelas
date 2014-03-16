#ifndef IARCADEMENULEVEL_H
#define IARCADEMENULEVEL_H

#include "cocos2d.h"

/**
 *Representa un menu para arcade
 *donde se representa diferentes fondo
 *dificultades.
 */
class ArcadeMenuLevel
{
 public:
  virtual cocos2d::Node* getView() = 0;
  virtual void touch(cocos2d::Point) = 0;
};

#endif
