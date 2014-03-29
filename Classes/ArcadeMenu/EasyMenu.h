#ifndef EASYMENU_H
#define EASYMENU_H

#include "../IArcadeMenuLevel.h"
#include "../Grid.h"
#include "cocos2d.h"

class EasyMenu :  public cocos2d::Object, public ArcadeMenuLevel
{
 public:
  EasyMenu();
  static EasyMenu* create();

  virtual cocos2d::Node* getView();
  virtual void touch(cocos2d::Point);
  void choiceLevel(cocos2d::Object*);
 private:

  cocos2d::MenuItemImage* createMenuItem(const char* normalimg, const char* selectedimg, int lvl, bool locked);
  cocos2d::Node* view;
  cocos2d::Sprite *background;
  Grid<cocos2d::Sprite*> _grid;
  cocos2d::Menu* menu;
};

#endif
