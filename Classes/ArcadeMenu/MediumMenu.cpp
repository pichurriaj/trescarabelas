#include "MediumMenu.h"
#include "../ArcadeScene.h"
#include "../LevelManager.h"
USING_NS_CC;

#define TAG_LEVEL_LOCK 0x00000100 //10#256

/**
 *medium_menu_complete_%d: se almacena bool si completo ya el nivel.
 *medium_menu_score_%d: se almacena puntaje de nivel.
 *medium_menu_time_%d: se almacena tiempo que termino nivel.
 */


MediumMenu::MediumMenu(ArcadeMenu* scene): _grid(SCREEN_WIDTH/GRID_SIZE, SCREEN_HEIGHT/GRID_SIZE){
  _scene = scene;
  background = Sprite::create("menu arcade/menu_arcade_medio.png");
  view = Node::create();
  view->addChild(background);
  view->retain();

  cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();

  menu = Menu::create();
  view->addChild(menu);
  menu->setPosition(Point(-background->getContentSize().width/3,-background->getContentSize().height/3));
  bool finish_easy = false;
  LevelManager::getInstance()->setCurrentStage("easy_arcade");
  finish_easy = LevelManager::getInstance()->getLevelComplete(30);

  LevelManager::getInstance()->setCurrentStage("medium_arcade");
  LevelManager::getInstance()->setMaxLevel(30);
  
  if(finish_easy)
    LevelManager::getInstance()->setLevelLock(31,false);

  int lvl = 30;
  for(int row = 6; row > 0; row--){
    for(int col = 0; col < 5; col++){
      lvl++;
      //bool complete = LevelManager::getInstance()->getLevelComplete(lvl);
      bool locked = LevelManager::getInstance()->getLevelLock(lvl);
      //bool locked = false;
      auto lvlItem = this->createMenuItem("menu arcade/boton_mapa.png", "menu arcade/boton_mapa.png", lvl, locked);

      PointGrid pos(col, row);
      Point posxy = pos.toPoint() * 2;
      lvlItem->setPosition(posxy);
      menu->addChild(lvlItem);

    }
  }
}

MediumMenu* MediumMenu::create(ArcadeMenu* scene){
  MediumMenu* obj = new MediumMenu(scene);
  if(obj){
    obj->autorelease();
    obj->retain();
    return obj;
  }
  CC_SAFE_DELETE(obj);
  return NULL;
}

Node* MediumMenu::getView(){
  view->retain();
  return view;
}

void MediumMenu::choiceLevel(Object* obj){
  MenuItemImage* lvlItem = static_cast<MenuItemImage*>(obj);
  LevelManager::getInstance()->setCurrentStage("medium_arcade");
  LevelManager::getInstance()->setMaxLevel(30);
  if(!(lvlItem->getTag() & TAG_LEVEL_LOCK)) {
    playArcade(lvlItem->getTag());
  }
  std::cout << "Level:" << lvlItem->getTag() << std::endl;
}

void MediumMenu::touch(Point pos){
}


/**
 *Se crea un item para el menu, con candado si se da *locked*
 *se asigna *setTag* el numero del nivel que es el item
 *y en caso de estar bloqueado se pone 1 el 1 bit de lo 2 byte
 */
cocos2d::MenuItemImage* MediumMenu::createMenuItem(const char* normalimg, const char* selectedimg, int lvl,  bool locked){
  auto lvlItem = MenuItemImage::create(normalimg,
				       selectedimg,
				       CC_CALLBACK_1(MediumMenu::choiceLevel, this)
				       );
  lvlItem->setTag(lvl);
  LabelTTF* num = LabelTTF::create(String::createWithFormat("%d",lvl)->getCString(),
				   "Serif",
				   50);
  lvlItem->addChild(num);
  num->setPosition(Point(
			 lvlItem->getContentSize().width/2,
			 lvlItem->getContentSize().height/2
			 )
		   );

  if(locked){
    Sprite* lock = Sprite::create("menu arcade/bloqueo.png");
    lvlItem->addChild(lock);
    lock->setPosition(Point(
			    lvlItem->getContentSize().width/2,
			    lvlItem->getContentSize().height/2
			    )
		      );
    lvlItem->setTag(lvlItem->getTag() | TAG_LEVEL_LOCK);
  }
  lvlItem->retain();
  return lvlItem;
}


/**
 *son 30 niveles
 *la dificultad se basa en:
 * - velocidad de roll del escenario
 * - tiempo para cumplir escenario
 * - randomizacion de esferas
 */
void MediumMenu::playArcade(int lvl){
  const int max_lvl = 30;
  const float default_roll_board = 6.0f;
  const int default_time_start = 90;
  auto  arcade = Arcade::create();
  LevelManager::getInstance()->setCurrentStage("medium_arcade");
  LevelManager::getInstance()->setMaxLevel(30);
  LevelManager::getInstance()->setCurrentLevel(lvl);
  struct{
    int delay_roll_board;
    int randomize_ball;
    int score_low_win;
    int score_win;
    int score_high_win;
    int extra_rows;
  } goals[] = {
    {4,51,1300,1400,1500,2}, //lvl 1
    {4,51,1400,1500,1600,3}, //lvl 2
    {4,51,1500,1600,1700,3}, //lvl 3
    {4,51,1600,1700,1800,3}, //lvl 4
    {4,51,1700,1800,1900,4}, //lvl 5
    {4,51,1800,1900,2000,4}, //lvl 6
    {4,51,2100,2200,2300,4}, //lvl 7
    {4,51,2000,2100,2400,4}, //lvl 8
    {4,51,2100,2200,2500,4}, //lvl 9
    {4,51,2200,2300,2800,3}, //lvl 10
    {4,53,2500,2600,2700,3}, //lvl 11
    {4,53,2700,2800,2900,3}, //lvl 12
    {4,53,2800,2900,3000,3}, //lvl 13
    {4,53,2900,3100,3200,4}, //lvl 14
    {4,53,3000,3100,3200,4}, //lvl 15
    {4,53,3100,3200,3300,4}, //lvl 16
    {4,53,3200,3300,3400,4}, //lvl 17
    {4,53,3333,3433,3500,4}, //lvl 18
    {4,53,3400,3500,3600,4}, //lvl 19
    {4,53,3500,3600,3700,4}, //lvl 20
    {4,58,4700,4800,4900,5}, //lvl 21
    {4,58,4800,4900,5000,5}, //lvl 22
    {4,58,4900,5000,5500,5}, //lvl 23
    {4,58,5000,5100,5700,5}, //lvl 24
    {3,98,5100,5300,5800,1}, //lvl 25
    {3,98,5700,6300,6400,2}, //lvl 26
    {3,98,6300,6400,6600,2}, //lvl 27
    {3,98,6400,6600,6700,2}, //lvl 28
    {3,98,6500,6600,6800,2}, //lvl 29
    {3,99,6600,6700,7800,2} //lvl 30
  };
  lvl -= 30;
  for(int c=goals[lvl].extra_rows; c > 0; c--)
    arcade->populateRow();
  arcade->setDelayRollBoard(goals[lvl].delay_roll_board);
  arcade->setRandomizeBall(goals[lvl].randomize_ball);
  arcade->setScoreWin(goals[lvl].score_win );
  arcade->setScoreLowWin(goals[lvl].score_low_win);
  arcade->setScoreHighWin(goals[lvl].score_high_win);
  arcade->setDelayStopCombo(1.7f);

  if(getBackground())
    arcade->changeBackground(getBackground());
  _scene->stopAllActions();
  _scene->unscheduleAllSelectors();
  _scene->removeFromParentAndCleanup(true);
  Scene* scene = Scene::create();scene->addChild(arcade);
  Scene* newScene = TransitionFade::create(0.7, scene);
  Director::sharedDirector()->replaceScene(newScene);
}


bool MediumMenu::complete(){
  int lvl = 0;
  LevelManager::getInstance()->setCurrentStage("medium_arcade");
  LevelManager::getInstance()->setMaxLevel(30);
  for(int row = 6; row > 0; row--){
    for(int col = 0; col < 5; col++){
      lvl++;
      if(!LevelManager::getInstance()->getLevelComplete(lvl)){
	return false;
      }
    }
  }
  return true;
}

const char* MediumMenu::getBackground(){
  return "mapas/mapa2.png";
}
