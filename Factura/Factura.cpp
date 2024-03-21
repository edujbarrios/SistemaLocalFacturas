#include "Factura.h"
#include <iostream>
#include <iomanip>

Factura::Factura(int idFactura, Cliente cliente)
    : idFactura(idFactura), cliente(cliente), total(0.0) {}

void Factura::agregarItem(const ItemFactura& item) {
    items.push_back(item);
    total += item.calcularTotal(); // Actualiza el total cada vez que se agrega un item
}

double Factura::calcularTotal() {
    double total = 0.0;
    for (const auto& item : items) {
        total += item.calcularTotal();
    }
    return total;
}

void Factura::imprimirFactura() const {
    std::cout << "Factura ID: " << idFactura << "\nCliente: " << cliente.getNombre() 
              << "\nDireccion: " << cliente.getDireccion() << "\nItems:\n";
    for (const auto& item : items) {
        std::cout << "- " << item.getDescripcion() << ", Cantidad: " << item.getCantidad() 
                  << ", Precio: " << std::fixed << std::setprecision(2) << item.getPrecioUnitario()
                  << ", Total: " << item.calcularTotal() << "\n";
    }
    std::cout << "Total Factura: " << std::fixed << std::setprecision(2) << total << "\n";
}

int Factura::getIdFactura() const {
    return idFactura;
}

Cliente Factura::getCliente() const {
    return cliente;
}

double Factura::getTotal() const {
    return total;
}
