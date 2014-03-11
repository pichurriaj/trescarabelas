#include "BoardPopulaterTester.h"
#include "Sphere.h"

BoardPopulaterTester::BoardPopulaterTester(Board* board) : _board(board) {
  _board->retain();
  auto grid = _board->getGrid();
  grid.setCols(10);
  grid.setRows(20);
}

void BoardPopulaterTester::populate() {

}

void BoardPopulaterTester::populate(SphereType type, int srows){
  auto grid = _board->getGrid();

  srand(time(NULL));
  for(int col = 0; col < grid.getCols(); col++) {
    GroupSphere spheres; spheres.clear();
    //for(int rows = rand() % 5 + 1; rows > 0; rows--) {
    for(int rows = 0; rows < srows; rows++) {
      Sphere* sp = Sphere::create(type);
      sp->retain();
      spheres.push_back(sp);
    }
    _board->takeSphere(col, spheres);
  }
}

void BoardPopulaterTester::populateCol(SphereType type, int col, int size) {
  GroupSphere spheres; spheres.clear();

  for(int count = 0; count < size; count++){
    spheres.push_back(Sphere::create(type));
  }
  _board->takeSphere(col, spheres);
}

void BoardPopulaterTester::populate_next_row() {
}

void BoardPopulaterTester::populate_next_row(SphereType type) {
  auto grid = _board->getGrid();
  for(int col = 0; col < grid.getCols(); col++) {
    GroupSphere spheres;
    for(int rows = 1; rows > 0; rows--) {
      Sphere* sp = Sphere::create(type);
      sp->retain();
      spheres.push_back(sp);
    }
    _board->takeSphere(col, spheres);
  }
}

void BoardPopulaterTester::populate_first_row() {
}

void BoardPopulaterTester::populate_first_row(SphereType type) {
  auto grid = _board->getGrid();
  GroupSphere spheres;
  for(int col = 0; col < grid.getCols(); col++) {
    Sphere* sp = Sphere::create(type); sp->retain();
    spheres.push_back(sp);
  }
  std::cerr << __FUNCTION__ << ":" << "GRID SIZE:" << grid.getCols() << std::endl;
  std::cout << __FUNCTION__ << ":" << "Populating board first row with : " << spheres.size() << std::endl;
  _board->roll(spheres);
}
