#include "MenuScene.h"
#include "Effects.h"
#include "SimpleAudioEngine.h"
#include "ArcadeScene.h"

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
  this->setKeypadEnabled(true);

  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  //imagen fondo
  Sprite* fondo = Sprite::create("menu/fondo.png");
  fondo->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  fondo->setScaleX(visibleSize.width/fondo->getContentSize().width);
  this->addChild(fondo);
  
  //audio
  CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
  if(!CocosDenshion::SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
    CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic("menu/musica.ogg", true);

  //barco
  _add_boat("menu/barco.png", 10);

  //mar
  _add_sea("menu/mar1.png", -30);
  _add_sea("menu/mar2.png", 20);
  _add_sea("menu/mar3.png", -20);
  _add_fish("menu/pez2.png", 522, 300, 3);
  _add_fish("menu/pez2.png", 122, 200, 2.5);
  _add_fish("menu/pez2.png", 622, 100, 2);

  _add_sea("menu/capamar.png",0);

  //titulo
  _add_title("menu/titulo.png");

  //salir
  _add_quit("botones/salir.png");
  _add_credits();
  _add_buttons();
  return true;
}

void MenuPrincipal::_add_buttons(){
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();


  auto play_normal = Sprite::create("botones/play.png");
  auto play_selected = Sprite::create("botones/play_presionado.png");
  play_selected->runAction(Effects::ActionButtonSelected());
  auto play = MenuItemSprite::create(play_normal, play_selected, CC_CALLBACK_0(MenuPrincipal::toPlayMenu, this));
  /*
  auto training_normal = Sprite::create("botones/training.png");
  auto training_selected = Sprite::create("botones/training.png");
  training_selected->runAction(Effects::ActionButtonSelected());
  auto training = MenuItemSprite::create(training_normal, training_selected, CC_CALLBACK_0(MenuPrincipal::toTraining, this));
  */
  _menu = Menu::create(play,  NULL);
  _menu->alignItemsVerticallyWithPadding(10);
  this->addChild(_menu);
  _menu->setPosition(Point(_menu->getContentSize().width/2 + 10,
			  visibleSize.height/2 + origin.y
			  )
		    );
}

void MenuPrincipal::_add_credits() {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  auto item = MenuItemImage::create(
				    "botones/credito.png",
				    "botones/credito_presionado.png",
				    CC_CALLBACK_0(MenuPrincipal::toCredits, this)
				    );
  item->setPosition(Point(origin.x + item->getContentSize().width + 15,
			 visibleSize.height + origin.y - item->getContentSize().height - 15));

  auto menu = Menu::create(item, NULL);
  menu->setPosition(Point::ZERO);
  this->addChild(menu, 99);

}

void MenuPrincipal::quit() {
  stopAllActions();
  unscheduleAllSelectors();
  removeFromParentAndCleanup(true);
  Director::getInstance()->end();
}

void MenuPrincipal::_add_quit(const char* path) {
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  auto item = MenuItemImage::create(
				    path,
				    path,
				    CC_CALLBACK_0(MenuPrincipal::quit, this)
				    );
  item->setPosition(Point(visibleSize.width + origin.x - item->getContentSize().width - 15,
			 visibleSize.height + origin.y - item->getContentSize().height - 15));

  auto menu = Menu::create(item, NULL);
  menu->setPosition(Point::ZERO);
  this->addChild(menu, 99);

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

void MenuPrincipal::_add_fish(const char* path, int x, int y, float vel){
  Sprite* fish = Sprite::create(path);
  this->addChild(fish);
  fish->setPosition(Point(x, y));
  fish->runAction(Effects::ActionFishMovement(y, vel));
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
  sea->runAction(RepeatForever::create(Spawn::create(zigzag, NULL)));
  this->addChild(sea);
}


void MenuPrincipal::toPlayMenu(){
  stopAllActions();
  unscheduleAllSelectors();
  removeFromParentAndCleanup(true);
  Scene* newScene = TransitionFade::create(0.7, Arcade::createScene()); 
  Director::sharedDirector()->replaceScene(newScene);
}

void MenuPrincipal::toCredits(){
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  Layer* credits = Layer::create();
  if(Layer::init()) {
    _menu->runAction(Hide::create());
    Sprite* bg = Sprite::create("creditos/creditos.png");
    bg->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    bg->runAction(Sequence::create(FadeIn::create(1.0f), DelayTime::create(3.0f), FadeOut::create(1.0f), RemoveSelf::create(),NULL));
    credits->addChild(bg, 99);
    _menu->runAction(Sequence::create(DelayTime::create(5.0f), Show::create(), FadeIn::create(1.0f), NULL));
    credits->runAction(Sequence::create(DelayTime::create(5.0f), RemoveSelf::create(), NULL));
    this->addChild(credits, 99);
  }

}

void MenuPrincipal::toTraining(){
}


void MenuPrincipal::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
  if(keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE){
    std::cout << __FUNCTION__ << std::endl;
    stopAllActions();
    unscheduleAllSelectors();
    removeFromParentAndCleanup(true);
    Director::getInstance()->end();
  }
}
