#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "cliente.h"
#include "lista_doble.h"

using namespace std;

class GestorClientes
{
public:    
    ListaDoble<Cliente> listar();
    Cliente buscarPorDni(string dni);
};