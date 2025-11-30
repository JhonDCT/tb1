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
	GestorSucursales gestorSucursales;

public:
    void mostrarMenu();

    void buscarCliente();
    void crearEncomienda();
    void listarEncomiendas();
    void buscarEncomiendaPorCodigo();

    void registrarCliente();
	void actualizarEstadoEncomienda();
    void calcularTarifa();


private:
    void limpiarPantalla();
    void pausar();
    void mostrarEncabezado(string titulo);
    void mostrarLogo();
};