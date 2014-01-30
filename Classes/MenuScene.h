#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "cocos2d.h"

class MenuPrincipal : public cocos2d::Layer
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(MenuPrincipal);

 private:
  /**
   *Agregar imagen de mar con movimiento
   *con desfase entre imagenes
   */
  void _add_sea(const char*, int);
  void _add_boat(const char*, int);
  void _add_title(const char*);
};

#endif
