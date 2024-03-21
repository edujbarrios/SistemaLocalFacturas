#include "GestorFacturas.h"
#include <iostream>

GestorFacturas* GestorFacturas::instance = nullptr;

GestorFacturas::GestorFacturas() : nextFacturaId(1) {}

GestorFacturas* GestorFacturas::getInstance() {
    if (instance == nullptr) {
        instance = new GestorFacturas();
    }
    return instance;
}

Factura& GestorFacturas::crearFactura(const Cliente& cliente) {
    Factura nuevaFactura(nextFacturaId++, cliente);
    facturas.insert(std::make_pair(nuevaFactura.getIdFactura(), nuevaFactura));
    return facturas[nuevaFactura.getIdFactura()];
}

void GestorFacturas::agregarItemAFactura(int idFactura, const ItemFactura& item) {
    if (facturas.find(idFactura) != facturas.end()) {
        facturas[idFactura].agregarItem(item);
    } else {
        std::cerr << "Factura no encontrada.\n";
    }
}

void GestorFacturas::imprimirFactura(int idFactura) const {
    if (facturas.find(idFactura) != facturas.end()) {
        facturas.at(idFactura).imprimirFactura();
    } else {
        std::cerr << "Factura no encontrada.\n";
    }
}
