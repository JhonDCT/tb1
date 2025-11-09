#include "ordenamiento.h"

template <typename T>
class MergeSort : public Ordenamiento<T>
{
public:
	void ordenar(T A[], int n, function<int(T, T)> cmp)
	{
		if (n > 1)
		{
			int mitad = n / 2;
			T* A1 = new T[mitad];
			T* A2 = new T[n - mitad];

			for (int i = 0; i < mitad; i++)
			{
				A1[i] = A[i];
			}

			for (int i = mitad; i < n; i++)
			{
				A2[i - mitad] = A[i];
			}

			ordenar(A1, mitad, cmp);
			ordenar(A2, n - mitad, cmp);

			merge(A1, A2, A, n, cmp);
		}

	}

	void merge(T* A1, T* A2, T A[], int n, function<int(T, T)> cmp)
	{
		int i = 0, j = 0, k = 0;
		int mitad = n / 2;

		while (i < mitad && j < n - mitad)
		{
			if (cmp(A1[i], A2[j]) < 0) {
				A[k] = A1[i];
				i++;
				k++;
			}
			else
			{
				A[k] = A2[j];
				j++;
				k++;
			}
		}

		while (i < mitad)
		{
			A[k] = A1[i];
			i++;
			k++;
		}

		while (j < n - mitad)
		{
			A[k] = A2[j];
			j++;
			k++;
		}
	}
};