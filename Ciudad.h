#pragma once

#include "sucursal.h"

class Ciudad {
private:
	int etiqueta;
	int longitud;
	int latitud;
	string nombre;
	Sucursal sucursal;
public:
	Ciudad(int _etiqueta, int lon, int lat, Sucursal suc, string _nombre) {
		etiqueta = _etiqueta;
		longitud = lon;
		latitud = lat;
		sucursal = suc;
		nombre = _nombre;
	}

	int getEtiqueta() { return etiqueta; }
	string getNombre() { return nombre; }

	bool igual(int e) { return etiqueta = e; }
};