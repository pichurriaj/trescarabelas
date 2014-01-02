#include "GameTestArcadeScene.h"
#include "Game.h"
#include "BoardPopulaterTester.h"
USING_NS_CC;

Scene* GameTestArcade::createScene() {
  auto scene = Scene::create();
  auto layer = GameTestArcade::create();
  scene->addChild(layer);
  return scene;
}


bool GameTestArcade::init() {
  if(!LayerColor::initWithColor(Color4B(255,255,255,255))){
    return false;
  }
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  board = Board::create();
  Node* board_view = board->getView();
  this->addChild(board_view);
  board_view->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

  BoardPopulaterTester* board_populater = new BoardPopulaterTester(board);
  board_populater->populate();
  board_populater->populate();
  board_populater->populate_next_row();

  return true;
}
