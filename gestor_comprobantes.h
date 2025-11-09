#pragma once

#include "comprobante.h"
#include "pila.h"

class GestorComprobante {
	public:
		Pila<Comprobante> comprobantes;

		void agregar();
		void eliminar();
		// TODO: implementar peek
		void peek();
};