#pragma once

template <typename T>
class Nodo
{
private:
    T valor;
    unique_ptr<Nodo<T>> siguiente;

public:
    Nodo(T v) : valor(v), siguiente(nullptr) {}
};