#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "cocos2d.h"
class LevelManager{
 private:
  static LevelManager *_instance;
  char* stage;
  LevelManager();
 public:
  static LevelManager* getInstance();
   int getCurrentLevel();
   void setCurrentLevel(int);
   void setCurrentStage(const char*);
   const char* getCurrentStage();
   void setMaxLevel(int mlvl);
   int getMaxLevel();
   bool getLevelComplete(int lvl);
   void setLevelComplete(int lvl, bool);
   bool getLevelLock(int lvl);
   void setLevelLock(int lvl, bool);
   void unlockNextLevel(int lvl);

   void setGoalHighScore(int lvl);
   void setGoalLowScore(int lvl);
   void setGoalScore(int lvl);
   bool goalHighScore(int lvl);
   bool goalScore(int lvl); //middle
   bool goalLowScore(int lvl);
   
};

#endif
