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
  background = Sprite::create("menu arcade/menu_arcade.png");
  view = Node::create();
  view->addChild(background);


  cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();

  menu = Menu::create();
  view->addChild(menu);
  menu->setPosition(Point(-background->getContentSize().width/3,-background->getContentSize().height/3));
  LevelManager::getInstance()->setCurrentStage("medium_arcade");
  LevelManager::getInstance()->setMaxLevel(30);
  LevelManager::getInstance()->setLevelLock(1,false);
  int lvl = 0;
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

  LevelManager::getInstance()->setCurrentLevel(lvl);
  struct{
    int delay_roll_board;
    int randomize_ball;
    int score_low_win;
    int score_win;
    int score_high_win;
    int extra_rows;
  } goals[] = {
    {5,1,300,400,500,0}, //lvl 1
    {5,1,400,500,600,0}, //lvl 2
    {5,1,500,600,700,0}, //lvl 3
    {5,1,600,700,800,0}, //lvl 4
    {5,1,700,800,900,0}, //lvl 5
    {5,1,800,900,1000,0}, //lvl 6
    {5,1,900,1000,1100,0}, //lvl 7
    {5,1,1000,1100,1200,0}, //lvl 8
    {5,1,1100,1200,1300,0}, //lvl 9
    {5,1,1200,1300,1400,0}, //lvl 10
    {4,3,500,600,700,0}, //lvl 11
    {4,3,700,800,900,0}, //lvl 12
    {4,3,800,900,1000,1}, //lvl 13
    {4,3,900,1000,1100,1}, //lvl 14
    {4,3,1000,1100,1200,1}, //lvl 15
    {4,3,1100,1200,1300,1}, //lvl 16
    {4,3,1200,1300,1400,1}, //lvl 17
    {4,3,1333,1433,1500,1}, //lvl 18
    {4,3,1400,1500,1600,1}, //lvl 19
    {4,3,1500,1600,1700,1}, //lvl 20
    {4,8,700,800,900,1}, //lvl 21
    {4,8,800,900,1000,1}, //lvl 22
    {4,8,900,1000,1100,1}, //lvl 23
    {4,8,1000,1100,1200,1}, //lvl 24
    {4,8,1100,1200,1300,1}, //lvl 25
    {4,8,1200,1300,1400,2}, //lvl 26
    {4,8,1300,1400,1500,2}, //lvl 27
    {4,8,1400,1500,1600,2}, //lvl 28
    {4,8,1500,1600,1700,2}, //lvl 29
    {4,9,1600,1700,1800,2} //lvl 30
  };
  for(int c=goals[lvl].extra_rows; c > 0; c--)
    arcade->populateRow();
  arcade->setDelayRollBoard(goals[lvl].delay_roll_board);
  arcade->setRandomizeBall(goals[lvl].randomize_ball);
  arcade->setScoreWin(goals[lvl].score_win );
  arcade->setScoreLowWin(goals[lvl].score_low_win);
  arcade->setScoreHighWin(goals[lvl].score_high_win);

  _scene->stopAllActions();
  _scene->unscheduleAllSelectors();
  _scene->removeFromParentAndCleanup(true);
  Scene* scene = Scene::create();scene->addChild(arcade);
  Scene* newScene = TransitionFade::create(0.7, scene);
  Director::sharedDirector()->replaceScene(newScene);
}


bool MediumMenu::complete(){
   int lvl = 0;
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
