#ifndef BOARD_H
#define BOARD_H

#include "cocos2d.h"
#include "PointGrid.h"
#include "Grid.h"
#include "Sphere.h"
#include <vector>

typedef GroupSphere std::vector<Sphere*>*;

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

  /**
   *Saca esferas del tablero,
   *eso es cuando el jugador toma la esfera
   *Siempre y cuando se pueda.
   */
  Sphere* dropSphere(PointGrid pos);

  /**
   *Pone esfera en el tablero
   */
  void takeSphere(PointGrid pos, Sphere*);

  /**
   *Llamada cuando mas de tres esferas han colisionado
   *en el patron esperado.
   */
  void attachMatch(std::function<void(std::vector<Sphere*>));

 private:
  void _populate_board();
  void _populate_next_row();
  void _roll();
  /**
   *Retorna grupo de esfera que compaginaron..
   *@param PointGrid indica el punto de partida de la busquedad
   *@return GroupSphere* grupo de esferas
   */
  GroupSphere _match(PointGrid start);

  Grid _grid;
  std::vector< std::function<void(GroupSphere)> > onAttachMatch;
};

#endif
