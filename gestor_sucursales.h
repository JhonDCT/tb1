#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "sucursal.h"
#include "lista_doble.h"
#include "tabla_hash.h"

using namespace std;

class GestorSucursales
{
public:	
	TablaHash<Sucursal> sucursales;

	GestorSucursales() {
		sucursales = listar();
	}

	TablaHash<Sucursal> listar();
	Sucursal buscarPorId(string id);
	vector<Sucursal> obtenerSucursales();
};