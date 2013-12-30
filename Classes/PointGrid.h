#ifndef POINTGRID_H
#define POINTGRID_H

#include "cocos2d.h"

/**
 *Representa un punto de la grilla
 *esto es mas para aclaracion que otra cosa
 */
class PointGrid
{
 public:
 PointGrid(int _x, int _y) : x(_x), y(_y){
  }

  int x;
  int y;
};


#endif
