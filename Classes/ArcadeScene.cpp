#include "ArcadeScene.h"
#include "BoardPopulaterRandom.h"
#include "Effects.h"
#include "MessageBoardSphere.h"
#include "MessageBoard.h"
#include "SimpleAudioEngine.h"

#define PLAY_EFFECT(X) CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(X);
#define PLAY_MUSIC(X) CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(X, true);
USING_NS_CC;

#define TOUCH_TO_COL(T) (int)(T.x / GRID_SIZE)
#define DELAY_BEFORE_FALL 0.07f
#define DELAY_ROLL_BOARD 4.0f

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

  //dificultad
  _delay_before_fall = DELAY_BEFORE_FALL;
  _delay_roll_board = DELAY_ROLL_BOARD;

  _snd_take = String("musica y sonidos/baja.ogg");
  _snd_drop = String("musica y sonidos/sube.ogg");
  _snd_collide = String("musica y sonidos/choca_perla.ogg");
  
  //initialize images
  Animation *_anim_exploit_sphere = Animation::create();
  for(int i = 1; i <= 4; i++){
    String *file = String::createWithFormat("efectos/eliminacion%d.png", i);
    String *name = String::createWithFormat("eliminacion%d.png", i);
    SpriteFrame *frame = SpriteFrame::create(file->getCString(), Rect(0, 0, 64, 64));
    SpriteFrameCache::sharedSpriteFrameCache()->addSpriteFrame(frame, name->getCString());
    _anim_exploit_sphere->addSpriteFrame(frame);
  }
  _anim_exploit_sphere->setDelayPerUnit(0.03);
  //_anim_exploit_sphere->setLoops(1);
  _anim_exploit_sphere->setRestoreOriginalFrame(false);
  AnimationCache::getInstance()->addAnimation(_anim_exploit_sphere, "exploit_sphere");
  /*auto cache = SpriteFrameCache::getInstance();
  auto pjf_espera1 = SpriteFrame::create("personajes/espera1.png",Rect(0,0,85,128));
  cache->addSpriteFrame(pjf_espera1, "indio_espera_1");
  auto pjf_espera2 = SpriteFrame::create("personajes/espera2.png",Rect(0,0,87,128));
  cache->addSpriteFrame(pjf_espera2, "indio_espera_2");
  auto pjf_espera3 = SpriteFrame::create("personajes/espera3.png",Rect(0,0,87,128));
  cache->addSpriteFrame(pjf_espera3, "indio_espera_3");
  */
  Sprite* bg = Sprite::create("mapas/mapa_arcade.png");
  bg->setPosition(Point(
			visibleSize.width/2 + origin.x,
			visibleSize.height/2 + origin.y
			)
		  );
  this->addChild(bg);


  board = Board::create();
  Node* board_view = board->getView();
  this->addChild(board_view);
  board_view->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  board->attachMatch(CC_CALLBACK_2(Arcade::onMatchSpheres, this));
  board->attachFall(CC_CALLBACK_3(Arcade::onFallSpheres, this));
  board->attachDropSphere(CC_CALLBACK_1(Arcade::onAnimateExploitSphere, this));
  board->attachEndBoard(CC_CALLBACK_1(Arcade::onReachEndBoard,this));
  board_populater = new BoardPopulaterRandom(board);
  board_populater->populate();
  board->setPopulater(board_populater);


  player = Indian::create();
  player->retain();
  Node* player_view = player->getView();
  this->addChild(player_view);
  player->jumpTo(3);




  auto dispatcher = Director::getInstance()->getEventDispatcher();
  auto listener = EventListenerTouchOneByOne::create();
  listener->onTouchBegan = CC_CALLBACK_2(Arcade::onTouchBegan, this);
  listener->onTouchMoved = CC_CALLBACK_2(Arcade::onTouchMoved, this);
  listener->onTouchEnded = CC_CALLBACK_2(Arcade::onTouchEnded, this);
  
  dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
  this->schedule(schedule_selector(Arcade::updateBoard), getDelayRollBoard());

  PLAY_MUSIC("musica y sonidos/juego.ogg");
  
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
  int touch_col = TOUCH_TO_COL(tap_begin);
  auto board_grid = board->getGrid();
  if(touch_col < 0 || touch_col >= board_grid.getCols())  return;

  if(tap_end.y < tap_begin.y)
    gestureDown = true;
  if(tap_end.y > tap_begin.y)
    gestureUp = true;

  CCLOG("Gesture Down: %d", gestureDown ? 1 : 0);
  CCLOG("Gesture Up: %d", gestureUp ? 1 : 0);
  CCLOG("Col Touched: %d", touch_col);

  if(gestureDown){
    GroupSphere grab_spheres;



    if(player->typeOnBag() != SPHERE_COUNT){
      grab_spheres = board->dropSphere(touch_col, player->typeOnBag());
      CCLOG("Tomo del mismo color %d", player->typeOnBag());
    }else{
      CCLOG("Toma el primero");
      grab_spheres = board->dropSphere(touch_col);
    }
    for(auto it = grab_spheres.begin(); it != grab_spheres.end(); it++){
      player->takeSphere(&(*it));
      CCLOG("\tguardando en el bolso");
    }
    player->jumpTo(touch_col);
    player->animateTake();
    playSoundTake();
  }else if(gestureUp){
    GroupSphere on_bag = player->getBag();
    board->takeSphere(TOUCH_TO_COL(tap_begin), on_bag);
    player->jumpTo(TOUCH_TO_COL(tap_begin));
    player->animateDrop();
    playSoundDrop();
  }



  //fin
  gestureUp = false; gestureDown = false; tap_begin = Point::ZERO;
}

void Arcade::onMatchSpheres(GroupSphere &spheres, unsigned int start_count_match){
  if(start_count_match < 3) return;
  std::cout << "On Match Spheres: " << spheres.size() << " StartCountMatch:" << start_count_match << std::endl;
  for(auto it = spheres.begin(); it != spheres.end(); it++){
    std::cout << "MatchToRemove:" << (*it)->getPosition().x << "," << (*it)->getPosition().y  << " Type:" << (*it)->getType() << std::endl;
    //@todo aqui efecto de destruccion

   
    playSoundCollide();
    board->dropSphere((*it)->getPosition());
  }

  MessageBoard* send = new MessageBoard(board, this);
 Node* view = board->getView();
 view->retain();
 view->setUserData(send);
 view->runAction(Sequence::create(
				  DelayTime::create(getDelayBeforeFall()),
				  //@todo efecto de fondo

				  CallFuncN::create(
						     [](Node* node){
						       MessageBoard* recv = static_cast<MessageBoard*>(node->getUserData());
						       recv->getBoard()->fallSpheres(CC_CALLBACK_2(Arcade::onFallSphere, recv->getArcade()));
						       delete recv;
						     }
						    ),
				   NULL
				  )
		 );


}

void Arcade::playSoundTake() {
  PLAY_EFFECT(_snd_take.getCString());
}

void Arcade::playSoundDrop() {
  PLAY_EFFECT(_snd_drop.getCString());
}

void Arcade::playSoundCollide() {
  PLAY_EFFECT(_snd_collide.getCString());
}

//Efecto al caer
void Arcade::onFallSphere(Sphere* sphere, PointGrid sphere_next_pos){
  std::cout << "New Pos for Sphere: " << sphere->getType() << " From: " << sphere->getPosition().x << "," << sphere->getPosition().y << "To:" << sphere_next_pos.x << "," << sphere_next_pos.y << std::endl;
  Node* view = sphere->getView();
  view->retain();
  Node* board_view = board->getView();
  board_view->retain();
  Point new_pos = sphere_next_pos.toPoint();
  new_pos.x += GRID_SIZE/2;
  new_pos.y *= -1;
  new_pos.y += board_view->getContentSize().height;
  sphere->retain();
  //@todo revizar memoria
  MessageBoardSphere* send = new MessageBoardSphere(board, sphere);
  view->setUserData(send);
  view->runAction(Sequence::create(
				   Effects::ActionSphereFall(new_pos),
				   CallFuncN::create(
						     [](Node* node){
						       MessageBoardSphere* recv = static_cast<MessageBoardSphere*>(node->getUserData());
						       recv->getBoard()->updateMatch(recv->getSphere()->getPosition());
						       delete recv;
						     }
						     ),
				   NULL
				   )
		  );
  
  //sphere_view_tmp->runAction(Sequence::create(
					      //@todo genera fallo de segmentacion porque??
					      //Animate::create(AnimationCache::getInstance()->getAnimation("exploit_sphere")),
  //				      DelayTime::create(0.1),
  //				      RemoveSelf::create(),
  //				      NULL));
}

//Grupo de esferas que cayeron
void Arcade::onFallSpheres(GroupSphere spheres, std::vector<PointGrid> spheres_old_pos, std::vector<PointGrid> spheres_new_pos){
  for(auto isfall = spheres_new_pos.begin(); isfall != spheres_new_pos.end(); isfall++){
    board->updateMatch((*isfall));
  }
}

void Arcade::onAnimateExploitSphere(Sphere *sphere)
{
  std::cout << __FUNCTION__ << std::endl;
  Node *sphere_view = sphere->getView();
  sphere_view->retain();

  Sphere *sphere_tmp = Sphere::create(sphere->getType());

  Node *sphere_view_tmp = sphere_tmp->getView();
  sphere_view_tmp->retain();

  Node *board_view = board->getView();
  board_view->retain();
  board_view->addChild(sphere_view_tmp);
  sphere_view_tmp->setPosition(sphere_view->getPosition());
  sphere_view_tmp->runAction(Sequence::create(

					      //@todo no se visualiza la animacion???
					      //si pongo este en la vista del fondo si reproduce animacion
					      //Animate::create(AnimationCache::getInstance()->getAnimation("exploit_sphere")),
					      //DelayTime::create(0.1),
					      Effects::ActionSphereFall(Point(0,0)),
					      RemoveSelf::create(),
					      NULL));

}

void Arcade::onReachEndBoard(GroupSphere spheres){
  std::cout << __FUNCTION__ << std::endl;
  stopAllActions();
  unscheduleAllSelectors();
  removeFromParentAndCleanup(true);
  Director::getInstance()->end();
}
