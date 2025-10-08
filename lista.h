#pragma once
#include "nodo.h"

template <typename T>
class Lista
{
private:
    Nodo<T> cabeza;
    int tamano;

public:
    Lista() : cabeza(nullptr), tamano(0) {}
    ~Lista() { limpiarNodos(); }

    void limpiarNodos()
    {
        Nodo<T> actual = cabeza;
        while (actual)
        {
            Nodo<T> temporal = actual->siguiente();

            actual = temporal;
        }

        cabeza = nullptr;
        tamano = 0;
    }

    void insertarInicio(T item)
    {
        Nodo<T> nodo = new Nodo<T>(item);
        nodo->siguiente = cabeza;
        cabeza = nodo ;
        tamano++;
    }

    void insertarFin(T item) {}

    void insertarEn(T item, int posicion) {}

    void eliminarEn(int posicion) {}

    // T buscar((T)->bool predicado);
    // void forEarch((T)->void accion);
    // void ordenar(Lista datos);
    // Lista<U> map((T)->U predicado);
    // Lista<T> filter((T)->bool predicado);
    // U reduce(U valorInicial, (U, T)->U predicado);
};