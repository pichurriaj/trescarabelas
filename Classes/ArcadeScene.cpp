#include "ArcadeScene.h"
#include "BoardPopulaterRandom.h"
#include "Effects.h"
#include "MessageBoardSphere.h"

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
  player->retain();
  board = Board::create();
  Node* board_view = board->getView();
  this->addChild(board_view);
  board_view->setPosition(Point(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
  board->attachMatch(CC_CALLBACK_2(Arcade::onMatchSpheres, this));
  board->attachFall(CC_CALLBACK_3(Arcade::onFallSpheres, this));
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
  //board_populater->populate_first_row();
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
    }else{
      grab_spheres = board->dropSphere(touch_col);
    }
    for(auto it = grab_spheres.begin(); it != grab_spheres.end(); it++){
      player->takeSphere(&(*it));
    }

  }else if(gestureUp){
    GroupSphere on_bag = player->getBag();
    board->takeSphere(TOUCH_TO_COL(tap_begin), on_bag);
  }



  //fin
  gestureUp = false; gestureDown = false; tap_begin = Point::ZERO;
}

void Arcade::onMatchSpheres(GroupSphere &spheres, unsigned int start_count_match){
  if(start_count_match < 3) return;
  std::cout << "On Match Spheres: " << spheres.size() << " StartCountMatch:" << start_count_match << std::endl;
  for(auto it = spheres.begin(); it != spheres.end(); it++){
    std::cout << "MatchToRemove:" << (*it)->getPosition().x << "," << (*it)->getPosition().y  << " Type:" << (*it)->getType() << std::endl;
    board->dropSphere((*it)->getPosition());
  }
  board->fallSpheres(CC_CALLBACK_2(Arcade::onFallSphere, this));
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
}

//Grupo de esferas que cayeron
void Arcade::onFallSpheres(GroupSphere spheres, std::vector<PointGrid> spheres_old_pos, std::vector<PointGrid> spheres_new_pos){
}
