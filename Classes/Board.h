#ifndef BOARD_H
#define BOARD_H

#include "cocos2d.h"
#include "PointGrid.h"
#include "Grid.h"
#include "Sphere.h"
#include <vector>

/**
 *Estados del tablero, para animacion
 *y actualizacion de logica
 */
enum BOARD_STATE {
};

/**
 *Tablero donde se desarrolla el video juego,
 *ademas de proveer una interfaz para interactuar con este,
 *este lleva el movimiento de las esferas, sus colisiones.
 */
class Board
{
 public:
  Board();
  
  /**
   *La representacion en cocos2d.
   */
  cocos2d::Node* getView();

  /**
   *Actualiza logica del tablero
   */
  void update(float dt);

  /**
   *Saca esferas del tablero,
   *eso es cuando el jugador toma la esfera
   *Siempre y cuando se pueda.
   */
  GroupSphere dropSphere(PointGrid pos);

  /**
   *Pone esfera en el tablero
   */
  void takeSphere(PointGrid pos, GroupSphere*);

  /**
   *Llamada cuando mas de tres esferas han colisionado
   *en el patron esperado.
   *Usado para logica de juego.
   */
  void attachMatch(std::function<void(GroupSphere)> );

  /**
   *Llamada cuando se toca el fin del tablero
   *. usado para logica de juego
   */
  void attachTouchEnd(std::function<void(void)>);


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

  cocos2d::Node* _node;
  Grid<Sphere> _grid;
  std::vector< std::function<void(GroupSphere)> > onAttachMatch;
  std::vector< std::function<void(void)> > onAttachTouchEnd;
};

#endif
