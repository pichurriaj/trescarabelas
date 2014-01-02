#ifndef BOARDPOPULATER_H
#define BOARDPOPULATER_H

/**
 *Se encarga de rellenar un tablero
 *e ir agregando filas
 */
class BoardPopulater {
 public:
  virtual void populate() = 0;
  virtual void populate_next_row() = 0;
};

#endif
