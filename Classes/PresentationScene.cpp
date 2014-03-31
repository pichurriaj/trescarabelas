/**
 *Presentacion.
 *
 *@todo hay veces que el cambio de escenera genera fallo de segmentacion en gnu/linux.
 */
#include "PresentationScene.h"
#include "MenuScene.h"
//#include "Config.h"
//#include "ProtocolAds.h"
//#include "PluginManager.h"

USING_NS_CC;
//using namespace cocos2d::plugin;

Scene* Presentation::createScene() {
  auto scene = Scene::create();
  auto layer = Presentation::create();
  scene->addChild(layer);
  return scene;
}

bool Presentation::init() {
  if(!LayerColor::initWithColor(ccc4(0,0,0,255))){
    return false;
  }
  toNextSceneP = false;
  Size visibleSize = Director::getInstance()->getVisibleSize();
  Point origin = Director::getInstance()->getVisibleOrigin();

  auto juego = Sprite::create("logo/estrella.png");
  juego->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
  this->addChild(juego);


  this->schedule(schedule_selector(Presentation::update), 2.0);
  //Ads
  //ADMOB_NEURON_LOAD

  return true;
}

void Presentation::update(float dt) {
  stopAllActions();
  unscheduleAllSelectors();
  removeFromParentAndCleanup(true);
  Scene* newScene = TransitionFade::create(0.8, MenuPrincipal::createScene()); 
  Director::sharedDirector()->replaceScene(newScene);
}
void Presentation::changeScene(Node* sender) {
  toNextSceneP = true;
}

void Presentation::onTransitionDidFinished() {
  CCLog("TRANSITION DID FINISHED");
}







