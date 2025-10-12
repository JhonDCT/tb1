#pragma once

#include <functional>

template <typename T>
class Ordenamiento
{
public:
    virtual void ordenar(T datos[], int q, function<int(T, T)> cmp) = 0;
};