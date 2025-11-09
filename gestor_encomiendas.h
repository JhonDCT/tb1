#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "encomienda.h"
#include "lista_doble.h"

using namespace std;

class GestorEncomiendas
{
private:
	ListaDoble<Encomienda> encomiendas;
	string ruta;

public:
	GestorEncomiendas() {
		ruta = "encomiendas.txt";
		encomiendas = listar();
	}

	ListaDoble<Encomienda> getEncomiendas() {
		return encomiendas;
	}

	string crear(
		Cliente remitente,
		Cliente destinatario,
		Sucursal origen,
		Sucursal destino,
		Servicio servicio,
		Pago pago,
		Vehiculo vehiculo,
		Repartidor repartidor,
		Ruta ruta
	);
	void eliminar(string codigo);
	ListaDoble<Encomienda> listar();
	Encomienda buscarPorCodigo(string codigo);
};