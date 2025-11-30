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

	void buscarRuta(int origenEtiqueta)
	{
		int origen = buscaIndice(origenEtiqueta);
		if (origen == -1)
		{
			cout << "Nodo origen no encontrado ! " << endl;

			return;
		}

		int INF = 9999999;
		int distancias[MAX_NODOS];
		bool visitados[MAX_NODOS];
		int predecesores[MAX_NODOS];

		for (int i = 0; i < cantidad; i++)
		{
			distancias[i] = INF;
			visitados[i] = false;
			predecesores[i] = -1;
		}

		distancias[origen] = 0;

		for (int i = 0; i < cantidad; i++)
		{
			int actual = -1; 
			int menorDistancia = INF;

			for (int i = 0; i < cantidad; i++)
			{
				if (!visitados[i] && distancias[i] < menorDistancia)
				{
					menorDistancia = distancias[i];
					actual = i;
				}
			}

			if (actual == -1) break;

			visitados[actual] = true;

			for (int i = 0; i < adyancencia[actual].size(); i++)
			{
				int etiquetaDestino = adyancencia[actual][i].getDestino();
				int vecino = buscaIndice(etiquetaDestino);
				int peso = adyancencia[actual][i].getDistancia();

				if (!visitados[vecino] && distancias[actual] + peso < distancias[vecino])
				{
					distancias[vecino] = distancias[actual] + peso;
					predecesores[vecino] = actual;
				}
			}
		}

		for (int i = 0; i < cantidad; i++)
		{
			if (distancias[i] == INF)
			{
				cout << "Nodo no alcanzable";
			}
			else
			{
				cout << "Distancia : " << distancias[i] << ", camino : ";
				mostrarCamino(i, predecesores);
				cout << endl;
			}
		}
	}

	// TODO: Regresar la cantidad de km que va a recorrer la ruta
	void mostrarCamino(int i, int predecesores[])
	{
		if (i == -1) return;

		mostrarCamino(predecesores[i], predecesores);

		cout << nodos[i]->getEtiqueta();

		if (predecesores[i] != -1)
		{
			cout << " -> ";
		}

	}
};