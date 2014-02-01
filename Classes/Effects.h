#ifndef EFFECTS_H
#define EFFECTS_H

#include "cocos2d.h"
#include "PointGrid.h"
#include "Game.h"

class Effects
{
 public:
  static cocos2d::Animate* ActionDestroySphere(){
    //@todo pendiente plist para animaciones
    return NULL;
  }

  static cocos2d::ActionInterval* ActionSphereFall(cocos2d::Point pos){
    return cocos2d::EaseInOut::create(cocos2d::MoveTo::create(0.2f, pos),2);
  }

  static cocos2d::ActionInterval* ActionButtonSelected(){
    return cocos2d::RepeatForever::create(
					  cocos2d::Sequence::create(
								    cocos2d::EaseInOut::create(cocos2d::RotateBy::create(1.0f, 5),2),
								    cocos2d::EaseInOut::create(cocos2d::RotateBy::create(1.0f, -5),2),
						  NULL
						  )
				 );
  }

  static cocos2d::ActionInterval* ActionFishMovement(int y, float vel){
    cocos2d::Size visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Point origin = cocos2d::Director::getInstance()->getVisibleOrigin();
  
    return cocos2d::RepeatForever::create(
					  cocos2d::Sequence::create(
								    cocos2d::EaseInOut::create(cocos2d::MoveTo::create(vel, cocos2d::Point(visibleSize.width + 100, y)),2),
								    cocos2d::FlipX::create(true),
								    cocos2d::EaseInOut::create(cocos2d::MoveTo::create(vel, cocos2d::Point(- 300, y)), 2),
								    cocos2d::FlipX::create(false),
											       
								    NULL
								    )
					  );
  }
};

#endif


