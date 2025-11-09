#pragma once

#include <functional>

#include "nodo-arbol.h"

template <typename T>
class ArbolBinario {
public:
	NodoArbol<T>* raiz;

	ArbolBinario() {
		raiz = nullptr;
	}

private:
	NodoArbol<T>* insertar(NodoArbol<T>* nodo, T valor, function<int(T&, T&)> cmp) {
		if (nodo == nullptr) {
			return new NodoArbol<T>(valor);
		}

		//if (valor < nodo->valor) {
		if (cmp(valor, nodo->valor) < 0) {
			nodo->izquierdo = insertar(nodo->izquierdo, valor, cmp);
		}

		//if (valor > nodo->valor) {
		if (cmp(valor, nodo->valor) > 0) {
			nodo->derecho = insertar(nodo->derecho, valor, cmp);
		}

		return nodo;
	}

	//NodoArbol<T>* buscar(NodoArbol<T>* nodo, T valor, function<bool(T&, T&)> cmp) {
	NodoArbol<T>* buscar(NodoArbol<T>* nodo, function<int(T&)> cmp) {
		if (nodo == nullptr) {
			return nullptr;
		}

		//if (valor == nodo->dato)
		if (cmp(nodo->valor) == 1) {
			return nodo;
		}
		//else if (valor < nodo->dato)
		else if (cmp(nodo->valor) < 0) {
			return buscar(nodo->izquierdo, cmp);
		}
		else {
			return buscar(nodo->derecho, cmp);
		}
	}

public:
	void insertarNodo(T valor, function<int(T&, T&)> cmp) {
		raiz = insertar(raiz, valor, cmp);
	}

	//NodoArbol<T>* buscarNodo(T valor, function<bool(T&, T&)> cmp) {
	NodoArbol<T>* buscarNodo(function<int(T&)> cmp) {
		return buscar(raiz, cmp);
	}
};