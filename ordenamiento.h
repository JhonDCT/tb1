#pragma once
#include "lista.h"

template <typename T>
class Ordenamiento
{
    // void ordenar(Lista<T> datos, cmp : (T, T)->int);
    void ordenar(Lista<T> datos, function<int(T&, T&)> cmp);
};