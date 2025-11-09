#pragma once

#include "lista.h"
#include "seguimiento.h"

class GestorSeguimiento
{
public:
	Lista<Seguimiento> listar();

	void agregar(string codigo);
};