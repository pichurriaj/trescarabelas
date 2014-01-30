#ifndef BOARDTEST_H
#define BOARDTEST_H

#include "../PointGrid.h"
#include "../Grid.h"
#include "../Board.h"
#include "../BoardPopulater.h"
#include "../BoardPopulaterTester.h"
#include <cppunit/extensions/HelperMacros.h>

class BoardTest : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(BoardTest);
  CPPUNIT_TEST(testRoll);
  CPPUNIT_TEST(testMatch);
  CPPUNIT_TEST(testDrop);
  CPPUNIT_TEST(testPopulater);
  CPPUNIT_TEST_SUITE_END();
  
 private:
  Board* board;
  BoardPopulaterTester* board_populater;
 public:

  void setUp() {
    board = new Board();
    board->retain();
    board_populater = new BoardPopulaterTester(board);
  }

  void tearDown() {
    delete board;
  }
  
  void testPopulater() {
    board_populater->populate(SPHERE_RED, 5);
    GroupSphere spheres = board->dropSphere(PointGrid(0,0));
    CPPUNIT_ASSERT(spheres.size() == 5);
    for(auto &sphere: spheres) {
      CPPUNIT_ASSERT(sphere->getType() == SPHERE_RED);
    }
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
