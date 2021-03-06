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
  void updateMatch(PointGrid);
  /**
   *Logica de esferas callendo.
   *Se llama funcion indicando la esfera, y la nueva posicion que va ha tener.
   */
  void fallSpheres(std::function<void(Sphere*, PointGrid)>);

  /**
   *Saca esferas del tablero,
   *eso es cuando el jugador toma la esfera
   *Siempre y cuando se pueda.
   */
  GroupSphere dropSphere(PointGrid pos);
  GroupSphere dropSphere(int col);
  GroupSphere dropSphere(int col, SphereType);
  /**
   *Pone esfera en el tablero
   */
  void takeSphere(int col, GroupSphere&);
  void populateCol(int col, GroupSphere&);
  /**
   *Llamada cuando mas de tres esferas han colisionado
   *en el patron esperado.
   *Usado para logica de juego.
   */
  void attachMatch(std::function<void(GroupSphere&, unsigned int)> );

  /**
   *Llamada cuando se toca el fin del tablero
   *. usado para logica de juego
   */
  void attachEndBoard(std::function<void(GroupSphere)>);

  /**
   *Llamada cuando se hace un roll
   */
  void attachRoll(std::function<void(GroupSphere)>);

  /**
   *Llamada cuando se hace fall de las esferas
   *GroupSphere, old, new
   */
  void attachFall(std::function<void(GroupSphere&, std::vector<PointGrid>, std::vector<PointGrid>)>);

  /**
   *Llamada cuando se saca una esfera del tablero
   */
  void attachDropSphere(std::function<void(Sphere*)>);
  Grid<Sphere*>& getGrid() { return _grid; }
  CC_SYNTHESIZE(BoardPopulater*, _populater, Populater);

  /**
   *Baja las esferas
   */
  void roll(GroupSphere);
  cocos2d::Point offset(){
    return cocos2d::Point(_node->getPosition().x - _node->getContentSize().width/2, 0);
  }
 private:
  /**
   *intento de sincronizacion
   */
  bool  _match_locker;
  void _match_lock();
  void _match_unlock();

  /**
   *Retorna grupo de esfera que compaginaron..
   *@param PointGrid indica el punto de partida de la busquedad
   *@return GroupSphere* grupo de esferas
   */
  GroupSphere _match(PointGrid start);
  GroupSphere _match_right(PointGrid start);
  GroupSphere _match_left(PointGrid start);
  cocos2d::Node* _node;
  Grid<Sphere*> _grid;
  std::vector< std::function<void(GroupSphere)> > onAttachRoll;
  std::vector< std::function<void(GroupSphere&,unsigned int)> > onAttachMatch;
  std::vector< std::function<void(GroupSphere)> > onAttachEndBoard;
  std::vector< std::function<void(GroupSphere&, std::vector<PointGrid>, std::vector<PointGrid>)> > onAttachFall;
  std::vector< std::function<void(Sphere*)> > onDropSphere;
};

#endif
