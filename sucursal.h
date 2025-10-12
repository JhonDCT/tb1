#pragma once

#include "direccion.h"

class Sucursal
{
private:
    string id;
    string nombre;
    Direccion direccion;
    string telefono;

public:
    Sucursal() {}

    void setId(string i) { id = i; }
    void setNombre(string n) { nombre = n; }
    void setDireccion(Direccion d) { direccion = d; }
    void setTelefono(string t) { telefono = t; }

    string getNombre() { return nombre; }
    string getId() { return id; }

    int capacidad();
};