#pragma once

#include <fstream>
#include <sstream>
#include "Dijkstra.h"
#include "gestor_sucursales.h"
#include <map>

class GestorRutas {
	Dijkstra dijkstra;
	GestorSucursales gestorSucursales;
	map<string, int> idToEtiqueta;
	vector<Sucursal> sucursales;

public:
	GestorRutas();
	void agregarNodos();
	void cargarArcos();
	void calcularRuta(Sucursal origen, Sucursal destino);
};