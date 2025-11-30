#pragma once

#include <functional>

#include "encomienda.h"
#include "ordenamiento.h"
#include "gestor_encomiendas.h"
#include "gestor_clientes.h"
#include "gestor_sucursales.h"
#include "lista_doble.h"
#include "mergesort.h"
#include "burbuja.h"
#include "Dijkstra.h"

using namespace std;

class GestorEnvios
{
private:
	GestorEncomiendas gestorEncomiendas;
	GestorClientes gestorCliente;
	GestorSucursales gestorSucursal;

public:	
	/*void listarOrdenado(function<int(Encomienda, Encomienda)> cmp, Ordenamiento<Encomienda>& est);*/
	void listarOrdenado();
	void buscarEncomiendaPorCodigo(string codigo);
	void crearEncomienda(string remitenteDni, string destinatarioDni, string sucursalOrigen, string sucursalDestino, string servicio, double montoPago);
	
	void imprimir(Encomienda encomiendas[], int q);
};
