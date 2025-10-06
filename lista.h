#include "nodo.h"

template <typename T>
class Lista {
    private: 
        Nodo<T> cabeza;
        int tamano;

    public: 
        void insertarInicio(T item);
        void insertarFin(T item);
        void insertarEn(T item, int posicion);
        void eliminarEn(int posicion);
        T buscar((T)-> bool predicado);
        void forEarch((T)-> void accion);
        void ordenar(Lista datos);
        Lista<U> map((T)-> U predicado);
        Lista<T> filter((T)-> bool predicado);
        U reduce(U valorInicial, (U, T)-> U predicado);
};