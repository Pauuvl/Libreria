#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Usuario {
public:
    string nombre;
    list<string> carrito;

    // Constructor
    Usuario(const string &nombre) : nombre(nombre) {}

    // Default constructor
    Usuario() {} // This will be called when a Usuario is created without a name

    // Agregar un libro al carrito
    void agregarAlCarrito(const string &libro) {
        carrito.push_back(libro);
        cout << "Libro agregado al carrito: " << libro << endl;
    }

    // Mostrar el contenido del carrito
    void mostrarCarrito() {
        cout << "Carrito de " << nombre << ":\n";
        if (carrito.empty()) {
            cout << "(Carrito vacío)\n";
            return;
        }
        for (const auto &libro : carrito) {
            cout << "- " << libro << endl;
        }
    }

    // Vaciar el carrito de compras
    void vaciarCarrito() {
        carrito.clear();
        cout << "El carrito ha sido vaciado.\n";
    }
};

#endif // USUARIO_H