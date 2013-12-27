#include "../Classes/AppDelegate.h"
#include "cocos2d.h"
#include "CCEGLView.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

USING_NS_CC;

int main(int argc, char **argv)
{
    // create the application instance
    AppDelegate app;
    EGLView eglView;
    eglView.init("trescarables", 320,240);
    Application::getInstance()->setAnimationInterval(1.0f/60.0f);
    return Application::getInstance()->run();
}
