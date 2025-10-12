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
    Ruta() {
        id = "";
		km = 0.0;
    }

    void setId(string i) { id = i; }
    void setOrigen(Sucursal o) { origen = o; }
    void setDestino(Sucursal d) { destino = d; }
    void setKm(double k) { km = k; }

    double estimadoHoras();
};