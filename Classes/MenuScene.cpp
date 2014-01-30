#include "MenuScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;


Scene* MenuPrincipal::createScene() {
  auto scene = Scene::create();
  auto layer = MenuPrincipal::create();
  scene->addChild(layer);
  return scene;
}

bool MenuPrincipal::init() {
  if(!Layer::init()){
    return false;
  }
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  //imagen fondo
  Sprite* fondo = Sprite::create("menu/fondo.png");
  fondo->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  fondo->setScaleX(visibleSize.width/fondo->getContentSize().width);
  this->addChild(fondo);
  
  //audio
  if(!CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("menu/musica.ogg", true);

  //barco
  _add_boat("menu/barco.png", 10);

  //mar
  _add_sea("menu/mar1.png", -30);
  _add_sea("menu/mar2.png", 50);
  _add_sea("menu/mar3.png", -50);

  //titulo
  _add_title("menu/titulo.png");
  return true;
}

void MenuPrincipal::_add_title(const char* path) {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  Sprite* title = Sprite::create(path);
  title->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height + origin.y - title->getContentSize().height));
  auto swing = Sequence::create(
				EaseInOut::create(RotateTo::create(3.2f, 5), 2),
				EaseInOut::create(RotateTo::create(3.2f, -5), 2),
				NULL
				);
  title->runAction(RepeatForever::create(swing));
  this->addChild(title);
}

void MenuPrincipal::_add_boat(const char* path, int vel){
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  Sprite *boat = Sprite::create("menu/barco.png");
  float base_y = visibleSize.height/2 + origin.y;
  float base_x = visibleSize.width/2 + origin.x;
  boat->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  auto swing = Sequence::create(
				Spawn::create(EaseInOut::create(RotateTo::create(1.2f, 5), 2),
					      EaseInOut::create(MoveTo::create(1.2f, Point(base_x, base_y + 50)), 2),
					      NULL
					     ),
				Spawn::create(
					      EaseInOut::create(RotateTo::create(1.2f, -5), 2),
					      EaseInOut::create(MoveTo::create(1.2f, Point(base_x, base_y)), 2),

					      NULL),
				NULL
				);
  boat->runAction(RepeatForever::create(swing));
  this->addChild(boat);
}

void MenuPrincipal::_add_sea(const char* path, int offset_x){
  Sprite* sea = Sprite::create(path);
  int mar_base_y = sea->getContentSize().height/2;
  int mar_base_x = sea->getContentSize().width/2 + offset_x;
  sea->setPosition(Point(mar_base_x, mar_base_y));
  auto zigzag = Sequence::create(
				EaseSineInOut::create(MoveTo::create(3.5f, Point(mar_base_x - offset_x, mar_base_y))),
				  EaseSineInOut::create(MoveTo::create(3.5f, Point(mar_base_x + offset_x, mar_base_y))),
				  NULL
				 );
  auto swing = Sequence::create(
				Spawn::create(EaseInOut::create(RotateTo::create(1.2f, -1), 2),
					      EaseInOut::create(MoveTo::create(1.2f, Point(mar_base_x, mar_base_y + 5)), 2),
					      NULL
					     ),
				Spawn::create(
					      EaseInOut::create(RotateTo::create(1.2f, 1), 2),
					      EaseInOut::create(MoveTo::create(1.2f, Point(mar_base_x, mar_base_y)), 2),

					      NULL),
				NULL
				);
  sea->runAction(RepeatForever::create(Spawn::create(zigzag, swing, NULL)));
  this->addChild(sea);
}
