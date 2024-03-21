#include "InterfazUsuario.h"
#include <iostream>

void InterfazUsuario::iniciar() const {
    int opcion;
    do {
        mostrarMenuPrincipal();
        opcion = leerOpcion();
        procesarAccion(opcion);
    } while (opcion != 0);
}

void InterfazUsuario::mostrarMenuPrincipal() const {
    std::cout << "\nSistema de Gestión de Facturas\n";
    std::cout << "1. Crear nueva factura\n";
    std::cout << "2. Agregar ítem a factura\n";
    std::cout << "3. Mostrar factura\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void InterfazUsuario::procesarAccion(int opcion) const {
    switch (opcion) {
        case 1:
            crearFactura();
            break;
        case 2:
            agregarItemAFactura();
            break;
        case 3:
            mostrarFactura();
            break;
        case 0:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
    }
}

void InterfazUsuario::crearFactura() const {
    Cliente cliente = leerDatosCliente();
    Factura& factura = GestorFacturas::getInstance()->crearFactura(cliente);
    std::cout << "Factura creada con ID: " << factura.getIdFactura() << "\n";
}

void InterfazUsuario::agregarItemAFactura() const {
    int idFactura;
    std::cout << "Ingrese el ID de la factura a la cual agregar el ítem: ";
    std::cin >> idFactura;
    ItemFactura item = leerDatosItem();
    GestorFacturas::getInstance()->agregarItemAFactura(idFactura, item);
}

void InterfazUsuario::mostrarFactura() const {
    int idFactura;
    std::cout << "Ingrese el ID de la factura a mostrar: ";
    std::cin >> idFactura;
    GestorFacturas::getInstance()->imprimirFactura(idFactura);
}

int InterfazUsuario::leerOpcion() const {
    int opcion;
    std::cin >> opcion;
    return opcion;
}

ItemFactura InterfazUsuario::leerDatosItem() const {
    std::string descripcion;
    int cantidad;
    double precio;
    std::cin.ignore(); // Ignora el '\n' del último ingreso
    std::cout << "Ingrese descripción del ítem: ";
    std::getline(std::cin, descripcion);
    std::cout << "Ingrese cantidad: ";
    std::cin >> cantidad;
    std::cout << "Ingrese precio unitario: ";
    std::cin >> precio;
    return ItemFactura(descripcion, cantidad, precio);
}

Cliente InterfazUsuario::leerDatosCliente() const {
    int id;
    std::string nombre, direccion;
    std::cin.ignore(); // Ignora el '\n' del último ingreso
    std::cout << "Ingrese ID del cliente: ";
    std::cin >> id;
    std::cin.ignore(); // Ignora el '\n' del último ingreso
    std::cout << "Ingrese nombre del cliente: ";
    std::getline(std::cin, nombre);
    std::cout << "Ingrese dirección del cliente: ";
    std::getline(std::cin, direccion);
    return Cliente(id, nombre, direccion);
}
