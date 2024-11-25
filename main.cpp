#include "Catalogo.h"
#include "Historial.h"
#include "Usuario.h"
#include <unordered_map>

void menu() {
    cout << "\n=== MENU ===\n";
    cout << "1. Agregar libro al catalogo\n";
    cout << "2. Buscar libro por titulo\n";
    cout << "3. Mostrar catalogo\n";
    cout << "4. Registrar compra\n";
    cout << "5. Mostrar historial de compras\n";
    cout << "6. Mostrar carrito\n";
    cout << "7. Agregar libro al carrito\n";
    cout << "8. Vaciar carrito\n";
    cout << "9. Buscar libro por categoria\n";
    cout << "10. Preordenar libro\n";
    cout << "11. Salir del usuario\n";
    cout << "12. Salir del programa\n";
}

int main() {
    Catalogo catalogo;
    Historial historial;
    unordered_map<string, Usuario> usuarios; // Mapa para almacenar usuarios
    Usuario *currentUser = nullptr;          // Usuario actual

    while (true) { // Bucle para gestionar el login y los usuarios
        if (currentUser == nullptr) {
            char respuesta;
            do {
                cout << "Bienvenido! ¿Ya tienes una cuenta? (s/n): ";
                cin >> respuesta;
                cin.ignore();

                if (respuesta == 'n') {
                    // Crear nueva cuenta
                    cout << "Ingrese su nombre: ";
                    string nombre;
                    getline(cin, nombre);
                    usuarios[nombre] = Usuario(nombre);
                    currentUser = &usuarios[nombre];
                    cout << "Usuario " << currentUser->nombre << " creado.\n";
                } else if (respuesta == 's') {
                    // Buscar usuario existente
                    cout << "Ingrese su nombre de usuario: ";
                    string nombre;
                    getline(cin, nombre);
                    if (usuarios.find(nombre) != usuarios.end()) {
                        currentUser = &usuarios[nombre];
                        cout << "Bienvenido de nuevo, " << currentUser->nombre << "!\n";
                    } else {
                        cout << "Usuario no encontrado. Intente de nuevo.\n";
                    }
                } else {
                    cout << "Opcion inválida. Intente de nuevo.\n";
                }
            } while (currentUser == nullptr);
        }

        int opcion;
        do {
            menu();
            cin >> opcion;

            switch (opcion) {
            case 1: {
                // Agregar libro al catálogo
                string titulo, autor, genero;
                double precio;
                int stock;

                cout << "Ingrese el titulo: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Ingrese el autor: ";
                getline(cin, autor);
                cout << "Ingrese el genero: ";
                getline(cin, genero);
                cout << "Ingrese el precio: ";
                cin >> precio;
                cout << "Ingrese el stock: ";
                cin >> stock;

                catalogo.agregarLibro(Libro(titulo, autor, genero, precio, stock));
                break;
            }
            case 2: {
                // Buscar libro por título
                string titulo;
                cout << "Ingrese el titulo a buscar: ";
                cin.ignore();
                getline(cin, titulo);

                catalogo.buscarPorTitulo(titulo);
                break;
            }
            case 3:
                catalogo.mostrarCatalogo();
                break;
            case 4: {
                // Registrar una compra
                string titulo;
                int cantidad;

                cout << "Ingrese el titulo del libro a comprar: ";
                cin.ignore();
                getline(cin, titulo);

                if (catalogo.libroEnCatalogo(titulo)) {
                    cout << "Ingrese la cantidad a comprar: ";
                    cin >> cantidad;

                    if (catalogo.actualizarStock(titulo, cantidad)) {
                        string descripcion = "Compra de " + to_string(cantidad) +
                                             " unidad(es) de '" + titulo + "'";
                        historial.registrarCompra(descripcion);
                        cout << "Compra registrada con exito.\n";
                    } else {
                        cout << "Stock insuficiente para la compra.\n";
                    }
                } else {
                    cout << "El libro '" << titulo
                         << "' no está en el catalogo. No se puede realizar la compra.\n";
                }
                break;
            }
            case 5:
                historial.mostrarHistorial();
                break;
            case 6:
                if (currentUser != nullptr) {
                    currentUser->mostrarCarrito();

                }
                break;
            case 7:
                if (currentUser != nullptr) {
                    string titulo;
                    cout << "Ingrese el titulo del libro a agregar al carrito: ";
                    cin.ignore();
                    getline(cin, titulo);

                    if (catalogo.libroEnCatalogo(titulo)) {
                        currentUser->agregarAlCarrito(titulo);
                    } else {
                        cout << "El libro '" << titulo
                             << "' no esta en el catálogo. No se puede agregar al "
                                "carrito.\n";
                    }

                }
                break;
            case 8:
                if (currentUser != nullptr) {
                    currentUser->vaciarCarrito();
                }
                break;
            case 9: {
                string genero;
                cout << "Ingrese el genero a buscar: ";
                cin.ignore();
                getline(cin, genero);

                catalogo.buscarPorCategoria(genero);
                break;
            }
            case 10: {
                string titulo;
                cout << "Ingrese el titulo del libro a preordenar: ";
                cin.ignore();
                getline(cin, titulo);

                catalogo.preordenarLibro(titulo);
                break;
            }
            case 11:
                cout << "Cerrando sesion del usuario actual...\n";
                currentUser = nullptr;
                break;
            case 12:
                cout << "Saliendo del programa...\n";
                return 0; // Termina el programa
            default:
                cout << "Opción inválida. Intente de nuevo.\n";
            }
        } while (opcion != 11 && opcion != 12);
    }

    return 0;
}
