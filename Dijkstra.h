#pragma once

#include "functional"
#include "vector"
#include "iostream"
#include "arista.h"
#include "ciudad.h"

#define MAX_NODOS 100

using namespace std;


class Dijkstra {
private:
	Ciudad* nodos[MAX_NODOS];
	vector<Arista> adyancencia[MAX_NODOS];
	int cantidad;

public:
	Dijkstra()
	{
		cantidad = 0;
	}

	void agregarNodo(Ciudad* nodo)
	{
		if (cantidad < MAX_NODOS) {
			nodos[cantidad++] = nodo;
		}
	}

	int buscaIndice(int etiqueta)
	{
		for (int i = 0; i < cantidad; i++)
		{
			if (nodos[i]->igual(etiqueta))
			{
				return i;
			}
		}

		return -1;
	}

	void agregarArco(int origen, int destino, int t, int d)
	{
		int i = buscaIndice(origen);

		if (i != -1)
		{
			adyancencia[i].push_back(Arista(destino, t, d));
		}
	}

	void buscarRuta(int origenEtiqueta, int destinoEtiqueta)
	{
		int origen = buscaIndice(origenEtiqueta);
		int destino = buscaIndice(destinoEtiqueta);

		if (origen == -1)
		{
			cout << "Nodo origen no encontrado ! " << endl;
			return;
		}

		if (destino == -1)
		{
			cout << "Nodo destino no encontrado ! " << endl;
			return;
		}

		int INF = 9999999;
		int distancias[MAX_NODOS];
		int tiempos[MAX_NODOS];
		bool visitados[MAX_NODOS];
		int predecesores[MAX_NODOS];

		for (int i = 0; i < cantidad; i++)
		{
			distancias[i] = INF;
			tiempos[i] = INF;
			visitados[i] = false;
			predecesores[i] = -1;
		}

		distancias[origen] = 0;
		tiempos[origen] = 0;

		for (int i = 0; i < cantidad; i++)
		{
			int actual = -1;
			int menorDistancia = INF;

			for (int j = 0; j < cantidad; j++)
			{
				if (!visitados[j] && distancias[j] < menorDistancia)
				{
					menorDistancia = distancias[j];
					actual = j;
				}
			}

			if (actual == -1) break;

			visitados[actual] = true;

			if (actual == destino) break;

			for (int k = 0; k < adyancencia[actual].size(); k++)
			{
				int etiquetaDestino = adyancencia[actual][k].getDestino();
				int vecino = buscaIndice(etiquetaDestino);
				int peso = adyancencia[actual][k].getDistancia();
				int tiempo = adyancencia[actual][k].getTiempo();

				if (vecino != -1 && !visitados[vecino] && distancias[actual] + peso < distancias[vecino])
				{
					distancias[vecino] = distancias[actual] + peso;
					tiempos[vecino] = tiempos[actual] + tiempo;
					predecesores[vecino] = actual;
				}
			}
		}

		if (distancias[destino] == INF)
		{
			cout << "Nodo destino no alcanzable desde el origen." << endl;
		}
		else
		{
			cout << "Distancia optima: " << distancias[destino] << " km, Ruta: ";
			mostrarCamino(destino, predecesores);
			cout << endl;
			cout << "Tiempo estimado: " << tiempos[destino] << "horas" << endl;
			cout << endl;
		}
	}

private:
	void mostrarCamino(int i, int predecesores[])
	{
		vector<string> camino;

		while (i != -1) {
			camino.push_back(nodos[i]->getNombre());
			i = predecesores[i];
		}

		for (int j = camino.size() - 1; j >= 0; --j) {
			cout << camino[j];
			if (j > 0) cout << " -> ";
		}
	}
};