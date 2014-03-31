#include "ArcadeMenuScene.h"
#include "ArcadeMenu/EasyMenu.h"
#include "ArcadeMenu/MediumMenu.h"
#include "ArcadeMenu/EndGameMenu.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

Scene* ArcadeMenu::createScene(){
  auto scene = Scene::create();
  auto layer = ArcadeMenu::create();
  scene->addChild(layer);
  return scene;
}

bool ArcadeMenu::init(){
  if(!Layer::init()) return false;
  CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
  CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("menu/musica.ogg", true);
  this->setKeypadEnabled(true);
  level_selected = UserDefault::getInstance()->getIntegerForKey("arcade_menu_last_level",0);  level = NULL;
  view_level = Node::create(); view_level->retain();
  visibleSize = Director::getInstance()->getVisibleSize();
  origin = Director::getInstance()->getVisibleOrigin();

  this->addChild(view_level);
  view_level->setPosition(Point(
				visibleSize.width/2 + origin.x,
				visibleSize.height/2 + origin.y
				));
  auto easy = EasyMenu::create(this);
  auto medium = MediumMenu::create(this);

  addLevel(easy);
  addLevel(medium);

  if(easy->complete()){
    level_selected += 1;
  }
  if(medium->complete()){
    level_selected += 1;
  }
  if(easy->complete() && medium->complete()){
    auto endgame = EndGameMenu::create(this);
    addLevel(endgame);
  }
  if(level_selected <= 0) level_selected  = 0;
  if(level_selected >= levels.size() - 1) level_selected = levels.size() - 1;

  selectLevel(level_selected);
  auto dispatcher = Director::getInstance()->getEventDispatcher();
  auto listener = EventListenerTouchOneByOne::create();
  listener->onTouchBegan = CC_CALLBACK_2(ArcadeMenu::onTouchBegan, this);
  listener->onTouchEnded = CC_CALLBACK_2(ArcadeMenu::onTouchEnded, this);

  dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
  return true;
}

bool ArcadeMenu::onTouchBegan(Touch* touch, Event* event){
  tap_begin = touch->getLocationInView();
  return true;
}

void ArcadeMenu::onTouchEnded(Touch* touch, Event* event){
  Point tap_end = touch->getLocationInView();
  CCLOG("tap_begin.x:%d, tap_end.x:%d",tap_begin.x, tap_end.x);
  bool new_level = false;
  if (tap_begin.x - tap_end.x < 100 && level_selected >= 0){
      level_selected -= 1;
      new_level = true;
    }else if(tap_begin.x - tap_end.x > 100){
      level_selected += 1;
      new_level = true;
    }


    if(level_selected <= 0) level_selected  = 0;
    if(level_selected >= levels.size() - 1) level_selected = levels.size() - 1;

  if(new_level)
    selectLevel(level_selected);
}

void ArcadeMenu::addLevel(ArcadeMenuLevel* _level){
  levels.push_back(_level);
}

void ArcadeMenu::selectLevel(unsigned int pos){
 
  if(pos <= 0) pos = 0;
  if(pos >= levels.size() - 1) pos = levels.size() - 1;
  CCLOG("===SELECTING LEVEL %d", pos);
  if(level == levels[pos]) return;
  if(level){
    view_level->removeChild(level->getView());
    level = NULL;
  }
  level = levels[pos];
  view_level->addChild(level->getView());
  UserDefault::getInstance()->setIntegerForKey("arcade_menu_last_level", pos);
  UserDefault::getInstance()->flush();
}

void ArcadeMenu::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
  if(keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE){
    std::cout << __FUNCTION__ << std::endl;
    stopAllActions();
    unscheduleAllSelectors();
    removeFromParentAndCleanup(true);
    Scene* newScene = TransitionFade::create(0.7, MenuPrincipal::createScene()); 
    Director::getInstance()->replaceScene(newScene);
  }
}
