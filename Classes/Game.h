#ifndef _GAME_H_
#define _GAME_H_

#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1280
#define GRID_SIZE 64

/**
 *Desplaza *node* a centro de *to_node*
 */
#define NODE_CENTER_TO(node, to_node) \
  node->setPosition(to_node->getPosition().x, to_node->getPosition().y)
#endif
