#ifndef ARCADEMENUSCENE_H
#define ARCADEMENUSCENE_H

#include "cocos2d.h"
#include "IArcadeMenuLevel.h"
#include <vector>

class ArcadeMenu : public cocos2d::Layer
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();

  CREATE_FUNC(ArcadeMenu);
  virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event*);
  virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
  virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
  /**
   *Selecciona un nivel y muestra
   *siempre y cuando se pueda
   */
  void selectLevel(unsigned int);

  /**
   *Agrega nivel para ser desplazdo
   */
  void addLevel(ArcadeMenuLevel*);
 private:
  std::vector<ArcadeMenuLevel*> levels;
  int level_selected; 
  ArcadeMenuLevel* level;
  cocos2d::Node* view_level;

  cocos2d::Size visibleSize;
  cocos2d::Point origin;
};

#endif
