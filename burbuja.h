#include <iostream>
#include "ordenamiento.h"

using namespace std;

template <typename T>
class Burbuja : public Ordenamiento<T>
{
    // void ordenar(Lista<T> datos, cmp : (T, T)->int) {
    void ordenar(Lista<T> datos, function<int(T &, T &)> cmp) override
    {
        T a[] = {};
        datos.convertirAArreglo(a);

        bool ordenado;

        for (int i = 0; i < datos.getTamano(); i++)
        {
            ordenado = true;

            for (int j = 0; j < datos.getTamano() - (i + 1); j++)
            {
                // T aux = datos.getPosicion(j);
                // T aux = a[j];
                // a[j] = a[j + 1];
                // a[j + 1] = aux;
                // int index = cmp(a[j], a[j + 1]);

                // ordenado = index <= 0 ? true : false;
                // if (a[j] > a[j + 1])
                // {
                //     int aux = a[j];
                //     a[j] = a[j + 1];
                //     a[j + 1] = aux;
                //     ordenado = false;
                // }
            }

            if (ordenado)
                break;
        }
    }
};