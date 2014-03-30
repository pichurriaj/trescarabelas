#include "BoardPopulaterRandom.h"
#include "Sphere.h"
#include <cstdlib>
#include <ctime>

SphereType BoardPopulaterRandom::randomType() {
  SphereType type = SPHERE_COUNT;
  while(type == SPHERE_COUNT || type == SPHERE_CHROMATIC){
    type = (SphereType)(rand() % SPHERE_COUNT);
  }
  return type;
}

BoardPopulaterRandom::BoardPopulaterRandom(Board* board) : _board(board) {
  _board->retain();
  setStartRows(4);
  setRandomizeBall(1);
}

void BoardPopulaterRandom::populate() {
  auto grid = _board->getGrid();
  
  srand(time(NULL));
  for(int col = 0; col < grid.getCols(); col++) {
    GroupSphere spheres;
      for (int rows = getStartRows(); rows > 0; rows--){
	Sphere *sphere = randomSphere();
	sphere->retain();
	spheres.push_back(sphere);
      }
      
    _board->populateCol(col, spheres);
  }

}

void BoardPopulaterRandom::populate_next_row() {
  SphereType first_sphere_type = randomType();
  auto grid = _board->getGrid();
  int *col_randomize = new int[getRandomizeBall()];
  for(int ix = 0; ix < getRandomizeBall(); ix++){
    col_randomize[ix] = rand() % grid.getCols();
  }
  for(int col = 0; col < grid.getCols(); col++) {
    GroupSphere spheres;
    int pos_randomize = rand() % grid.getCols();
    if(pos_randomize == col){
      spheres.push_back(Sphere::create(first_sphere_type));
    }else{
      spheres.push_back(randomSphere());
    }
    _board->populateCol(col, spheres);
  }
}


void BoardPopulaterRandom::populate_first_row() {
  auto grid = _board->getGrid();
  GroupSphere spheres;
  SphereType first_sphere_type = randomType();
  int count_random = getRandomizeBall();
  bool *pos_randomize = new bool[count_random];
  for(int ix = 0; ix < count_random; ix++){
    pos_randomize[ix] = false;
  }
  for(int repeats = count_random/grid.getCols(); repeats >= 0; repeats--){
    for(int ix = 0; ix < count_random; ix++){
      pos_randomize[rand()%count_random] = true;
    }
  }
  
  SphereType random_type = SPHERE_COUNT;
  for(int col = 0; col < grid.getCols(); col++) {
    for(int ix = 0; ix < count_random; ix++){
      if(pos_randomize[col])
	random_type = randomType();
      else
	random_type = first_sphere_type;
    }
    Sphere *sp = Sphere::create(random_type);
    sp->retain();
    spheres.push_back(sp);
  }
  std::cout << "Populating board first row with : " << spheres.size() << std::endl;
  _board->roll(spheres);
}

Sphere* BoardPopulaterRandom::randomSphere() {
  SphereType type = SPHERE_COUNT;
  while(type == SPHERE_COUNT || type == SPHERE_CHROMATIC){
    type = (SphereType)(rand() % SPHERE_COUNT);
  }
  Sphere* sp = Sphere::create(type);
  sp->retain();
  return sp;
}
