#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "../PointGrid.h"
#include "../Grid.h"
#include "../Board.h"
#include "../BoardPopulater.h"
#include <cppunit/extensions/HelperMacros.h>

class BoardTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BoardTest);
  CPPUNIT_TEST(testRoll);
  CPPUNIT_TEST(testMatch);
  CPPUNIT_TEST_SUITE_END();
  
 private:
  Board* board;
  BoardPopulater* board_populater;
 public:

  void setUp() {
    board = new Board();

  }

  void tearDown() {
    delete board;
  }
  
  void testDrop() {
    
  }

  void testRoll() {
  }

  void testMatch() {
    board->attachMatch([](GroupSphere spheres){
      });

    board->attachEndBoard([](GroupSphere spheres){

      });

    
  }
};

#endif
