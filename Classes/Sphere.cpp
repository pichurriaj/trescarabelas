#include "Sphere.h"
USING_NS_CC;

Sphere* Sphere::create(SphereType type) {
  Sphere* sphere = new Sphere();
  if(sphere) {
    sphere->setType(type);
    sphere->autorelease();
    return sphere;
  }
  CC_SAFE_DELETE(sphere);
  return NULL;
}
