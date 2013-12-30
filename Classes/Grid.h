#ifndef GRID_H
#define GRID_H

#include "PointGrid.h"
#include <vector>

template <class T>
class Grid
{
 public:
 Grid(int w, int h) : _w(w), _h(h) {
  }

  T* drop(PointGrid pg) {
    assert(pg.y <= _h); assert(pg.y >= 0);
    assert(pg.x <= _w); assert(pg.x >= 0);
    if(_grid[pg.y][pg.x]) {
      T* rt = _grid[pg.y][pg.x];
      _grid[pg.y][pg.x] = NULL;
      return rt;
    }
    return NULL;
  }

  T* take(PointGrid pg, T* data) {
    T* _rt = drop(pg);
    assert(pg.y <= _h); assert(pg.y >= 0);
    assert(pg.x <= _w); assert(pg.x >= 0);
    _grid[pg.y * _w + pg.x] = data;
    return _rt;
  }

  T* move(PointGrid pgs, PointGrid pgd) {
    T* _rt = drop(pgd);
    _grid[pgd.y * _w + pgd.x] = _grid[pgs.y * _w + pgs.x];
    _grid[pgs.y * _w + pgs.x] = NULL;
    return _rt;
  }

  bool push(int col, T* data) {
    for(int y = 0; y < _h; y++){
      if(!_grid[y * _w + col]) {
	_grid[y * _w + col] = data;
	return true;
      }
    }
    return false;
  }

  T* pop(int col) {
    for(int y = _h; y >= 0; y--) {
      if(_grid[y * _w + col])
	return _grid[y * _w + col];
    }
    return NULL;
  }

 private:
  int _w;
  int _h;
  std::map<PointGrid, T*> _grid;
};
#endif
