#ifndef ENDGAMEMENU_H
#define ENDGAMEMENU_H

#include "../ArcadeMenuScene.h"
#include "../IArcadeMenuLevel.h"

#include "../Grid.h"
#include "cocos2d.h"


class EndGameMenu : public cocos2d::Object, public ArcadeMenuLevel
{
 public:
  EndGameMenu(ArcadeMenu*);
  static EndGameMenu* create(ArcadeMenu* );

  virtual cocos2d::Node* getView();
  virtual void touch(cocos2d::Point);
  void choiceLevel(cocos2d::Object*);
  virtual const char *getBackground();
  bool complete();

 private:
  cocos2d::Node* view;
  ArcadeMenu* _scene;
};

#endif
