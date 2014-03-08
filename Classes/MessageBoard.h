#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include "Board.h"
#include "Sphere.h"
#include "cocos2d.h"
#include "ArcadeScene.h"
class MessageBoard
{
 public:
  MessageBoard(Board* b, Arcade *l){
    setBoard(b);
    setArcade(l);
  }
  virtual ~MessageBoard(){
  }
  CC_SYNTHESIZE(Board*,_board,Board);
  CC_SYNTHESIZE(Arcade*, _arcade, Arcade);
};


#endif
