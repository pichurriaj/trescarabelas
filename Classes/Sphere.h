#ifndef SPHERE_H
#define SPHERE_H

#include "cocos2d.h"

enum SphereType {SPHERE_RED, 
		 SPHERE_GREEN,
		 SPHERE_BLUE,
		 SPHERE_YELLOW, 
		 SPHERE_VIOLET,
		 SPHERE_CHROMATIC, 
		 SPHERE_COUNT};

class Sphere : public cocos2d::Node
{
 public:
  static Sphere* create(SphereType);
  virtual bool init();
  /**
   *Tipo de esfera
   */
  CC_SYNTHESIZE(SphereType, _type, Type);
};

#endif
