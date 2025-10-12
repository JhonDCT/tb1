#pragma once

#include "ordenamiento.h"

using namespace std;

template <typename T>
class Intercambio : public Ordenamiento<T>
{
	void ordenar(T datos[], int n, function<int(T, T)> cmp) override
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int k = i + 1; k < n; k++)
			{
				if (cmp(datos[i], datos[k]) > 0) {
					T aux = datos[i];
					datos[i] = datos[k];
					datos[k] = aux;
				}
			}
		}
	}
};