#pragma once 

#include <string>

using namespace std;

class Cliente
{
private:
    string id;
    string dniRuc;
    string nombre;
    string telefono;
    string email;

public:
    Cliente() {}

    void setId(string i) { id = i; }
    void setDniRuc(string dni) { dniRuc = dni; }
    void setNombre(string nom) { nombre = nom; }
    void setTelefono(string tel) { telefono = tel; }
    void setEmail(string ema) { email = ema; }

    bool validar();
};