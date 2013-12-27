#ifndef BOARD_H
#define BOARD_H

#include "cocos2d.h"
#include "PointGrid.h"
#include "Grid.h"
#include "Sphere.h"
#include <vector>
/**
 *Tablero donde se desarrolla el video juego,
 *ademas de proveer una interfaz para interactuar con este,
 *este lleva el movimiento de las esferas, sus colisiones.
 */
class Board : public cocos2d::Node
{
 public:
  virtual bool init();
  CREATE_FUNC(Board);

  /**
   *Actualiza logica del tablero
   */
  void update(float dt);

  Sphere* dropSphere(PointGrid pos);

  /**
   *Llamada cuando mas de tres esferas han colisionado
   *en el patron esperado.
   */
  void attachMatch(std::function<void(std::vector<Sphere*>));

 private:
  Grid _grid;
  std::vector< std::function<void(std::vector<Sphere*>)> > onAttachMatch;
};

#endif
