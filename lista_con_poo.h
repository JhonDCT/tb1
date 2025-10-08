#pragma once
#include <memory>
#include <stdexcept>
#include <functional>
#include <cstddef>

template <typename T>
class Nodo {
private:
    T valor;
    std::unique_ptr<Nodo<T>> siguiente;

    // Lista necesita acceso para manipular unique_ptr internamente.
    template<typename> friend class Lista;

public:
    explicit Nodo(const T& v) : valor(v), siguiente(nullptr) {}
    explicit Nodo(T&& v) : valor(std::move(v)), siguiente(nullptr) {}

    // acceso de solo lectura al valor (opcional)
    const T& get() const { return valor; }
    T& get() { return valor; }
};

template <typename T>
class Lista {
private:
    std::unique_ptr<Nodo<T>> cabeza; // ownership de la cadena
    Nodo<T>* cola;                   // puntero no owning para acceso rápido al final
    std::size_t len;

public:
    Lista() : cabeza(nullptr), cola(nullptr), len(0) {}
    ~Lista() = default; // unique_ptr destruye la cadena automáticamente

    bool empty() const noexcept { return len == 0; }
    std::size_t size() const noexcept { return len; }

    // insertar al inicio
    void push_front(const T& valor) {
        auto nodo = std::make_unique<Nodo<T>>(valor);
        if (!cabeza) {
            cola = nodo.get();
            cabeza = std::move(nodo);
        } else {
            nodo->siguiente = std::move(cabeza);
            cabeza = std::move(nodo);
        }
        ++len;
    }
    void push_front(T&& valor) {
        auto nodo = std::make_unique<Nodo<T>>(std::move(valor));
        if (!cabeza) {
            cola = nodo.get();
            cabeza = std::move(nodo);
        } else {
            nodo->siguiente = std::move(cabeza);
            cabeza = std::move(nodo);
        }
        ++len;
    }

    // insertar al final
    void push_back(const T& valor) {
        auto nodo = std::make_unique<Nodo<T>>(valor);
        Nodo<T>* nuevoPtr = nodo.get();
        if (!cabeza) {
            cabeza = std::move(nodo);
            cola = nuevoPtr;
        } else {
            cola->siguiente = std::move(nodo);
            cola = nuevoPtr;
        }
        ++len;
    }
    void push_back(T&& valor) {
        auto nodo = std::make_unique<Nodo<T>>(std::move(valor));
        Nodo<T>* nuevoPtr = nodo.get();
        if (!cabeza) {
            cabeza = std::move(nodo);
            cola = nuevoPtr;
        } else {
            cola->siguiente = std::move(nodo);
            cola = nuevoPtr;
        }
        ++len;
    }

    // insertar en posición (0..len). Lanza out_of_range si fuera de rango.
    void insertarEn(const T& valor, std::size_t pos) {
        if (pos > len) throw std::out_of_range("insertarEn: posicion fuera de rango");
        if (pos == 0) { push_front(valor); return; }
        if (pos == len) { push_back(valor); return; }

        Nodo<T>* cur = cabeza.get();
        for (std::size_t i = 1; i < pos; ++i) cur = cur->siguiente.get();

        auto nodo = std::make_unique<Nodo<T>>(valor);
        nodo->siguiente = std::move(cur->siguiente);
        cur->siguiente = std::move(nodo);
        ++len;
    }

    // eliminar en posición (0..len-1)
    void eliminarEn(std::size_t pos) {
        if (pos >= len) throw std::out_of_range("eliminarEn: posicion fuera de rango");
        if (pos == 0) {
            cabeza = std::move(cabeza->siguiente);
            if (!cabeza) cola = nullptr;
            --len;
            return;
        }
        Nodo<T>* cur = cabeza.get();
        for (std::size_t i = 1; i < pos; ++i) cur = cur->siguiente.get();
        // cur apunta al anterior del que vamos a borrar
        cur->siguiente = std::move(cur->siguiente->siguiente);
        if (!cur->siguiente) cola = cur;
        --len;
    }

    // buscar con predicado, devuelve puntero (nullptr si no encontró)
    template <typename Pred>
    T* buscar(Pred pred) {
        for (Nodo<T>* cur = cabeza.get(); cur; cur = cur->siguiente.get()) {
            if (pred(cur->valor)) return &cur->valor;
        }
        return nullptr;
    }

    // recorrer con una función
    template <typename Func>
    void forEach(Func f) const {
        for (Nodo<T>* cur = cabeza.get(); cur; cur = cur->siguiente.get()) {
            f(cur->valor);
        }
    }
};