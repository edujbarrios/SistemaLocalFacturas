#ifndef GESTORFACTURAS_H
#define GESTORFACTURAS_H

#include "../Factura/Factura.h"
#include <map>

class GestorFacturas {
private:
    static GestorFacturas* instance;
    std::map<int, Factura> facturas;
    int nextFacturaId;

    // Constructor privado para el patrón Singleton
    GestorFacturas();

public:
    // Eliminar la posibilidad de copia
    GestorFacturas(const GestorFacturas&) = delete;
    void operator=(const GestorFacturas&) = delete;

    static GestorFacturas* getInstance();

    Factura& crearFactura(const Cliente& cliente);
    void agregarItemAFactura(int idFactura, const ItemFactura& item);
    void imprimirFactura(int idFactura) const;
};

#endif // GESTORFACTURAS_H
