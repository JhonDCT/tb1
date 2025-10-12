#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "sucursal.h"
#include "lista_doble.h"

using namespace std;

class GestorSucursales
{
public:
	ListaDoble<Sucursal> listar();
	Sucursal buscarPorId(string id);
};