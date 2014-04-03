#include "../Classes/AppDelegate.h"
#include "cocos2d.h"
#include "CCEGLView.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string>

#include <cppunit/ui/text/TestRunner.h>
#include "../Classes/Tests/Tests.h"
USING_NS_CC;

int main(int argc, char **argv)
{
    // create the application instance
    AppDelegate app;
    EGLView eglView;
    //eglView.init("trescarables", 384,640);
    eglView.init("trescarables", 360,640);
    Application::getInstance()->setAnimationInterval(1.0f/60.0f);
    if(argc ==  2) {
      if(!strcmp(argv[1],"-t")){
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(Tests::suite());
	runner.run();
	return 0;
      }
    }

    return Application::getInstance()->run();
}
