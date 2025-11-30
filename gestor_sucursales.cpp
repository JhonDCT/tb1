#include "gestor_sucursales.h"

TablaHash<Sucursal> GestorSucursales::listar()
{
	string ruta = "sucursales.txt";

	ifstream fichero;
	fichero.open(ruta);

	if (!fichero.is_open())
	{
		cout << "No se puede abrir el archivo" << ruta << endl;
	}

	vector<Sucursal> sucursalesVector;

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

		sucursalesVector.push_back(sucursal);
	}

	fichero.close();

	TablaHash<Sucursal> sucursalesTmp(sucursalesVector.size());
	for (auto& sucursal : sucursalesVector)
	{
		sucursalesTmp.insertar(sucursal, sucursal.getId());
	}

	return sucursalesTmp;
}

Sucursal GestorSucursales::buscarPorId(string id)
{
	auto comparadorPorId = [id](Sucursal s) {
		cout << s.getId() << endl;
		if (s.getId() == id) return true;

		return false;
		};

	return sucursales.buscar(comparadorPorId, id);
}

vector<Sucursal> GestorSucursales::obtenerSucursales()
{
	return sucursales.obtenerTodos();
}