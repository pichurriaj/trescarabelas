#include "ArcadeMenuScene.h"
#include "ArcadeMenu/EasyMenu.h"
USING_NS_CC;

Scene* ArcadeMenu::createScene(){
  auto scene = Scene::create();
  auto layer = ArcadeMenu::create();
  scene->addChild(layer);
  return scene;
}

bool ArcadeMenu::init(){
  if(!Layer::init()) return false;
  level_selected = 0;  level = NULL;
  view_level = Node::create();
  visibleSize = Director::getInstance()->getVisibleSize();
  origin = Director::getInstance()->getVisibleOrigin();

  this->addChild(view_level);
  view_level->setPosition(Point(
				visibleSize.width/2 + origin.x,
				visibleSize.height/2 + origin.y
				));
  addLevel(EasyMenu::create());
  selectLevel(level_selected);

  return true;
}

bool ArcadeMenu::onTouchBegan(Touch* touch, Event* event){
}

void ArcadeMenu::onTouchEnded(Touch* touch, Event* event){
}

void ArcadeMenu::addLevel(ArcadeMenuLevel* _level){
  levels.push_back(_level);
}

void ArcadeMenu::selectLevel(unsigned int pos){
  if(pos > levels.size()) return;
  if(level)
    view_level->removeChild(level->getView());
  
  level = levels[pos];
  view_level->addChild(level->getView());
}
