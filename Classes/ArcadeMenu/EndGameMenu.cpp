#include "EndGameMenu.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

EndGameMenu::EndGameMenu(ArcadeMenu* _arcade) : _scene(_arcade){
  view = Node::create();
  view->retain();
  auto background = Sprite::create("escena_final/primera_escena.png");
  view->addChild(background);
}

EndGameMenu* EndGameMenu::create(ArcadeMenu* _arcade){
  EndGameMenu* obj = new EndGameMenu(_arcade);
  if(obj){
    obj->autorelease();
    obj->retain();
    return obj;
  }
  CC_SAFE_DELETE(obj);
  return NULL;
}

Node* EndGameMenu::getView(){
  CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(true);
  CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("musica y sonidos/pierde.ogg", true);
  view->retain();
  return view;
}

void EndGameMenu::choiceLevel(Object* obj){
}

bool EndGameMenu::complete(){
  return false;
}

void EndGameMenu::touch(Point touch){
}

const char* EndGameMenu::getBackground(){
  return NULL;
}
