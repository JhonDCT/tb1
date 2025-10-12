#pragma once

#include <iostream>

#include "gestor_envios.h"
#include "ordenamiento.h"
#include "burbuja.h"
#include "insercion.h"
#include "seleccion.h"
#include "intercambio.h"

using namespace std;

class Consola
{
private:
    GestorEnvios gestorEnvios;
    GestorEncomiendas gestorEncomiendas;

public:
    void mostrarMenu();
    void listarEncomiendas();
    void buscarEncomiendaPorCodigo();
    void crearEncomienda();
};