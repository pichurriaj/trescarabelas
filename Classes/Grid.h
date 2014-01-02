#ifndef GRID_H
#define GRID_H

#include "PointGrid.h"
#include <vector>

/**
 *Esta grilla, facilita
 *la gestion de las esferas
 *su ubicacion
 */
template <class T>
class Grid
{
 public:
 Grid(int w, int h) : _w(w), _h(h), _empty(0) {
  }

  /**
   *Saca un elemento de la grilla
   *@throw range_error
   */
  T drop(PointGrid pg) {
    
    if(pg.y > _h || pg.y < 0) {
      throw std::range_error("Over the height"); 
    }
    if(pg.x > _w || pg.x < 0) {
      throw std::range_error("Over the width");
    }
    if(_grid[pg.y * _w + pg.x]) {
      T rt = _grid[pg.y * _w + pg.x];
      _grid[pg.y * _w + pg.x] = _empty;
      return rt;
    }
    return _empty;
  }

  /**
   *La grilla toma un elemento y lo ubica
   *y retorna el elemento que estaba
   @throw range_error
   */
  T take(PointGrid pg, T data) {

    if(pg.y > _h || pg.y < 0) {
      throw std::range_error("Over the height"); 
    }
    if(pg.x > _w || pg.x < 0) {
      throw std::range_error("Over the width");
    }
    T _rt = drop(pg);
    _grid[pg.y * _w + pg.x] = data;
    return _rt;
  }

  T move(PointGrid pgs, PointGrid pgd) {
    T _rt = drop(pgd);
    T _st = drop(pgs);
    take(pgd, _st);
    return _rt;
  }

  /**
   *Pone un elemento al final de una columna
   *dada.
   */
  PointGrid push(int col, T data) {
    for(int y = 0; y < _h; y++){
      if(_grid[y * _w + col] == _empty) {
	take(PointGrid(col, y), data);
	return PointGrid(col, y);
      }
    }
    return PointGrid(-1, -1);
  }

  /**
   *Saca el ultimo elemento de la columna dada
   */
  T pop(int col) {
    for(int y = _h; y >= 0; y--) {
      if(_grid[y * _w + col] != _empty)
	return drop(PointGrid(col, y));
    }
    return _empty;
  }

  /**
   *Permite asignar indicador de vacio
   */
  void setEmpty(T v) {
    _empty = v;
  }

  int getCols() { return _w; }
  int getRows() { return _h; }
  void setCols(int w) { _w = w; }
  void setRows(int h) { _h = h; }
 private:
  int _w;
  int _h;
  /**
   *Indicador de vacio
   */
  T _empty; 
  /**
   *almacenamiento lineal
   *usar: y * _w + x
   */
  std::map<int, T> _grid;
};
#endif
