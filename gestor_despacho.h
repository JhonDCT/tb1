#pragma once

#include "cola.h"

class GestorDespacho {
public:
	Cola despacho;

	void agregar();
	void eliminar();
};