#pragma once

#include <string>
#include "sucursal.h"

using namespace std;

class Evento {
    private: 
        string fechaHora;
        Sucursal sucursal;
        string estado;
        string observacion;
};