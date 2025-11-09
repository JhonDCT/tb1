#include "gestor_clientes.h"

ArbolBinario<Cliente> GestorClientes::listar()
{
	/*ArbolBinario<Cliente> clientes;*/
	string ruta = "clientes.txt";

	ifstream fichero;
	fichero.open(ruta);

	if (!fichero.is_open())
	{
		cout << "No se puede abrir el archivo" << ruta << endl;
	}

	auto compararPorDni = [](Cliente a, Cliente b) -> int
		{
			if (stoi(a.getDni()) > stoi(b.getDni()))
				return 1;

			if (stoi(a.getDni()) < stoi(b.getDni()))
				return -1;

			return 0;
		};

	string linea;
	while (getline(fichero, linea))
	{
		if (linea.empty())
			continue;

		vector<string> campos;
		istringstream ss(linea);
		string campo;
		while (getline(ss, campo, ';'))
		{
			campos.push_back(campo);
		}

		Cliente cliente = Cliente();
		cliente.setId(campos[0]);
		cliente.setDni(campos[1]);
		cliente.setNombre(campos[2]);
		cliente.setTelefono(campos[3]);
		cliente.setEmail(campos[4]);		

		clientes.insertarNodo(cliente, compararPorDni);
	}

	fichero.close();

	return clientes;
}

Cliente GestorClientes::buscarPorDni(string dni)
{
	//clientes = listar();
	//ArbolBinario<Cliente> clientes = listar();

	auto buscadorPorDni = [dni](Cliente c) {
		if (stoi(c.getDni()) == stoi(dni))
		{
			return 1;
		}
		else if (stoi(dni) < stoi(c.getDni())) {
			return -1;
		}

		return 0;
		};

	auto nodo = clientes.buscarNodo(buscadorPorDni);

	return nodo->valor;
}