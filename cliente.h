#pragma once 

#include <string>

using namespace std;

class Cliente
{
private:
    string id;
    string dni;
    string nombre;
    string telefono;
    string email;

public:
    Cliente() {}

    void setId(string i) { id = i; }
    void setDniRuc(string dni) { dni = dni; }
    void setNombre(string nom) { nombre = nom; }
    void setTelefono(string tel) { telefono = tel; }
    void setEmail(string ema) { email = ema; }

    string getId() { return id; }    
    string getDni() { return dni; }
	string getNombre() { return nombre; }
    string getTelefono() { return id; }
    string getEmail() { return id; }

    bool validar();
};