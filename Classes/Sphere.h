#ifndef SPHERE_H
#define SPHERE_H

#include "cocos2d.h"

typedef GroupSphere std::vector<Sphere*>*;

enum SphereType {SPHERE_RED, 
		 SPHERE_GREEN,
		 SPHERE_BLUE,
		 SPHERE_YELLOW, 
		 SPHERE_VIOLET,
		 SPHERE_CHROMATIC, 
		 SPHERE_COUNT};

/**
 *Representa un cristal del video juego,
 *este es una imagen
 */
class Sphere : public cocos2d::Object
{
 public:
  static Sphere* create(SphereType);
  /**
   *Tipo de esfera
   */
  CC_SYNTHESIZE(SphereType, _type, Type);
  /**
   *Vista en cocos2d
   */
  CC_SYNTHESIZE(cocos2d::Node, _node, View);
};

#endif
