#pragma once

#include "ordenamiento.h"

using namespace std;

template <typename T>
class Seleccion : public Ordenamiento<T>
{
	void ordenar(T datos[], int n, function<int(T, T)> cmp) override
	{
		int k;
		T menor;

		for (int i = 0; i < n - 1; i++)
		{
			k = i;
			menor = datos[i];

			for (int j = i + 1; j < n; j++)
			{
				if (cmp(datos[j], menor) < 0) {
					menor = datos[j];
					k = j;
				}
			}

			datos[k] = datos[i];
			datos[i] = menor;
		}
	}
};