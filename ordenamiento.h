#pragma once
#include "lista.h"

template <typename T>
class Ordenamiento
{
public:
    // void ordenar(Lista<T> datos, cmp : (T, T)->int);
    virtual void ordenar(Lista<T> datos, function<int(T&, T&)> cmp) = 0;
};