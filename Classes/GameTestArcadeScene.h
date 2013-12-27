#ifndef GAMETESTSCENE_H
#define GAMETESTSCENE_H

#include "cocos2d.h"

class GameTestArcade : public cocos2d::Scene
{
 public:
  static cocos2d::Scene* scene();
  virtual bool init();
  CREATE_FUNC(GameTestArcade);

 private:
  int _score;
  int _time;
  Indian* player;
  Board* board;
};


#endif
