#include "cliente.h"

bool Cliente::validar()
{
    //return !id.empty() && !dni.empty() && !nombre.empty();

    return false;
}

void Cliente::imprimir()
{
    cout << "---------------------------------\n";
    cout << " ID:       " << id << endl;
    cout << " DNI:      " << dni << endl;
    cout << " Nombre:   " << nombre << endl;
    cout << " Telefono: " << telefono << endl;
    cout << " Email:    " << email << endl;
    cout << "---------------------------------\n";
}