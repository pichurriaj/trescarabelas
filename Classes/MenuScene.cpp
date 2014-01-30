#include "MenuScene.h"

USING_NS_CC;


Scene* Menu::scene() {
  auto scene = Scene::create();
  auto layer = Menu::create();
  scene->addChild(layer);
  return scene;
}

bool Menu::init() {
  if(!Layer::init()){
    return false;
  }

  return true;
}
