#ifndef MESSAGEBOARDSPHERE_H
#define MESSAGEBOARDSPHERE_H

#include "Board.h"
#include "Sphere.h"

class MessageBoardSphere
{
 public:
  MessageBoardSphere(Board* b, Sphere*s){
    setBoard(b);
    setSphere(s);
  }
  virtual ~MessageBoardSphere(){
  }
  CC_SYNTHESIZE(Board*,_board,Board);
  CC_SYNTHESIZE(Sphere*,_sphere,Sphere);
};

#endif
