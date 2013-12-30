#ifndef _GRID_TEST_
#define _GRID_TEST_

#include "../PointGrid.h"
#include "../Grid.h"
#include <cppunit/extensions/HelperMacros.h>

/**
 *http://cppunit.sourceforge.net/doc/lastest/group___assertions.html
 */
class GridTest : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(GridTest);
  CPPUNIT_TEST(testTake);
  CPPUNIT_TEST(testDrop);
  CPPUNIT_TEST(testMove);
  CPPUNIT_TEST(testPop);
  CPPUNIT_TEST(testPush);
  CPPUNIT_TEST_SUITE_END();
 private:
  Grid<int> *grid_10x10;
 public:
  void setUp() {
    grid_10x10 = new Grid<int>(10,10);
  }

  void tearDown() {
    delete grid_10x10;
  }
  
  void testPop() {

    grid_10x10->push(1, 1);
    grid_10x10->push(1, 2);
    grid_10x10->push(1, 3);
    grid_10x10->push(1, 55);
    grid_10x10->push(1, 53);
    CPPUNIT_ASSERT(grid_10x10->pop(1) == 53);
    CPPUNIT_ASSERT(grid_10x10->pop(1) == 55);
    CPPUNIT_ASSERT(grid_10x10->pop(1) == 3);
    CPPUNIT_ASSERT(grid_10x10->pop(1) == 2);
    CPPUNIT_ASSERT(grid_10x10->pop(1) == 1);
    CPPUNIT_ASSERT(grid_10x10->pop(1) == 0);

    grid_10x10->push(10, 1);
    grid_10x10->push(10, 11);
    grid_10x10->push(10, 111);
    CPPUNIT_ASSERT(grid_10x10->pop(10) == 111);
    CPPUNIT_ASSERT(grid_10x10->pop(10) == 11);
    CPPUNIT_ASSERT(grid_10x10->pop(10) == 1);
  }

  void testPush() {
    grid_10x10->take(PointGrid(1,0), 2);
    grid_10x10->push(1, 4);
    CPPUNIT_ASSERT(grid_10x10->drop(PointGrid(1,1)) == 4);
    grid_10x10->push(1, 4);
    grid_10x10->push(1, 55);
    CPPUNIT_ASSERT(grid_10x10->drop(PointGrid(1,2)) == 55);
    grid_10x10->push(5, 31);
    CPPUNIT_ASSERT(grid_10x10->drop(PointGrid(5, 0)) == 31);
  }

  void testMove() {
    CPPUNIT_ASSERT_THROW(grid_10x10->move(PointGrid(1,11), PointGrid(1,1)), std::range_error);
    grid_10x10->take(PointGrid(9,9), 11);
    grid_10x10->take(PointGrid(0,0), 5);
    CPPUNIT_ASSERT(grid_10x10->move(PointGrid(9,9), PointGrid(0,0)) == 5);
    CPPUNIT_ASSERT(grid_10x10->drop(PointGrid(0,0)) != 5);
  }

  void testDrop() {
    grid_10x10->take(PointGrid(1,10), 19);
    CPPUNIT_ASSERT(grid_10x10->drop(PointGrid(1,10)) == 19);
    CPPUNIT_ASSERT_THROW(grid_10x10->drop(PointGrid(1,11)), std::range_error);
  }

  void testTake() {
    CPPUNIT_ASSERT(grid_10x10->take(PointGrid(0,0), 1) != 1);
    CPPUNIT_ASSERT(grid_10x10->take(PointGrid(0,0), 2) == 1);
    CPPUNIT_ASSERT(grid_10x10->take(PointGrid(0,0), 3) == 2);
    CPPUNIT_ASSERT_THROW(grid_10x10->take(PointGrid(0,11), 0), std::range_error);
  }
};

#endif //_GRID_TEST_
