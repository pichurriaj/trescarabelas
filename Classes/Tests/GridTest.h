#ifndef _GRID_TEST_
#define _GRID_TEST_

#include "../Grid.h"
#include <cppunit/extensions/HelperMacros.h>

class GridTest : public CppUnit::TestFixture {

  CPPUNIT_TEST_SUITE(GridTest);
  CPPUNIT_TEST(testTake);
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
  
  void testTake() {
    CPPUNIT_ASSERT( 1 == 2);
  }
};

#endif //_GRID_TEST_
