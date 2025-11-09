#pragma once

#include <iostream>

#include "gestor_envios.h"
#include "ordenamiento.h"
#include "burbuja.h"
#include "insercion.h"
#include "seleccion.h"
#include "intercambio.h"
#include "mergesort.h"

using namespace std;

class Consola
{
private:
    GestorEnvios gestorEnvios;
    GestorEncomiendas gestorEncomiendas;
	GestorClientes gestorClientes;

public:
    void mostrarMenu();

    void insertarCliente(string dni, string nombre, string telefono, string email);
    void buscarCliente();

    void crearEncomienda();
	void eliminarEncomienda();
    void listarEncomiendas();
    void buscarEncomiendaPorCodigo();
    

};