#ifndef EASYMENU_H
#define EASYMENU_H

#include "../ArcadeMenuScene.h"
#include "../IArcadeMenuLevel.h"

#include "../Grid.h"
#include "cocos2d.h"

class EasyMenu :  public cocos2d::Object, public ArcadeMenuLevel
{
 public:
  EasyMenu(ArcadeMenu* arcade);
  static EasyMenu* create(ArcadeMenu*);

  virtual cocos2d::Node* getView();
  virtual void touch(cocos2d::Point);
  virtual const char *getBackground();
  void choiceLevel(cocos2d::Object*);
  bool complete();
 private:
  //inicia nuevo escenario con el juego en el nivel indicado
  void playArcade(int lvl);

  cocos2d::MenuItemImage* createMenuItem(const char* normalimg, const char* selectedimg, int lvl, bool locked);
  cocos2d::Node* view;
  cocos2d::Sprite *background;
  Grid<cocos2d::Sprite*> _grid;
  cocos2d::Menu* menu;
  ArcadeMenu *_scene;
};

#endif
