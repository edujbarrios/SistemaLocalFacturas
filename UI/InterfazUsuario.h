#ifndef INTERFAZUSUARIO_H
#define INTERFAZUSUARIO_H

#include "../GestorFactura/GestorFacturas.h"

class InterfazUsuario {
public:
    void iniciar() const;
private:
    void mostrarMenuPrincipal() const;
    void procesarAccion(int opcion) const;

    void crearFactura() const;
    void agregarItemAFactura() const;
    void mostrarFactura() const;

    int leerOpcion() const;
    ItemFactura leerDatosItem() const;
    Cliente leerDatosCliente() const;
};

#endif // INTERFAZUSUARIO_H
