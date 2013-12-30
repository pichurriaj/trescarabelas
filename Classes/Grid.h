#ifndef GRID_H
#define GRID_H

#include "PointGrid.h"
#include <vector>

template <class T>
class Grid
{
 public:
  Grid(int w, int h);

  /**
   *Saca un elemento de la grilla
   */
  T* drop(PointGrid);

  /**
   *Pone un elemento el la grilla
   *en caso de existir algo lo retorna
   */
  T* take(PointGrid, T*);

  /**
   *Mueve un elemento de la grilla
   *y retorna el destino en caso de existir antes de poner
   */
  T* move(PointGrid, PointGrid);

  /**
   *Pone un elemento en una de la columna indicad.
   *@return bool s'i pudo ponerlo en cola
   */
  bool push(int, T*);

  /**
   *Toma el ultimo elemento de la columna indicada.
   */
  T* pop(int);
 private:
  int _w;
  int _h;
  std::map<PointGrid, T*> _grid;
};
#endif
