#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "cliente.h"
#include "arbol_binario.h"

using namespace std;

class GestorClientes
{
public:
	ArbolBinario<Cliente> clientes;

	GestorClientes() {
		clientes = listar();
	}

	ArbolBinario<Cliente> listar();
	Cliente buscarPorDni(string dni);
	void insertar(string dni, string nombre, string telefono, string email); // en el documento y en el arbol
};