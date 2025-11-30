#pragma once

#include <functional>
#include <list>

template<typename T>
class TablaHash {
private:
	int tamano;
	vector<list<T>> tabla;

public:
	TablaHash(int _tamano = 10) {
		tabla.resize(_tamano);
		tamano = _tamano;
	}

	int hash(string id)
	{
		int suma = 0;
		for (char c : id)
		{
			suma += c;
		}

		return suma % tamano;
	}

	void insertar(T t, string id)
	{
		int pos = hash(id);
		tabla[pos].push_back(t);
	}

	T buscar(function<bool(T&)> cmp, string id)
	{
		int pos = hash(id);
		for (T i : tabla[pos])
		{
			if (cmp(i))
			{
				return i; 
			}
		}

		throw std::runtime_error("No se encontro el elemento");
	}

	vector<T> obtenerTodos()
	{
		vector<T> todos;
		for (const auto& lista : tabla)
		{
			for (const auto& item : lista)
			{
				todos.push_back(item);
			}
		}
		return todos;
	}
};
