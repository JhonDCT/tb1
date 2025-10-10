#pragma once

template <typename T>
class Nodo
{
private:
    T valor;
    Nodo<T>* siguiente;

public:
    Nodo(T val)
    {
        valor = val;
        siguiente = nullptr;
    }

    Nodo(T val, Nodo<T>* sig)
    {
        valor = val;
        siguiente = sig;
    }


    Nodo<T> *getSiguiente() { return siguiente; }
    void setSiguiente(Nodo<T> *sig) { siguiente = sig; }

    T getValor() { return valor; }
};