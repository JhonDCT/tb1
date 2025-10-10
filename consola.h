#pragma once

#include <iostream>

#include "gestor_envios.h"
#include "ordenamiento.h"
#include "burbuja.h"

using namespace std;

class Consola
{
private:
    GestorEnvios gestorEnvios;

public:
    void mostrarMenu();
    void listarEncomiendas();
};