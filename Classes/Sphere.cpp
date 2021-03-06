#include "Sphere.h"
#include "Game.h"

USING_NS_CC;

Sphere::Sphere() : _pos(PointGrid(0,0)), _node(NULL){
}

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

void Sphere::setType(SphereType type) {
  if(_node) {
    _node->release();
    _node = NULL;
  }

  _node = Node::create();
  Sprite* _sp = NULL;
  _node->setContentSize(Size(GRID_SIZE, GRID_SIZE));
  switch(type) {
  case SPHERE_RED:
    _sp = Sprite::create("objetos/esfera_roja.png");
    _type = type;
    break;
  case SPHERE_GREEN:
    _sp = Sprite::create("objetos/esfera_verde.png");
    _type = type;
    break;
  case SPHERE_BLUE:
    _sp = Sprite::create("objetos/esfera_azul.png");
    _type = type;
    break;
  case SPHERE_YELLOW:
    _sp = Sprite::create("objetos/esfera_amarilla.png");
    _type = type;
    break;
  case SPHERE_VIOLET:
    _sp = Sprite::create("objetos/esfera_morada.png");
    _type = type;
    break;
  case SPHERE_CHROMATIC:
    _sp = Sprite::create("objetos/esfera_gris.png");
    _type = type;
    break;
  default:
    /**
     *una bola de error
     */
    _sp = Sprite::create("objetos/esfera_error.png");
    break;
  }
  NODE_CENTER_TO(_sp, _node);
  _node->addChild(_sp);

}

SphereType Sphere::getType() {
  return _type;
}

PointGrid Sphere::getPosition() {
  return _pos;
}

void Sphere::setPosition(PointGrid pos) {
  _pos = pos;
}

Node* Sphere::getView() {
  _node->retain();
  return _node;
}


void Sphere::updateView(int offset_x, int board_height) {
  _node->setPosition(Point(_pos.toPoint().x + offset_x,
			   board_height-_pos.toPoint().y));
}
