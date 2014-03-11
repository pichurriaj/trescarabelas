#ifndef ARCADESCENE_H
#define ARCADESCENE_H

#include "cocos2d.h"

#include "Indian.h"
#include "Board.h"
#include "BoardPopulater.h"


class Arcade : public cocos2d::Layer
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(Arcade);
  
  void updateBoard(float);
  virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
  virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
  virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);

  void onMatchSpheres(GroupSphere&,unsigned int);
  void onFallSphere(Sphere*, PointGrid);
  void onFallSpheres(GroupSphere spheres, std::vector<PointGrid> spheres_old_pos, std::vector<PointGrid> spheres_new_pos);
  void onAnimateExploitSphere(Sphere*);
  void onReachEndBoard(GroupSphere);
  void playSoundTake();
  void playSoundDrop();
  void playSoundCollide();

  //propiedades usadas especialmente para la dificultad
  CC_SYNTHESIZE(float, _delay_before_fall, DelayBeforeFall);
  CC_SYNTHESIZE(float, _delay_roll_board, DelayRollBoard);
 private:
  bool gestureDown;
  bool gestureUp;
  cocos2d::Point tap_begin;
  int _score;
  int _time;
  Indian* player;
  cocos2d::Size visibleSize;
  cocos2d::Point origin;
  Board* board;
  BoardPopulater* board_populater;
  cocos2d::Sprite* background;
  cocos2d::String _snd_take;
  cocos2d::String _snd_drop;
  cocos2d::String _snd_collide;
};

#endif
