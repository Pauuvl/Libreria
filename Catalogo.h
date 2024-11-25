#ifndef CATALOGO_H
#define CATALOGO_H

#include "Libro.h"
#include <iostream>
#include <unordered_map>

using namespace std;

class Catalogo {
private:
  unordered_map<string, Libro> libros; // Tabla hash para libros

public:
  // Agregar un libro al catálogo
  void agregarLibro(const Libro &libro) {
    libros[libro.titulo] = libro;
    cout << "Libro agregado: " << libro.titulo << endl;
  }

  // Buscar libros por título
  void buscarPorTitulo(const string &tituloClave) {
    cout << "Buscando libros que contengan '" << tituloClave << "' en el título:\n";
    bool encontrados = false;
    for (const auto &par : libros) {
      const Libro &libro = par.second;
      if (libro.titulo.find(tituloClave) != string::npos) { // Buscar coincidencia parcial
        cout << "- Título: " << libro.titulo
             << ", Autor: " << libro.autor
             << ", Género: " << libro.genero
             << ", Precio: $" << libro.precio
             << ", Stock: " << libro.stock << endl;
        encontrados = true;
      }
    }
    if (!encontrados) {
      cout << "No se encontraron libros que coincidan con '" << tituloClave << "'.\n";
    }
  }


  // Mostrar todos los libros
  void mostrarCatalogo() {
    cout << "Catálogo de libros:\n";
    for (const auto &par : libros) {
      const Libro &libro = par.second;
      cout << "Titulo: " << libro.titulo << ", Autor: " << libro.autor
           << ", Género: " << libro.genero << ", Precio: $" << libro.precio
           << ", Stock: " << libro.stock << endl;
    }
  }

  // Buscar libros por categoría (género)
  void buscarPorCategoria(const string &genero) {
    cout << "Libros en la categoría '" << genero << "':\n";
    bool encontrados = false;
    for (const auto &par : libros) {
      const Libro &libro = par.second;
      if (libro.genero == genero) {
        cout << "- Titulo: " << libro.titulo << ", Autor: " << libro.autor
             << ", Precio: $" << libro.precio << ", Stock: " << libro.stock
             << endl;
        encontrados = true;
      }
    }
    if (!encontrados) {
      cout << "No se encontraron libros en la categoría '" << genero << "'.\n";
    }
  }

  // Preordenar libro si no hay stock
  void preordenarLibro(const string &titulo) {
    if (libros.find(titulo) != libros.end()) { // Verificar si el libro está en el catálogo
      const Libro &libro = libros[titulo];
      if (libro.stock > 0) { // Si el libro tiene stock disponible
        cout << "El libro '" << titulo
             << "' esta disponible. No es necesario preordenar.\n";
      } else { // Si el libro no tiene stock
        cout << "El libro '" << titulo
             << "' no esta disponible actualmente. Se ha registrado su preorden.\n";

      }
    } else { // Si el libro no está en el catálogo
      int cantidad;
      cout << "El libro '" << titulo << "' no esta en el catalogo.\n";
      cout << "¿Cuantos ejemplares desea preordenar?: ";
      cin >> cantidad;

      if (cantidad > 0) {
        cout << "Se ha registrado una preorden de " << cantidad
             << " ejemplar(es) del libro '" << titulo << "'.\n";

      } else {
        cout << "La cantidad debe ser mayor que 0. No se registró la preorden.\n";
      }
    }
  }

  // Verificar si un libro está en el catálogo
  bool libroEnCatalogo(const string &titulo) {
    return libros.find(titulo) != libros.end();
  }

  // Actualizar el stock de un libro al realizar una compra
  bool actualizarStock(const string &titulo, int cantidad) {
    if (libros.find(titulo) != libros.end()) {
      Libro &libro = libros[titulo];
      if (libro.stock >= cantidad) {
        libro.stock -= cantidad;
        cout << "Stock actualizado. Quedan " << libro.stock << " unidades de '"
             << titulo << "'.\n";
        return true;
      } else {
        cout << "Stock insuficiente para '" << titulo
             << "'. Disponible: " << libro.stock << " unidades.\n";
        return false;
      }
    }
    cout << "No se encontro el libro '" << titulo << "'.\n";
    return false;
  }
};

#endif // CATALOGO_H