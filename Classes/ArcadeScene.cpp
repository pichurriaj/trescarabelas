#include "ArcadeScene.h"
#include "BoardPopulaterRandom.h"
USING_NS_CC;

#define TOUCH_TO_COL(T) (int)(T.x / GRID_SIZE)

Scene* Arcade::createScene(){
  auto scene = Scene::create();
  auto layer = Arcade::create();
  scene->addChild(layer);
  return scene;
}


bool Arcade::init(){
  if(!Layer::init()){
    return false;
  }
  //inicial
  tap_begin = Point::ZERO;
  visibleSize = Director::getInstance()->getVisibleSize();
  origin = Director::getInstance()->getVisibleOrigin();

  Sprite* bg = Sprite::create("mapas/mapa_arcade.png");
  bg->setPosition(Point(
			visibleSize.width/2 + origin.x,
			visibleSize.height/2 + origin.y
			)
		  );
  this->addChild(bg);

  player = Indian::create();
  board = Board::create();
  Node* board_view = board->getView();
  this->addChild(board_view);
  board_view->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

  board_populater = new BoardPopulaterRandom(board);
  board_populater->populate();
  board->setPopulater(board_populater);

  auto dispatcher = Director::getInstance()->getEventDispatcher();
  auto listener = EventListenerTouchOneByOne::create();
  listener->onTouchBegan = CC_CALLBACK_2(Arcade::onTouchBegan, this);
  listener->onTouchMoved = CC_CALLBACK_2(Arcade::onTouchMoved, this);
  listener->onTouchEnded = CC_CALLBACK_2(Arcade::onTouchEnded, this);
  
  dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
  this->schedule(schedule_selector(Arcade::updateBoard), 5.0f);


  return true;
}

void Arcade::updateBoard(float dt){
  board_populater->populate_first_row();
}

bool Arcade::onTouchBegan(Touch* touch, Event* event){
  tap_begin = touch->getLocation();
  gestureUp = false; gestureDown = false;
  return true;
}

void Arcade::onTouchMoved(Touch* touch, Event* event){
}

void Arcade::onTouchEnded(Touch* touch, Event* event){
  Point tap_end = touch->getLocation();
  if(tap_end.y < tap_begin.y)
    gestureDown = true;
  if(tap_end.y > tap_begin.y)
    gestureUp = true;

  CCLOG("Gesture Down: %d", gestureDown ? 1 : 0);
  CCLOG("Gesture Up: %d", gestureUp ? 1 : 0);
  CCLOG("Col Touched: %d", TOUCH_TO_COL(tap_begin));

  board->dropSphere(TOUCH_TO_COL(tap_begin));
  //fin
  gestureUp = false; gestureDown = false; tap_begin = Point::ZERO;
}

