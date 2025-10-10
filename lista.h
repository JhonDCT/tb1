#pragma once
#include "nodo.h"

template <typename T>
class Lista
{
private:
    Nodo<T> *cabeza;
    int tamano;

public:
    Lista() : cabeza(nullptr), tamano(0) {}
    ~Lista() { limpiarNodos(); }

    void limpiarNodos()
    {
        // Nodo<T> actual = cabeza;
        // while (actual->getSiguiente())
        // {
        //     Nodo<T> temporal = actual->getSiguiente();

        //     actual = temporal;
        // }

        // cabeza = nullptr;
        // tamano = 0;
    }

    void insertarInicio(T item)
    {
        Nodo<T>* nuevo = new Nodo<T>(item, cabeza);
        if (nuevo != nullptr)
        {
            cabeza = nuevo;
            tamano++;
        }

        // Nodo<T> *actual = cabeza;
        // while (actual->getSiguiente())
        // {
        //     actual = actual->getSiguiente();
        // }

        // actual->setSiguiente(nodo);
    }

    void convertirAArreglo(T *arreglo = nullptr)
    {
        Nodo<T> *actual = cabeza;
        int indice = 0;

        while (actual)
        {
            arreglo[indice] = actual->getValor();
            actual = actual->getSiguiente();
            indice++;
        }
    }

    int getTamano() { return tamano; }

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