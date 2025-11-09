#pragma once

#include <functional>

#include "nodo_doble.h"

template <typename T>
class ListaDoble
{
private:
	NodoDoble<T>* cabeza;
	NodoDoble<T>* cola;
	int tamano;

public:
	ListaDoble() {
		cabeza = nullptr;
		cola = nullptr;
		tamano = 0;
	}

	~ListaDoble() { limpiarNodos(); }

	void limpiarNodos()
	{
	}

	void insertarInicio(T item)
	{
		NodoDoble<T>* nuevo = new NodoDoble<T>(item);
		if (nuevo != nullptr)
		{
			if (cabeza == nullptr)
			{
				cabeza = nuevo;
				cola = nuevo;
			}
			else
			{
				nuevo->siguiente = cabeza;
				cabeza->anterior = nuevo;
				cabeza = nuevo;
			}

			tamano++;
		}
	}

	T* convertirAArreglo(T* arreglo = nullptr)
	{
		if (arreglo == nullptr)
		{
			arreglo = new T[tamano];
		}

		NodoDoble<T>* actual = cabeza;
		int indice = 0;
		while (actual)
		{
			arreglo[indice] = actual->valor;
			actual = actual->siguiente;
			indice++;
		}

		return arreglo;
	}

	int getTamano() { return tamano; }

	T buscar(function<bool(T)> cmp) {
		NodoDoble<T>* actual = cabeza;

		while (actual) {
			if (cmp(actual->valor)) {
				return actual->valor;
			}

			actual = actual->siguiente;
		}

		throw runtime_error("No se encontro el elemento");
	}

	//void insertarFin(T item) {}

	//void insertarEn(T item, int posicion) {}

	//void eliminarEn(int posicion) {}

	//NodoDoble<T>* getCabeza() { return cabeza; }
	//void setCabeza(NodoDoble<T>* nodo) { cabeza = nodo; }

	// T buscar((T)->bool predicado);
	// void forEarch((T)->void accion);
	// void ordenar(Lista datos);
	// Lista<U> map((T)->U predicado);
	// Lista<T> filter((T)->bool predicado);
	// U reduce(U valorInicial, (U, T)->U predicado);
};
