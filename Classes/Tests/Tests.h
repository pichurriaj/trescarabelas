#ifndef TESTS_H
#define TESTS_H

#include "GridTest.h"


class Tests {
 public:
  static CppUnit::Test *suite() {
    CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite("Trescarabelas core");
    suiteOfTests->addTest(GridTest::suite());
    return suiteOfTests;
  }
};

#endif
