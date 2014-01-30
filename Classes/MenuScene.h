#ifndef MENUSCENE_H
#define MENUSCENE_H

#include "cocos2d.h"

class Menu : public cocos2d::Layer
{
 public:
  static cocos2d::Scene* scene();
  virtual bool init();
  CREATE_FUNC(Menu);
};

#endif
