#pragma once

template <typename T>
class NodoArbol {
public:
	T valor;
	NodoArbol* izquierdo;
	NodoArbol* derecho;

	NodoArbol(T val)
	{
		valor = val;
		izquierdo = nullptr;
		derecho = nullptr;
	}
};