#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <sstream>
#include "encomienda.h"
#include "cliente.h"
#include "sucursal.h"

using namespace std;

class GestorEncomiendas
{
public:
    Lista<Encomienda> listar();
};