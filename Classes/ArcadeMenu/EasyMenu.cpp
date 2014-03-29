#include "EasyMenu.h"
USING_NS_CC;

#define TAG_LEVEL_LOCK 0x00000100 //10#256

EasyMenu::EasyMenu(): _grid(SCREEN_WIDTH/GRID_SIZE, SCREEN_HEIGHT/GRID_SIZE){
  background = Sprite::create("menu arcade/menu_arcade.png");
  view = Node::create();
  view->addChild(background);


  cocos2d::Size visibleSize = Director::getInstance()->getVisibleSize();
  cocos2d::Point origin = Director::getInstance()->getVisibleOrigin();

  menu = Menu::create();
  view->addChild(menu);
  menu->setPosition(Point(-background->getContentSize().width/3,-background->getContentSize().height/3));

  int lvl = 0;
  for(int row = 6; row > 0; row--){
    for(int col = 0; col < 5; col++){
      lvl++;
      auto lvlItem = this->createMenuItem("menu arcade/boton_mapa.png", "menu arcade/boton_mapa.png", lvl, true);

      PointGrid pos(col, row);
      Point posxy = pos.toPoint() * 2;
      lvlItem->setPosition(posxy);
      menu->addChild(lvlItem);
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

void EasyMenu::choiceLevel(Object* obj){
  MenuItemImage* lvlItem = static_cast<MenuItemImage*>(obj);
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

  return lvlItem;
}
