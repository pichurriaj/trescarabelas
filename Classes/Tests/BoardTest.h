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
  CPPUNIT_TEST(testUpdateMatch);
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
    Board* tboard = new Board();
    tboard->retain();
    BoardPopulaterTester* tboard_populater = new BoardPopulaterTester(tboard);
    auto grid = tboard->getGrid();
    grid.setCols(10);
    grid.setRows(20);
    //board_populater->populate(SPHERE_RED, 5);
    tboard_populater->populate_first_row(SPHERE_RED);
    tboard_populater->populate_first_row(SPHERE_RED);
    tboard_populater->populate_first_row(SPHERE_RED);
    tboard_populater->populate_first_row(SPHERE_RED);
    tboard_populater->populate_first_row(SPHERE_RED);
    GroupSphere spheres = tboard->dropSphere(0);
    std::cerr << __FUNCTION__ << "spheres drop: " << spheres.size() << std::endl;
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
    board->attachMatch([](GroupSphere spheres,int start_count_match){
      });

    board->attachEndBoard([](GroupSphere spheres){

      });

    
  }

  void testUpdateMatch(){
    /**
     * crea tablero
     * R | B
     * R | B
     * B | B
     * para probar colisiones
     */

   
    board->attachMatch([](GroupSphere& spheres,unsigned int start_count_match){
	CPPUNIT_ASSERT(spheres.size() == 6);
      });

    board_populater->populateCol(SPHERE_RED, 0, 2);
    board_populater->populateCol(SPHERE_BLUE, 0, 1);
    board_populater->populateCol(SPHERE_BLUE, 1, 3);
    
  }
};

#endif
