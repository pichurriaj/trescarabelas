#include "AppDelegate.h"
#include "GameTestArcadeScene.h"
#include "MenuScene.h"
#include "ArcadeScene.h"
#include "SimpleAudioEngine.h"
USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto eglView = EGLView::getInstance();
    director->setOpenGLView(eglView);
    Size designSize = Size(768, 1280);
    Size screenSize = eglView->getFrameSize();

    Size smallSize = Size(320, 480);
    Size mediumSize = Size(768, 1024);
    Size largeSize = Size(1536, 2048);
    

    EGLView::sharedOpenGLView()->setDesignResolutionSize(designSize.width, designSize.height, ResolutionPolicy::FIXED_HEIGHT);
    if(screenSize.height >= mediumSize.height) {
      director->setContentScaleFactor(largeSize.height/designSize.height);
    }else if(screenSize.height >= smallSize.height) {
      director->setContentScaleFactor(mediumSize.height/designSize.height);
    }else {
      director->setContentScaleFactor(smallSize.height/designSize.height);
      }
    Director::sharedDirector()->setContentScaleFactor(1.0f);
    
    // turn on display FPS
    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    // create a scene. it's an autorelease object
    auto scene = Arcade::createScene();

    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    CocosDenshion::SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    CocosDenshion::SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
