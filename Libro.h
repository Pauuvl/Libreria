#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

class Libro {
public:
  string titulo, autor, genero;
  double precio;
  int stock;

  // Constructor predeterminado
  Libro() : titulo(""), autor(""), genero(""), precio(0.0), stock(0) {}

  // Constructor con parámetros
  Libro(string t, string a, string g, double p, int s)
      : titulo(t), autor(a), genero(g), precio(p), stock(s) {}
};

#endif // LIBRO_H