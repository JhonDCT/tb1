#include "gestor_rutas.h"

GestorRutas::GestorRutas()
{
	this->sucursales = gestorSucursales.obtenerSucursales();
	this->agregarNodos();
	this->cargarArcos();
};

void GestorRutas::agregarNodos()
{
	int etiquetaCounter = 0;

	for (auto& suc : sucursales) {
		idToEtiqueta[suc.getId()] = etiquetaCounter;
		Ciudad* ciudad = new Ciudad(etiquetaCounter, 0, 0, suc, suc.getNombre());
		dijkstra.agregarNodo(ciudad);
		etiquetaCounter++;
	}
}

void GestorRutas::cargarArcos()
{
	string ruta = "rutas.txt";

	ifstream fichero;
	fichero.open(ruta);

	if (!fichero.is_open())
	{
		cout << "No se puede abrir el archivo" << ruta << endl;
	}

	string linea;
	while (getline(fichero, linea)) {
		if (linea.empty())
			continue;

		vector<string> campos;
		istringstream ss(linea);
		string campo;

		while (getline(ss, campo, ';'))
		{
			campos.push_back(campo);
		}

		string origenId = campos[0];
		string destinoId = campos[1];
		string distStr = campos[2];
		int tiempo = stoi(campos[3]);

		if (idToEtiqueta.count(origenId) && idToEtiqueta.count(destinoId)) {
			int origen = idToEtiqueta[origenId];
			int destino = idToEtiqueta[destinoId];
			int peso = stoi(distStr);

			dijkstra.agregarArco(origen, destino, tiempo, peso);
		}
	}

	fichero.close();
}

void GestorRutas::calcularRuta(Sucursal origen, Sucursal destino)
{
	if (idToEtiqueta.count(origen.getId()) && idToEtiqueta.count(destino.getId())) {
		int origenEtiqueta = idToEtiqueta[origen.getId()];
		int destinoEtiqueta = idToEtiqueta[destino.getId()];

		cout << "\n[+] Calculando ruta optima desde " << origen.getNombre() << " a " << destino.getNombre() << "...\n";
		dijkstra.buscarRuta(origenEtiqueta, destinoEtiqueta);
	}
	else {
		cout << "\n[!] Sucursales no encontradas en el grafo.\n";
	}
}