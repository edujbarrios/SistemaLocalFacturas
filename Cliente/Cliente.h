#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    int id;
    std::string nombre;
    std::string direccion;

public:
    Cliente(int id, std::string nombre, std::string direccion);

    int getId() const;
    std::string getNombre() const;
    std::string getDireccion() const;

    void setId(int id);
    void setNombre(const std::string& nombre);
    void setDireccion(const std::string& direccion);
};

#endif // CLIENTE_H
