#ifndef ARCADESCENE_H
#define ARCADESCENE_H

#include "cocos2d.h"

#include "Indian.h"
#include "Board.h"
#include "BoardPopulater.h"

enum GoalArcade{
  /**
   *gana si llega al puntaje
   */
  SCORE_WIN,
  /**
   *gana si alcanza el combo esperado
   */
  COMBO_WIN
};

class Arcade : public cocos2d::Layer
{
 public:
  static cocos2d::Scene* createScene();
  virtual bool init();
  CREATE_FUNC(Arcade);
  
  void updateBoard(float);
  void updateRollBoard(float);
  void updateCombo(float);
  void updateClock(float);
  void updateTutorial(float);
  
  virtual bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
  virtual void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
  virtual void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
  virtual void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event*);

  void onMatchSpheres(GroupSphere&,unsigned int);
  void onFallSphere(Sphere*, PointGrid);
  void onFallSpheres(GroupSphere spheres, std::vector<PointGrid> spheres_old_pos, std::vector<PointGrid> spheres_new_pos);
  void onAnimateExploitSphere(Sphere*);
  void populateRow();
  void onReachEndBoard(GroupSphere);
  void playSoundTake();
  void playSoundDrop();
  void playSoundCollide();

  void addScore(int);
  void addTime(int);

  void changeBackground(const char*);

  //propiedades usadas especialmente para la dificultad
  //en +segundos+ lo que se demora una esfera en caer
  CC_SYNTHESIZE(float, _delay_before_fall, DelayBeforeFall);

  //en +segundos+ antes de desplazar el tablero
  CC_SYNTHESIZE(float, _delay_roll_board, DelayRollBoard);

  //en +segundos+ cuando se detiene el combo si no se han hecho mas
  CC_SYNTHESIZE(float, _delay_stop_combo, DelayStopCombo);

  //indica la cantidad de esferas que se deben aletorizar
  //el resto se repite la misma
  CC_SYNTHESIZE(int, _randomize_ball, RandomizeBall);


  //tiempo de duracion del juego
  CC_SYNTHESIZE(int, _time, Time);
  CC_SYNTHESIZE(int, _time_start, TimeStart);
  CC_SYNTHESIZE(int, _score_inc_combo, ScoreCombo);
  CC_SYNTHESIZE(int, _score_match, ScoreMatch);
  CC_SYNTHESIZE(int, _rows_start, RowsStart);
  
  //objetivos
  CC_SYNTHESIZE(GoalArcade, _goal, Goal);
  CC_SYNTHESIZE(int, _score_win, ScoreWin);
  CC_SYNTHESIZE(int, _score_low_win, ScoreLowWin);
  CC_SYNTHESIZE(int, _score_high_win, ScoreHighWin);
  CC_SYNTHESIZE(int, _combo_win, ComboWin);
 private:
  void unlockNextLevel();
  void showWinner();
  void showLosser();
  void gotoArcadeMenu();
  void restartGame();

  bool _stop;
  bool _goto_menu;

  cocos2d::Timer _time_roll_board;
  /*@todo Pasar a Objeto??*/
  cocos2d::Timer _time_combo;
  float _time_elapsed_combo;
  bool _in_combo;

  cocos2d::LabelTTF* _clock_label;
  bool _time_over; //bandera: se activa cuando se acaba el tiempo

  cocos2d::LabelTTF* _score_label;
  
  bool gestureDown;
  bool gestureUp;
  cocos2d::Point tap_begin;
  int _score;
  int _combo_count;
  Indian* player;
  cocos2d::Size visibleSize;
  cocos2d::Point origin;
  Board* board;
  BoardPopulater* board_populater;
  cocos2d::Sprite* background;
  cocos2d::String _snd_take;
  cocos2d::String _snd_drop;
  cocos2d::String _snd_collide;

  //tutorial
  cocos2d::Sprite* help_down;
  cocos2d::Sprite* help_up;
  cocos2d::Sprite* help_now;
};

#endif
