#include "ItemFactura.h"

ItemFactura::ItemFactura(std::string descripcion, int cantidad, double precioUnitario)
    : descripcion(std::move(descripcion)), cantidad(cantidad), precioUnitario(precioUnitario) {}

std::string ItemFactura::getDescripcion() const {
    return descripcion;
}

int ItemFactura::getCantidad() const {
    return cantidad;
}

double ItemFactura::getPrecioUnitario() const {
    return precioUnitario;
}

void ItemFactura::setDescripcion(const std::string& descripcion) {
    this->descripcion = descripcion;
}

void ItemFactura::setCantidad(int cantidad) {
    this->cantidad = cantidad;
}

void ItemFactura::setPrecioUnitario(double precioUnitario) {
    this->precioUnitario = precioUnitario;
}

double ItemFactura::calcularTotal() const {
    return cantidad * precioUnitario;
}
