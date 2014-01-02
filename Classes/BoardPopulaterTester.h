#ifndef BOARDPOPULATERTESTER_H
#define BOARDPOPULATERTESTER_H

#include "BoardPopulater.h"
#include "Board.h"
class BoardPopulaterTester : public BoardPopulater {
 public:
  BoardPopulaterTester(Board*);
  virtual void populate();
  virtual void populate_next_row();

 private:
  Board* _board;
};

#endif
