#ifndef BONES_H
#define BONES_H

#include "cocos2d.h"

class BoneTraining : public cocos2d::Node
{
 public:
  virtual bool init(){
    if(!cocos2d::Node::init()){
      return false;
    }
    bg = Sprite::create("botones");
    bg->setPosition(this->getPosition());
    this->addChild(bg);

    return true;
  }
  CREATE_FUNC(BoneTraining);

 private:
  cocos2d::Sprite* bg;
};

#endif
