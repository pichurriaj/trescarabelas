#include "EasyMenu.h"
USING_NS_CC;

EasyMenu::EasyMenu(): _grid(SCREEN_WIDTH/GRID_SIZE, SCREEN_HEIGHT/GRID_SIZE){
  background = Sprite::create("menu arcade/menu_arcade.png");
  view = Node::create();
  view->addChild(background);


  cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();

  int lvl = 0;
  for(int row = 5; row > 0; row--){
    for(int col = 0; col < 5; col++){
      lvl++;
      Sprite* boton = Sprite::create("menu arcade/boton_mapa.png");
      PointGrid pos(col, row);
      view->addChild(boton);
      Point posxy = pos.toPoint() * 2;
      posxy.x -= visibleSize.width/4;
      posxy.y -= 100;
      boton->setPosition(posxy);
      LabelTTF* num = LabelTTF::create(String::createWithFormat("%d",lvl)->getCString(),
				       "Serif",
				       50);
      view->addChild(num);
      num->setPosition(boton->getPosition());
    }
  }
}

EasyMenu* EasyMenu::create(){
  EasyMenu* obj = new EasyMenu();
  if(obj){
    obj->autorelease();
    obj->retain();
    return obj;
  }
  CC_SAFE_DELETE(obj);
  return NULL;
}

Node* EasyMenu::getView(){
  view->retain();
  return view;
}

void EasyMenu::touch(Point pos){
}
