#include "ArcadeScene.h"
#include "BoardPopulaterRandom.h"
#include "Effects.h"
#include "MessageBoardSphere.h"
#include "MessageBoard.h"
#include "SimpleAudioEngine.h"
#include "LevelManager.h"
#include "ArcadeMenuScene.h"

#define PLAY_EFFECT(X) CocosDenshion::SimpleAudioEngine::sharedEngine()->playEffect(X);
#define PLAY_MUSIC(X) CocosDenshion::SimpleAudioEngine::sharedEngine()->playBackgroundMusic(X, true);
USING_NS_CC;

#define TOUCH_TO_COL(T) (int)(T.x / GRID_SIZE)
#define DELAY_BEFORE_FALL 0.06f
#define DELAY_ROLL_BOARD 6.0f
#define DELAY_STOP_COMBO 2.0f
#define DEFAULT_TIME_START 60
#define DEFAULT_SCORE_MATCH 35
#define DEFAULT_SCORE_COMBO 70
#define DEFAULT_RANDOMIZE_BALL 2
#define DEFAULT_ROWS_START 4

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
  setDelayRollBoard(DELAY_ROLL_BOARD);
  setDelayBeforeFall(DELAY_BEFORE_FALL);
  setDelayStopCombo(DELAY_STOP_COMBO);
  setRandomizeBall(DEFAULT_RANDOMIZE_BALL);
  setRowsStart(DEFAULT_ROWS_START);
  //objetivos
  setGoal(SCORE_WIN);
  setScoreWin(400);
  setComboWin(6);
  _stop = false; _goto_menu = false;
  _snd_take = String("musica y sonidos/baja.ogg");
  _snd_drop = String("musica y sonidos/sube.ogg");
  _snd_collide = String("musica y sonidos/choca_perla.ogg");
  
  //set key
  this->setKeypadEnabled(true);
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

  _anim_exploit_sphere->setRestoreOriginalFrame(false);
  AnimationCache::getInstance()->addAnimation(_anim_exploit_sphere, "exploit_sphere");

  background = Sprite::create("mapas/mapa_arcade.png");
  background->setPosition(Point(
			visibleSize.width/2 + origin.x,
			visibleSize.height/2 + origin.y
			)
		  );
  this->addChild(background, -10);
  auto border = Sprite::create("efectos/barraArriba.png");
  border->setPosition(Point(visibleSize.width/2 + origin.x,
			    visibleSize.height - border->getContentSize().height/4 + origin.y));
  this->addChild(border, 9999);
  //iniciale el tablaro
  //y el populador del tablero
  board = Board::create();
  Node* board_view = board->getView();
  this->addChild(board_view);
  board_view->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  board->attachMatch(CC_CALLBACK_2(Arcade::onMatchSpheres, this));
  board->attachFall(CC_CALLBACK_3(Arcade::onFallSpheres, this));
  board->attachDropSphere(CC_CALLBACK_1(Arcade::onAnimateExploitSphere, this));
  board->attachEndBoard(CC_CALLBACK_1(Arcade::onReachEndBoard,this));
  board_populater = new BoardPopulaterRandom(board);
  board_populater->setStartRows(getRowsStart());
  board_populater->populate();
  board->setPopulater(board_populater);


  player = Indian::create();
  player->retain();
  Node* player_view = player->getView();
  this->addChild(player_view);
  player->jumpTo(3);

  _score_label = LabelTTF::create("0000","default", 60);

  this->addChild(_score_label, 99999);
  _score_label->setPosition(Point(origin.x + _score_label->getContentSize().width,
				  origin.y + visibleSize.height - _score_label->getContentSize().height/2));

  //variables de juego
  setTimeStart(DEFAULT_TIME_START);
  _time = getTimeStart();
  _clock_label = LabelTTF::create(String::createWithFormat("%02i", _time)->getCString(), "default", 60);
  this->addChild(_clock_label, 99999);
  _clock_label->setPosition(Point(visibleSize.width/2 + origin.x,
				  visibleSize.height + origin.y - _clock_label->getContentSize().height/3));
  _time_over = false;
  _score = 0;
  setScoreCombo(DEFAULT_SCORE_COMBO);
  setScoreMatch(DEFAULT_SCORE_MATCH);
  auto dispatcher = Director::getInstance()->getEventDispatcher();
  auto listener = EventListenerTouchOneByOne::create();
  listener->onTouchBegan = CC_CALLBACK_2(Arcade::onTouchBegan, this);
  listener->onTouchMoved = CC_CALLBACK_2(Arcade::onTouchMoved, this);
  listener->onTouchEnded = CC_CALLBACK_2(Arcade::onTouchEnded, this);

  dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
  this->schedule(schedule_selector(Arcade::updateBoard), 1.0f);

  CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
  PLAY_MUSIC("musica y sonidos/juego.ogg");
  _time_roll_board.initWithTarget(this, schedule_selector(Arcade::updateRollBoard));
  _time_roll_board.setInterval(getDelayRollBoard());
  _time_combo.initWithTarget(this, schedule_selector(Arcade::updateCombo));
  _time_combo.setInterval(0.5f);
  _in_combo = false; _time_elapsed_combo = 0;
  return true;
}

void Arcade::updateBoard(float dt){
  if(!_in_combo){
    switch(getGoal()){
    case SCORE_WIN:
      if(_score > getScoreLowWin()){
	showWinner();
	unlockNextLevel();
      }
      break;
    case COMBO_WIN:
      if(_combo_count > getComboWin()){
	showWinner();
	unlockNextLevel();
      }
      break;
    }
  }
  _time_roll_board.update(dt);
  _time_combo.update(dt);
  updateClock(dt);

}


void Arcade::updateClock(float dt){
  _time --;
  auto value = String::createWithFormat("%02i", _time);
  _clock_label->setString(value->getCString());
  _clock_label->setFontFillColor(Color3B(255,255,0));

  if(_time < 0 && !_in_combo){
    _time = 0;
    showLosser();
    _time_over = true;
  }else if(_time < getTimeStart() * 0.20){
    _clock_label->setColor(Color3B::RED);
    _clock_label->runAction(
			    Sequence::create(
					     FadeOut::create(0.4f),
					     FadeIn::create(0.4f),
					     NULL
					     )
			    );
  } else if(_time < getTimeStart() * 0.5) {
    _clock_label->setColor(Color3B::YELLOW);
    _clock_label->runAction(
			    Sequence::create(
					     FadeOut::create(0.7f),
					     FadeIn::create(0.3f),
					     NULL
					     )
			    );
  }

}

void Arcade::updateRollBoard(float dt){
  board_populater->populate_first_row();
}


void Arcade::updateCombo(float dt){
  if(!_in_combo) return;
  if(_time_elapsed_combo >= getDelayStopCombo()){
    addScore(_in_combo * getScoreCombo());

    _time_elapsed_combo = 0;
    _in_combo = false;
    _combo_count = 0;
    return;
  }
  /*inicia/continua combo*/
  if(_time_elapsed_combo == 0){
    //@todo logica de cuando se realiza el combo
    //_combo_count cantidad de combos hasta ahora
    std::cout << __FUNCTION__ << "combos:" << _combo_count << std::endl;
    LabelTTF* combo_label = LabelTTF::create(String::createWithFormat("%d Combo", _combo_count)->getCString(),
					     "default", 80);
    combo_label->runAction(Sequence::create(
					    FadeOut::create(getDelayStopCombo()),
					    RemoveSelf::create(),
					    NULL
					    )
			   );
    this->addChild(combo_label, 999);
    combo_label->setPosition(Point(visibleSize.width/2,
				   visibleSize.height/2));

    //da tiempo cuando se hace buena cantidad de combos
    //@todo asignar desde metodos para cambiar segun dificultad
    if(_combo_count > 4){
      addTime(5);
    }
  }

  _time_elapsed_combo += dt;
}

bool Arcade::onTouchBegan(Touch* touch, Event* event){
 if(_stop) return false;

  tap_begin = touch->getLocationInView();
  tap_begin.x -= board->offset().x;
  gestureUp = false; gestureDown = false;
  return true;
}

void Arcade::onTouchMoved(Touch* touch, Event* event){
}

void Arcade::onTouchEnded(Touch* touch, Event* event){
  Point tap_end = touch->getLocationInView();  
  tap_end.x -= board->offset().x;

  CCLOG("Tap END %f,%f", tap_end.x, tap_end.y);
  int touch_col = TOUCH_TO_COL(tap_begin);
  auto board_grid = board->getGrid();
  if(touch_col < 0 || touch_col >= board_grid.getCols())  return;

  if(tap_end.y > tap_begin.y)
    gestureDown = true;
  if(tap_end.y < tap_begin.y)
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
    player->getView()->setPosition(player->getView()->getPosition() + board->offset());
    playSoundTake();
  }else if(gestureUp){
    GroupSphere on_bag = player->getBag();
    board->takeSphere(TOUCH_TO_COL(tap_begin), on_bag);
    player->jumpTo(TOUCH_TO_COL(tap_begin));
    player->getView()->setPosition(player->getView()->getPosition() + board->offset());
    player->animateDrop();
    playSoundDrop();
  }



  //fin
  gestureUp = false; gestureDown = false; tap_begin = Point::ZERO;
}

void Arcade::onMatchSpheres(GroupSphere &spheres, unsigned int start_count_match){
  if(start_count_match < 3 + 1 /*offset*/) return;
  std::cout << "On Match Spheres: " << spheres.size() << " StartCountMatch:" << start_count_match << std::endl;
  for(auto it = spheres.begin(); it != spheres.end(); it++){
    std::cout << "MatchToRemove:" << (*it)->getPosition().x << "," << (*it)->getPosition().y  << " Type:" << (*it)->getType() << std::endl;
    //@todo aqui efecto de destruccion

   
    playSoundCollide();
    board->dropSphere((*it)->getPosition());
  }
  /*activa el modo combo*/
  _in_combo  = true;
  _combo_count += 1;
  _time_elapsed_combo = 0;
  addScore(getScoreMatch());

  
  std::cout << "Match Time Elapsed:" << Director::getInstance()->getDeltaTime() << std::endl;
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
  if(!sphere) return;
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
  PointGrid* send_new_pos = new PointGrid(sphere_next_pos.x, sphere_next_pos.y);
  sphere->setUserData(send_new_pos);
  MessageBoardSphere* send = new MessageBoardSphere(board, sphere);
  view->setUserData(send);
  view->retain();
  view->runAction(Sequence::create(
				   Effects::ActionSphereFall(new_pos),
				   CallFuncN::create(
						     [](Node* node){
						       if(!node) return;
						       MessageBoardSphere* recv = static_cast<MessageBoardSphere*>(node->getUserData());
						       PointGrid *new_pos = static_cast<PointGrid*>(recv->getSphere()->getUserData());
						       recv->getSphere()->setPosition(*new_pos);
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
  showLosser();
  /*std::cout << __FUNCTION__ << std::endl;
  stopAllActions();
  unscheduleAllSelectors();
  removeFromParentAndCleanup(true);
  Director::getInstance()->end();*/
}

/**
 *Incrementa el score y actualiza label
 */
void Arcade::addScore(int p){
  _score += p;
  _score_label->setString(String::createWithFormat("%04i", _score)->getCString());
}

/**
 *Incrementa el tiempo
 *cambia de color la letras para advertir
 */
void Arcade::addTime(int time){
  _time += time;
  if(_time >= getTimeStart())
    _clock_label->setFontFillColor(Color3B(255,255,255));
  else if(_time >= getTimeStart() * 0.5)
    _clock_label->setFontFillColor(Color3B::YELLOW);
  else if(_time >= getTimeStart() * 0.20)
    _clock_label->setFontFillColor(Color3B::RED);

  _clock_label->setString(String::createWithFormat("%02i", _time)->getCString());
}

void Arcade::onKeyReleased(EventKeyboard::KeyCode keyCode, cocos2d::Event *event){
  if(keyCode == EventKeyboard::KeyCode::KEY_BACKSPACE){
    std::cout << __FUNCTION__ << std::endl;
    gotoArcadeMenu();
  
  }
}


void Arcade::showWinner(){
  _stop = true;
  stopAllActions();
  unscheduleAllSelectors();
  CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
  PLAY_MUSIC("musica y sonidos/gana.ogg");

  Sprite* win = Sprite::create("efectos/gana.png");
  Point pos_win(visibleSize.width/2, visibleSize.height - win->getContentSize().height);
  win->setPosition(pos_win);
  win->runAction(RepeatForever::create(
		 Sequence::create(
				  Spawn::create(EaseInOut::create(RotateTo::create(1.2f, -30), 2),
						EaseInOut::create(MoveTo::create(1.2f, pos_win), 2),
						NULL
						),
				  Spawn::create(
					      EaseInOut::create(RotateTo::create(1.2f, 30), 2),
					      EaseInOut::create(MoveTo::create(1.2f, pos_win), 2),

					      NULL),
				NULL
				  ))
		 );
  this->addChild(win, 777);
  
  Node* particle_win = Node::create();
  const char* effects[] = {
    "efectos/azul_lluvia.png",
    "efectos/verde_lluvia.png",
    "efectos/morado_lluvia.png",
    "efectos/rojo_lluvia.png"
  };
  int particles = 50;
  for(int ix = 0; ix < particles; ix++){
    Sprite* sp = Sprite::create(effects[rand()%4]);
    sp->retain();
    particle_win->addChild(sp);
    sp->setPosition(Point(visibleSize.width/2,
			  visibleSize.height/2));
    float dst_time = (float)(rand() % 8 + 3);
    float dst_x_particle = rand() % (int)visibleSize.width;
    float dst_y_particle = rand() % (int)visibleSize.height - visibleSize.height;
    float dst_angle = (float)(rand() % 360);
    float dst_rotate_time = (float)(rand() % 8 + 3);
    Point dst(dst_x_particle, dst_y_particle);
    sp->runAction(
		  RepeatForever::create(
					Sequence::create(
							 FadeIn::create(0.0f),
							 MoveTo::create(0.0f, Point(visibleSize.width/2,
										    visibleSize.height/2)),
							 Spawn::create(
								       FadeOut::create(dst_time),
								       EaseSineInOut::create(MoveTo::create(dst_time, dst)),
								       RepeatForever::create(
											     RotateTo::create(dst_rotate_time, dst_angle)
											     ),
								       NULL),

							 NULL
							 )
					)
		  );

  }
  this->addChild(particle_win);
  
  auto score_label = LabelTTF::create(String::createWithFormat("Score %d", _score)->getCString(),"default", 60);
  score_label->setPosition(Point(visibleSize.width/2, visibleSize.height/2 - score_label->getContentSize().height));
  this->addChild(score_label);
  
  /*auto time_label = LabelTTF::create(String::createWithFormat("Time%d", abs(getTimeStart() - getTime()) )->getCString(), "ThonburiBold", 60);
  time_label->setPosition(Point(visibleSize.width/2, visibleSize.height/2 - score_label->getContentSize().height - time_label->getContentSize().height));
  this->addChild(time_label);*/
  //unlock next level
  CCLOG("Winner LVL: %d", LevelManager::getInstance()->getCurrentLevel());
  LevelManager::getInstance()->setLevelComplete(LevelManager::getInstance()->getCurrentLevel(),
						true);
  LevelManager::getInstance()->unlockNextLevel(LevelManager::getInstance()->getCurrentLevel());
  _goto_menu = true;
  auto a_menu = MenuItemImage::create(
				      "botones/boton_gana.png",
				      "botones/boton_gana_presionado.png",
				      CC_CALLBACK_0(Arcade::gotoArcadeMenu, this)
				      );
  auto menu = Menu::create(a_menu,NULL);
  menu->setPosition(Point(visibleSize.width/2,
			  visibleSize.height/2 + a_menu->getContentSize().height/2));
  this->addChild(menu);

  //copas
  if(_score >= getScoreLowWin())
    LevelManager::getInstance()->setGoalLowScore(LevelManager::getInstance()->getCurrentLevel());
  if(_score >= getScoreWin())
    LevelManager::getInstance()->setGoalScore(LevelManager::getInstance()->getCurrentLevel());
  if(_score >= getScoreHighWin())
    LevelManager::getInstance()->setGoalHighScore(LevelManager::getInstance()->getCurrentLevel());

  auto logro_fondo = Sprite::create("efectos/puntaje_fondo.png");
  logro_fondo->setPosition(Point(visibleSize.width/2 - logro_fondo->getContentSize().width,
				 visibleSize.height/4));
  this->addChild(logro_fondo, 888);

  
  if(LevelManager::getInstance()->goalLowScore(LevelManager::getInstance()->getCurrentLevel())){
    auto logro_low = Sprite::create("efectos/puntaje.png");
    logro_low->setPosition(Point(visibleSize.width/2 - logro_low->getContentSize().width,
				 visibleSize.height/4));
    this->addChild(logro_low, 999);
  }

  logro_fondo = Sprite::create("efectos/puntaje_fondo.png");
  logro_fondo->setPosition(Point(visibleSize.width/2,
				 visibleSize.height/4));
  this->addChild(logro_fondo,888);
  if(LevelManager::getInstance()->goalScore(LevelManager::getInstance()->getCurrentLevel())){
    auto logro = Sprite::create("efectos/puntaje.png");
    logro->setPosition(Point(visibleSize.width/2,
			     visibleSize.height/4));
    this->addChild(logro,999);
  }

  logro_fondo = Sprite::create("efectos/puntaje_fondo.png");
  logro_fondo->setPosition(Point(visibleSize.width/2 + logro_fondo->getContentSize().width,
				 visibleSize.height/4));
  this->addChild(logro_fondo,888);
  if(LevelManager::getInstance()->goalHighScore(LevelManager::getInstance()->getCurrentLevel())){
    auto logro_high = Sprite::create("efectos/puntaje.png");
    logro_high->setPosition(Point(visibleSize.width/2 + logro_high->getContentSize().width,
			     visibleSize.height/4));
    this->addChild(logro_high,999);
  }
  
}

void Arcade::showLosser(){
  _stop = true;
  stopAllActions();
  unscheduleAllSelectors();
  CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
  PLAY_MUSIC("musica y sonidos/pierde.ogg");

  Sprite* win = Sprite::create("efectos/pierde.png");
  Point pos_win(visibleSize.width/2, visibleSize.height - win->getContentSize().height);
  win->setPosition(pos_win);
  this->addChild(win);

  auto a_menu = MenuItemImage::create(
				      "botones/boton_pierde.png",
				      "botones/boton_pierde_presionado.png",
				      CC_CALLBACK_0(Arcade::restartGame, this)
				      );
  auto menu = Menu::create(a_menu,NULL);
  menu->setPosition(Point(visibleSize.width/2,
			  visibleSize.height/2 + a_menu->getContentSize().height/2));
  this->addChild(menu);
}

void Arcade::unlockNextLevel(){
}


void Arcade::gotoArcadeMenu(){
  stopAllActions();
  unscheduleAllSelectors();
  removeFromParentAndCleanup(true);
  Scene* newScene = TransitionFade::create(0.7, ArcadeMenu::createScene()); 
  Director::sharedDirector()->replaceScene(newScene);
}

void Arcade::restartGame(){
  stopAllActions();
  unscheduleAllSelectors();
  removeFromParentAndCleanup(true);
  Scene* newScene = TransitionFade::create(0.7, ArcadeMenu::createScene()); 
  Director::sharedDirector()->replaceScene(newScene);
}

void Arcade::populateRow(){
  board_populater->populate_first_row();
}

void Arcade::changeBackground(const char *path){
  this->removeChild(background);
  background = Sprite::create(path);
  background->setPosition(Point(visibleSize.width/2, visibleSize.height/2));
  this->addChild(background, -10);
}
