#ifndef SPHERE_H
#define SPHERE_H

#include "cocos2d.h"
#include "PointGrid.h"


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
  virtual ~Sphere();

  /**
   *Tipo de esfera
   */
  CC_SYNTHESIZE(SphereType, _type, Type);

  void setPosition(PointGrid);
  PointGrid getPosition();

  /**
   *nodo cocos2d representa vista
   */
  cocos2d::Node* getView();

 private:					
  cocos2d::Node *_node;
  PointGrid _pos;
  
};
typedef std::vector<Sphere*>* GroupSphere;
#endif
