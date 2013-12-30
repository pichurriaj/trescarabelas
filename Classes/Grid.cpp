#include "Grid.h"
#include <cassert>

Grid::Grid(int w, int h): _w(w), _h(h) {
  _grid.resize(h);
  for(int y = 0; y < h; y++) {
    _grid[y].resize(w);
    for(int x = 0; x < w; x++) {
      _grid[y][x] = NULL;
    }
  }

}

void* Grid::drop(PointGrid pg) {
  assert(pg.y <= _h); assert(pg.y >= 0);
  assert(pg.x <= _w); assert(pg.x >= 0);
  if(_grid[pg.y][pg.x]) {
    void* rt = _grid[pg.y][pg.x];
    _grid[pg.y][pg.x] = NULL;
    return rt;
  }
  return NULL;
}

template <typename T>
T* Grid::take(PointGrid pg, T* data) {
  T* _rt = drop(pg);
  assert(pg.y <= _h); assert(pg.y >= 0);
  assert(pg.x <= _w); assert(pg.x >= 0);
  _grid[pg.y][pg.x] = data;
  return _rt;
}

template <typename T>
T* Grid::move(PointGrid pgs, PointGrid pgd) {
  T* _rt = drop(pgd);
  _grid[pgd.y][pgd.x] = _grid[pgs.y][pgs.x];
  _grid[pgs.y][pgs.x] = NULL;
  return _rt;
}

template <typename T>
bool Grid::push(int row, T* data) {
  for(int y = 0; y < _h; y++){
    if(!_grid[y][row]) {
      _grid[y][row] = data;
      return true;
    }
  }
  return false;
}

template <typename T>
T* Grid::pop(int row) {
  for(int y = _h; y >= 0; y--) {
    if(_grid[y][row])
      return _grid[y][row];
  }
  return NULL;
}
