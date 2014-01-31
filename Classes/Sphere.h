#ifndef SPHERE_H
#define SPHERE_H

#include "cocos2d.h"
#include "PointGrid.h"


enum SphereType {SPHERE_RED = 0, 
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
  Sphere();
  static Sphere* create(SphereType);
  virtual ~Sphere();

  /**
   *Tipo de esfera
   */
  void setType(SphereType);
  SphereType getType();
  void setPosition(PointGrid);
  PointGrid getPosition();
  void updateView(int, int);
  /**
   *nodo cocos2d representa vista
   */
  cocos2d::Node* getView();
  void viewRemoveFromParent() { _node->removeFromParent(); }
 private:					
  cocos2d::Node *_node;
  PointGrid _pos;
  SphereType _type;
};
typedef std::vector<Sphere*> GroupSphere;
#endif
