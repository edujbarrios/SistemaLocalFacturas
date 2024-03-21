#ifndef FACTURA_H
#define FACTURA_H

#include <vector>
#include "../Cliente/Cliente.h"
#include "../Item/ItemFactura.h"

class Factura {
private:
    int idFactura;
    Cliente cliente;
    std::vector<ItemFactura> items;
    double total;

public:
    Factura(int idFactura, Cliente cliente);

    void agregarItem(const ItemFactura& item);
    double calcularTotal();
    void imprimirFactura() const;

    // Getters
    int getIdFactura() const;
    Cliente getCliente() const;
    double getTotal() const;
};

#endif // FACTURA_H
