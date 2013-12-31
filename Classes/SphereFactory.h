#ifndef SPHEREFACTORY_H
#define SPHEREFACTORY_H

#include "cocos2d.h"

#include "Sphere.h"

/**
 *Factory para creacion de esferas/cristales
 *@deprecated esto sobra con el Sphere::create(type)
 */
class SphereFactory
{
 protected:
  SphereFactory();

 public:
  static SphereFactory* getInstance();
  Sphere* makeSphere(SphereType);
 private:
  static SphereFactory* _instance;
};

#endif
