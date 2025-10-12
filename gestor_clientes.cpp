#include "gestor_clientes.h"

ListaDoble<Cliente> GestorClientes::listar()
{
	ListaDoble<Cliente> clientes;
	string ruta = "clientes.txt";

	ifstream fichero;
	fichero.open(ruta);

	if (!fichero.is_open())
	{
		cout << "No se puede abrir el archivo" << ruta << endl;
	}

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
		cliente.setDniRuc(campos[1]);
		cliente.setNombre(campos[2]);
		cliente.setTelefono(campos[3]);
		cliente.setEmail(campos[4]);


		clientes.insertarInicio(cliente);
	}

	fichero.close();

	return clientes;
}

Cliente GestorClientes::buscarPorDni(string dni)
{
	ListaDoble<Cliente> clientes = listar();

	auto comparadorPorDni = [dni](Cliente c) {
		if (c.getDni() == dni) return true;

		return false;
		};

	return clientes.buscar(comparadorPorDni);
}