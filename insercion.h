#pragma once

#include "ordenamiento.h"

using namespace std;

template <typename T>
class Insercion : public Ordenamiento<T>
{
	void ordenar(T datos[], int n, function<int(T, T)> cmp) override
	{
		T aux;
		int k;

		for (int i = 1; i < n; i++)
		{
			aux = datos[i];
			k = i - 1;

			while (k >= 0 && cmp(aux, datos[k]) < 0)
			{
				datos[k + 1] = datos[k];
				k--;
			}

			datos[k + 1] = aux;
		}
	}
};