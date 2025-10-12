#include "gestor_sucursales.h"

ListaDoble<Sucursal> GestorSucursales::listar()
{
	ListaDoble<Sucursal> sucursales;
	string ruta = "sucursales.txt";

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

		Direccion direccionOrigen = Direccion();
		direccionOrigen.setCalle(campos[1]);
		direccionOrigen.setNumero(campos[2]);
		direccionOrigen.setDistrito(campos[3]);
		direccionOrigen.setProvincia(campos[4]);
		direccionOrigen.setDepartamento(campos[5]);
		direccionOrigen.setReferencia(campos[6]);

		Sucursal sucursal = Sucursal();
		sucursal.setId(campos[0]);
		sucursal.setNombre(campos[7]);
		sucursal.setTelefono(campos[8]);
		sucursal.setDireccion(direccionOrigen);

		sucursales.insertarInicio(sucursal);
	}

	fichero.close();

	return sucursales;
}

Sucursal GestorSucursales::buscarPorId(string id)
{
	ListaDoble<Sucursal> sucursales = listar();

	auto comparadorPorId = [id](Sucursal s) {
		if (s.getId() == id) return true;

		return false;
		};

	return sucursales.buscar(comparadorPorId);
}