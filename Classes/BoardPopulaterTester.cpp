#include "BoardPopulaterTester.h"
#include "Sphere.h"
#include <cstdlib>
#include <ctime>
BoardPopulaterTester::BoardPopulaterTester(Board* board) : _board(board) {
}

void BoardPopulaterTester::populate() {
  auto grid = _board->getGrid();

  srand(time(NULL));
  for(int col = 0; col < grid.getCols(); col++) {
    GroupSphere spheres;
    for(int rows = rand() % 5 + 1; rows > 0; rows--) {
      SphereType type = SPHERE_COUNT;
      while(type == SPHERE_COUNT || type == SPHERE_CHROMATIC){
	type = (SphereType)(rand() % SPHERE_COUNT);
      }
      spheres.push_back(Sphere::create(type));
    }
    _board->takeSphere(col, spheres);
  }

}

void BoardPopulaterTester::populate_next_row() {
  auto grid = _board->getGrid();
  for(int col = 0; col < grid.getCols(); col++) {
    GroupSphere spheres;
    for(int rows = 1; rows > 0; rows--) {
      SphereType type = SPHERE_COUNT;
      while(type == SPHERE_COUNT || type == SPHERE_CHROMATIC){
	type = (SphereType)(rand() % SPHERE_COUNT);
      }
      spheres.push_back(Sphere::create(type));
    }
    _board->takeSphere(col, spheres);
  }
}
