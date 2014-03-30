#include "LevelManager.h"
#include <cstring>
USING_NS_CC;


LevelManager* LevelManager::_instance = NULL;

LevelManager::LevelManager(){
  stage = NULL;
}

LevelManager* LevelManager::getInstance() {
  if(!_instance){
    _instance = new LevelManager();
    return _instance;
  }
  return _instance;
}

void LevelManager::setCurrentStage(const char* _stage){
  if(stage){
    free(stage);
    stage = NULL;
  }
  stage = strdup(_stage);
  CCLOG("ASIGNED CURRENT STAGE: %s", stage);
}

void LevelManager::setCurrentLevel(int lvl){
  if(!stage) return;
  char key[200];
  memset(key, 0, 200);
  strcat(key, stage);
  strcat(key, "_current_lvl");
  UserDefault::getInstance()->setIntegerForKey(key, lvl);
}

int LevelManager::getCurrentLevel(){
  if(!stage) return 0;
  char key[200];
  memset(key, 0, 200);
  strcat(key, stage);
  strcat(key, "_current_lvl");
  return UserDefault::getInstance()->getIntegerForKey(key);
}

bool LevelManager::getLevelComplete(int lvl){
  if(!stage) return false;
  return UserDefault::getInstance()->getBoolForKey(String::createWithFormat("%s_%d", stage, lvl)->getCString(), false);
}

void LevelManager::setLevelComplete(int lvl, bool state){
  if(!stage) return;
  UserDefault::getInstance()->setBoolForKey(String::createWithFormat("%s_%d", stage, lvl)->getCString(), state);
  UserDefault::getInstance()->flush();
}

void LevelManager::setLevelLock(int lvl, bool lock){
  if(!stage) {
    CCLOG("NO STAGE %s", stage);
    return;
  }
 UserDefault::getInstance()->setBoolForKey(String::createWithFormat("%s_%d_lock", stage, lvl)->getCString(), lock);
 UserDefault::getInstance()->flush();
}

bool LevelManager::getLevelLock(int lvl){
  if(!stage) return true;
  return UserDefault::getInstance()->getBoolForKey(String::createWithFormat("%s_%d_lock", stage, lvl)->getCString(), true);

}

void LevelManager::unlockNextLevel(int lvl){
  if(!stage) return;
  setLevelLock(lvl+1, false);
}


void LevelManager::setMaxLevel(int mlvl){
  if(!stage) return;
  char key[200];
  memset(key, 0, 200);
  strcat(key, stage);
  strcat(key, "_max_lvl");
  UserDefault::getInstance()->setIntegerForKey(key, mlvl);
  UserDefault::getInstance()->flush();
}

int LevelManager::getMaxLevel(){
  if(!stage) return 0;
  char key[200];
  memset(key, 0, 200);
  strcat(key, stage);
  strcat(key, "_max_lvl");
  return UserDefault::getInstance()->getIntegerForKey(key);
}


bool LevelManager::goalHighScore(int lvl){
 if(!stage) return false;
 return UserDefault::getInstance()->getBoolForKey(String::createWithFormat("%s_%d_goal_high_score", stage, lvl)->getCString(), false);
}

bool LevelManager::goalLowScore(int lvl){
 if(!stage) return false;
 return UserDefault::getInstance()->getBoolForKey(String::createWithFormat("%s_%d_goal_low_score", stage, lvl)->getCString(), false);
}

bool LevelManager::goalScore(int lvl){
 if(!stage) return false;
 return UserDefault::getInstance()->getBoolForKey(String::createWithFormat("%s_%d_goal_score", stage, lvl)->getCString(), false);
}

void LevelManager::setGoalHighScore(int lvl){
  if(!stage) return;
  UserDefault::getInstance()->setBoolForKey(String::createWithFormat("%s_%d_goal_high_score", stage, lvl)->getCString(), true);
  UserDefault::getInstance()->flush();
}

void LevelManager::setGoalLowScore(int lvl){
 if(!stage) return;
  UserDefault::getInstance()->setBoolForKey(String::createWithFormat("%s_%d_goal_low_score", stage, lvl)->getCString(), true);
  UserDefault::getInstance()->flush();
}

void LevelManager::setGoalScore(int lvl){
 if(!stage) return;
  UserDefault::getInstance()->setBoolForKey(String::createWithFormat("%s_%d_goal_score", stage, lvl)->getCString(), true);
  UserDefault::getInstance()->flush();
}

const char* LevelManager::getCurrentStage(){
  return stage;
}
