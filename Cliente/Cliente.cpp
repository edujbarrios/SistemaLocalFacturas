#include "Cliente.h"

Cliente::Cliente(int id, std::string nombre, std::string direccion)
    : id(id), nombre(std::move(nombre)), direccion(std::move(direccion)) {}

int Cliente::getId() const {
    return id;
}

std::string Cliente::getNombre() const {
    return nombre;
}

std::string Cliente::getDireccion() const {
    return direccion;
}

void Cliente::setId(int id) {
    this->id = id;
}

void Cliente::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Cliente::setDireccion(const std::string& direccion) {
    this->direccion = direccion;
}
