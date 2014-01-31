#ifndef BOARD_H
#define BOARD_H

#include "cocos2d.h"
#include "PointGrid.h"
#include "Grid.h"
#include "Sphere.h"
#include "BoardPopulater.h"
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
class Board : public cocos2d::Object
{
 public:
  Board();
  static Board* create();

  /**
   *La representacion en cocos2d.
   */
  cocos2d::Node* getView();
  void setView(cocos2d::Node* nd) { _node = nd; }
  /**
   *Actualiza logica del tablero
   */
  void update(float dt);
  void updateView();

  /**
   *Saca esferas del tablero,
   *eso es cuando el jugador toma la esfera
   *Siempre y cuando se pueda.
   */
  GroupSphere dropSphere(PointGrid pos);
  GroupSphere dropSphere(int col);
  /**
   *Pone esfera en el tablero
   */
  void takeSphere(int col, GroupSphere&);

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
  void attachEndBoard(std::function<void(GroupSphere)>);

  /**
   *Llamada cuando se hace un roll
   */
  void attachRoll(std::function<void(GroupSphere)>);

  const Grid<Sphere*>& getGrid() { return _grid; }
  CC_SYNTHESIZE(BoardPopulater*, _populater, Populater);

  /**
   *Baja las esferas
   */
  void roll(GroupSphere);
 private:


  /**
   *Retorna grupo de esfera que compaginaron..
   *@param PointGrid indica el punto de partida de la busquedad
   *@return GroupSphere* grupo de esferas
   */
  GroupSphere _match(PointGrid start);

  cocos2d::Node* _node;
  Grid<Sphere*> _grid;
  std::vector< std::function<void(GroupSphere)> > onAttachRoll;
  std::vector< std::function<void(GroupSphere)> > onAttachMatch;
  std::vector< std::function<void(GroupSphere)> > onAttachEndBoard;
};

#endif
