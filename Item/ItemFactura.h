#ifndef ITEMFACTURA_H
#define ITEMFACTURA_H

#include <string>

class ItemFactura {
private:
    std::string descripcion;
    int cantidad;
    double precioUnitario;

public:
    ItemFactura(std::string descripcion, int cantidad, double precioUnitario);

    std::string getDescripcion() const;
    int getCantidad() const;
    double getPrecioUnitario() const;

    void setDescripcion(const std::string& descripcion);
    void setCantidad(int cantidad);
    void setPrecioUnitario(double precioUnitario);

    double calcularTotal() const;
};

#endif // ITEMFACTURA_H
