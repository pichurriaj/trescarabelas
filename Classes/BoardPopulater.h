#ifndef BOARDPOPULATER_H
#define BOARDPOPULATER_H

/**
 *Se encarga de rellenar un tablero
 *e ir agregando filas
 */
class BoardPopulater {
 public:
  virtual void populate() = 0;

  /**
   *Llena de bolas al final de la cadena
   */
  virtual void populate_next_row() = 0;	       
  
  /**
   *Llena fila al principio, y desplaza el resto
   */
  virtual void populate_first_row() = 0;
};

#endif
