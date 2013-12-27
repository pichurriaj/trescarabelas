#ifndef ARCADESCENE_H
#define ARCADESCENE_H

#include "cocos2d.h"

#include "Indian.h"
#include "Board.h"

class GameArcade : public cocos2d::Scene
{
 public:
  static cocos2d::Scene* scene();
  virtual bool init();
  CREATE_FUNC(Game);

 private:
  int _score;
  int _time;
  Indian* player;
  Board* board;
};

#endif
