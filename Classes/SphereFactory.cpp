#include "SphereFactory.h"
#include "Sphere.h"
USING_NS_CC;

SphereFactory* SphereFactory::_instance = 0;

SphereFactory* SphereFactory::getInstance() {
  if(_instance == 0) {
    _instance = new SphereFactory();
  }
  return _instance;
}

Sphere* SphereFactory::makeSphere(SphereType type) {
  return Sphere::create(type);
}
