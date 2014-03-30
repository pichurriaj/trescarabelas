#include "EasyMenu.h"
#include "../ArcadeScene.h"
#include "../LevelManager.h"
USING_NS_CC;

#define TAG_LEVEL_LOCK 0x00000100 //10#256

/**
 *easy_menu_complete_%d: se almacena bool si completo ya el nivel.
 *easy_menu_score_%d: se almacena puntaje de nivel.
 *easy_menu_time_%d: se almacena tiempo que termino nivel.
 */


EasyMenu::EasyMenu(ArcadeMenu* scene): _grid(SCREEN_WIDTH/GRID_SIZE, SCREEN_HEIGHT/GRID_SIZE){
  _scene = scene;
  background = Sprite::create("menu arcade/menu_arcade.png");
  view = Node::create();
  view->addChild(background);


  cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();

  menu = Menu::create();
  view->addChild(menu);
  menu->setPosition(Point(-background->getContentSize().width/3,-background->getContentSize().height/3));
  LevelManager::getInstance()->setCurrentStage("easy_arcade");
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

EasyMenu* EasyMenu::create(ArcadeMenu* scene){
  EasyMenu* obj = new EasyMenu(scene);
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

void EasyMenu::choiceLevel(Object* obj){
  MenuItemImage* lvlItem = static_cast<MenuItemImage*>(obj);
  if(!(lvlItem->getTag() & TAG_LEVEL_LOCK)) {
    playArcade(lvlItem->getTag());
  }
  std::cout << "Level:" << lvlItem->getTag() << std::endl;
}

void EasyMenu::touch(Point pos){
}


/**
 *Se crea un item para el menu, con candado si se da *locked*
 *se asigna *setTag* el numero del nivel que es el item
 *y en caso de estar bloqueado se pone 1 el 1 bit de lo 2 byte
 */
cocos2d::MenuItemImage* EasyMenu::createMenuItem(const char* normalimg, const char* selectedimg, int lvl,  bool locked){
  auto lvlItem = MenuItemImage::create(normalimg,
				       selectedimg,
				       CC_CALLBACK_1(EasyMenu::choiceLevel, this)
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
void EasyMenu::playArcade(int lvl){
  const int max_lvl = 30;
  const float default_roll_board = 6.0f;
  const int default_time_start = 90;
  auto  arcade = Arcade::create();

  LevelManager::getInstance()->setCurrentLevel(lvl);
  struct{
    int delay_roll_board;
    int randomize_ball;
    int score_win;
  } goals[] = {
    {5,1,300}, //lvl 1
    {5,1,400}, //lvl 2
    {5,1,500}, //lvl 3
    {5,1,600}, //lvl 4
    {5,1,700}, //lvl 5
    {5,1,800}, //lvl 6
    {5,1,900}, //lvl 7
    {5,1,1000}, //lvl 8
    {5,1,1100}, //lvl 9
    {5,1,1200}, //lvl 10
    {4,3,500}, //lvl 11
    {4,3,700}, //lvl 12
    {4,3,800}, //lvl 13
    {4,3,900}, //lvl 14
    {4,3,1000}, //lvl 15
    {4,3,1100}, //lvl 16
    {4,3,1200}, //lvl 17
    {4,3,1333}, //lvl 18
    {4,3,1400}, //lvl 19
    {4,3,1500}, //lvl 20
    {4,8,700}, //lvl 21
    {4,8,800}, //lvl 22
    {4,8,900}, //lvl 23
    {4,8,1000}, //lvl 24
    {4,8,1100}, //lvl 25
    {4,8,1200}, //lvl 26
    {4,8,1300}, //lvl 27
    {4,8,1400}, //lvl 28
    {4,8,1500}, //lvl 29
    {4,9,1600} //lvl 30
  };
  arcade->setDelayRollBoard(goals[lvl].delay_roll_board);
  arcade->setRandomizeBall(goals[lvl].randomize_ball);
  arcade->setScoreWin(goals[lvl].score_win );
  

  _scene->stopAllActions();
  _scene->unscheduleAllSelectors();
  _scene->removeFromParentAndCleanup(true);
  Scene* scene = Scene::create();scene->addChild(arcade);
  Scene* newScene = TransitionFade::create(0.7, scene);
  Director::sharedDirector()->replaceScene(newScene);
}


bool EasyMenu::complete(){
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
