#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "../PointGrid.h"
#include "../Grid.h"
#include "../Board.h"
#include <cppunit/extensions/HelperMacros.h>

class BoardTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BoardTest);
  CPPUNIT_TEST(testMatch);
  CPPUNIT_TEST_SUITE_END();
  
 private:
  Board* board;

 public:

  void setUp() {
    board = new Board();
  }

  void tearDown() {
    delete board;
  }

  void testMatch() {
    board->attachMatch([](GroupSphere spheres){
      });

    board->attachEndBoard([](GroupSphere spheres){

      });

    
  }
};

#endif
