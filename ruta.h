#pragma once

#include <string>
#include "sucursal.h"

using namespace std;

class Ruta
{
private:
    string id;
    Sucursal origen;
    Sucursal destino;
    double km;

public:
    double estimadoHoras();
};