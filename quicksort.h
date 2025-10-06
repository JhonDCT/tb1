#include "ordenamiento.h"

template <typename T>
class QuickSort : public Ordenamiento<T>
{
    void ordenar(Lista<T> datos, cmp : (T, T)->int) {
        cout << "Ordenando con QuickSort" << endl;
    }
};