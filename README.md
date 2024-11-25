# Libreria

Juliana Valencia Cataño y Paulina Velasquez Londoño


Este proyecto implementa un sistema básico de gestión de un catálogo de libros. Permite a los usuarios registrar cuentas, buscar libros, realizar compras, gestionar carritos y mantener un historial de compras. Está escrito en C++ y utiliza clases y estructuras de datos estándar (Tabla hash) para implementar sus funcionalidades.

El proyecto contiene los siguientes archivos:

main.cpp: Archivo principal que contiene la lógica del menú y el flujo del programa.
Libro.h: Define la clase Libro con los atributos básicos de un libro.
Catalogo.h: Define la clase Catalogo, que gestiona los libros.
Usuario.h: Define la clase Usuario, que representa a un cliente y su carrito.
Historial.h: Define la clase Historial, que almacena las compras realizadas por los usuarios.
Al iniciar el programa, el sistema pedirá que te registres o inicies sesión.
Una vez dentro, puedes interactuar con el menú para:
Buscar libros en el catálogo.
Agregar libros al carrito.
Realizar compras o gestionar preórdenes.
El historial y el carrito son específicos de cada usuario.
Como ejecutarlo
1. Compilar:
g++ main.cpp -o test
2. Correr
./test
