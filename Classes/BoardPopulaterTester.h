#ifndef BOARDPOPULATERTESTER_H
#define BOARDPOPULATERTESTER_H

#include "BoardPopulater.h"
#include "Board.h"
class BoardPopulaterTester : public BoardPopulater {
 public:
  BoardPopulaterTester(Board*);
  virtual void populate();
  virtual void populate_next_row();
  virtual void populate_first_row();

  Sphere* randomSphere();
 private:
  Board* _board;
};

#endif
