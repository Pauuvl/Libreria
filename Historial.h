#ifndef HISTORIAL_H
#define HISTORIAL_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

class Historial {
private:
    list<string> compras;

public:
    void registrarCompra(const string &descripcion) {
        compras.push_back(descripcion);
        cout << "Compra registrada: " << descripcion << endl;
    }

    void mostrarHistorial() {
        cout << "Historial de compras:\n";
        for (const auto &compra : compras) {
            cout << "- " << compra << endl;
        }
    }
};

#endif // HISTORIAL_H