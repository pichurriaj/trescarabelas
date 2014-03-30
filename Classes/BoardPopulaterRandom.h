#ifndef BOARDPOPULATERTESTER_H
#define BOARDPOPULATERTESTER_H

#include "BoardPopulater.h"
#include "Board.h"
class BoardPopulaterRandom : public BoardPopulater {
 public:
  BoardPopulaterRandom(Board*);
  
  virtual void populate();
  virtual void populate_next_row();
  virtual void populate_first_row();

  CC_SYNTHESIZE(int, _randomize_ball, RandomizeBall);


  Sphere* randomSphere();
 private:
  SphereType randomType();


  Board* _board;
};

#endif
