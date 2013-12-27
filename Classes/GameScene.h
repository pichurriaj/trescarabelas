#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "cocos2d.h"
/**
 *Escenario donde se desarrolla el juego
 *Puede tener uno o mas metas, por ejemplo:
 *  * eliminar todas los cristales de un tipo
 *  * alcanzar un Y puntaje.
 */
class Game : public cocos2d::Scene
{
 public:
  static cocos2d::Scene* scene();
  virtual bool init();
  CREATE_FUNC(Game);

 private:
  
};

#endif
