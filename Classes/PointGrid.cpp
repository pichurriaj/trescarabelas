#include "PointGrid.h"

const PointGrid PointGrid::ZERO = PointGrid(0,0);
const PointGrid PointGrid::BAD = PointGrid(-1, -1);
std::ostream& operator<<(std::ostream &strm, const PointGrid &a){
  return strm << "PointGrid(" << a.x << "," << a.y << ")";
}


