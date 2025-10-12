#pragma once

template <typename T>
class NodoDoble
{
public:
	T valor;
	NodoDoble<T>* siguiente;
	NodoDoble<T>* anterior;

public:
	NodoDoble(T val)
	{
		valor = val;
		siguiente = nullptr;
		anterior = nullptr;
	}
};