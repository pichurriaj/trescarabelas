#ifndef BOARDPOPULATERTESTER_H
#define BOARDPOPULATERTESTER_H

#include "BoardPopulater.h"

#include "BoardPopulater.h"
#include "Board.h"

class BoardPopulaterTester : public BoardPopulater {
 public:
  BoardPopulaterTester(Board*);
  virtual void populate();
  virtual void populate_next_row();
  virtual void populate_first_row();
  void populate(SphereType, int);
  void populate_next_row(SphereType);
  void populate_first_row(SphereType);

 private:
  Board* _board;
};


#endif
