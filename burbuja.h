#pragma once

#include "ordenamiento.h"

using namespace std;

template <typename T>
class Burbuja : public Ordenamiento<T>
{
	void ordenar(T datos[], int q, function<int(T, T)> cmp) override
	{
		bool intercambio = false;

		for (int i = 0; i < q - 1; i++)
		{
			intercambio = false;

			for (int j = 0; j < q - i - 1; j++)
			{				
				if (cmp(datos[j], datos[j + 1]) > 0) {
					swap(datos[j], datos[j + 1]);
					intercambio = true;
				}
			}

			if (!intercambio)
				break;
		}
	}
};