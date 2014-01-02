#ifndef GAMETESTSCENE_H
#define GAMETESTSCENE_H

#include "cocos2d.h"
#include "Board.h"

class GameTestArcade : public cocos2d::LayerColor
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(GameTestArcade);

 private:
  int _score;
  int _time;
  //Indian* player;
  Board* board;
};


#endif
