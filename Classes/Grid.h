#ifndef GRID_H
#define GRID_H

#include "PointGrid.h"
#include <vector>

class Grid
{
 public:
  Grid(int w, int h);
  /**
   *Saca un elemento de la grilla
   */
  void* drop(PointGrid);

  /**
   *Pone un elemento el la grilla
   *en caso de existir algo lo retorna
   */
  void* take(PointGrid, void*);

  /**
   *Mueve un elemento de la grilla
   *y retorna el destino en caso de existir antes de poner
   */
  void* move(PointGrid, PointGrid);
 private:
  int _w;
  int _h;
  std::vector< std::vector<void*> > _grid;
};
#endif
