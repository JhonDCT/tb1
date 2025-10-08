#include <iostream>
#include "ordenamiento.h"

using namespace std;

template <typename T>
class QuickSort : public Ordenamiento<T>
{
    // void ordenar(Lista<T> datos, cmp : (T, T)->int) {
    void ordenar(Lista<T> datos, function<int(T &, T &)> cmp)
    {
        cout << "Ordenando con QuickSort" << endl;
    }
};