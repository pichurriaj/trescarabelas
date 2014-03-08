#ifndef POINTGRID_H
#define POINTGRID_H

#include "cocos2d.h"
#include "Game.h"
/**
 *Representa un punto de la grilla
 *esto es mas para aclaracion que otra cosa
 */
class PointGrid
{
 public:
 PointGrid(): x(0), y(0) {
  }
 PointGrid(const int _x,const int _y) : x(_x), y(_y){
  }
  
  cocos2d::Point toPoint() { return cocos2d::Point(x * GRID_SIZE, y * GRID_SIZE);  }
  bool operator==(const PointGrid &other) const{
    return x == other.x && y == other.y;
  }

  bool operator!=(const PointGrid &other) const{
    return !(x == other.x && y == other.y);
  }

  int x;
  int y;

  static const PointGrid ZERO;
  static const PointGrid BAD;
};


#endif
