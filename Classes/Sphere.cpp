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

Sphere::~Sphere() {
}

PointGrid Sphere::getPosition() {
  return _pos;
}

void Sphere::setPosition(PointGrid pos) {
  _pos = pos;
}

Node* Sphere::getView() {
  return _node;
}
