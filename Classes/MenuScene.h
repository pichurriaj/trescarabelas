#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "cocos2d.h"

class MenuPrincipal : public cocos2d::Layer
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(MenuPrincipal);
  void quit();
  void toPlayMenu();
  void toCredits();
  void toTraining();
 private:
  /**
   *Agregar imagen de mar con movimiento
   *con desfase entre imagenes
   */
  void _add_sea(const char*, int);
  void _add_boat(const char*, int);
  void _add_fish(const char*, int, int, float);
  void _add_title(const char*);
  void _add_quit(const char*);
  void _add_credits();
  void _add_buttons();

};

#endif
