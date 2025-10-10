#include "encomienda.h"
#include "ordenamiento.h"
#include "gestor_encomiendas.h"

using namespace std;

class GestorEnvios
{
private:
    GestorEncomiendas gestorEncomiendas;

public:
    // template <typename Comparador>
    // Lista<Encomienda> listarOrdenado(Comparador cmp, Ordenamiento<Encomienda> est);

    // Lista<Encomienda> listarOrdenado(const function<int(Encomienda &, Encomienda &)> cmp, Ordenamiento<Encomienda> est)
    void listarOrdenado(function<int(Encomienda &, Encomienda &)> cmp, Ordenamiento<Encomienda> &est)
    {
        Lista<Encomienda> encomiendas = gestorEncomiendas.listar();
        Encomienda *arr = {};
        encomiendas.convertirAArreglo(arr);

        for (size_t i = 0; i < encomiendas.getTamano(); i++)
        {
            /* code */
            cout << "Encomienda " << i << " Monto: " << arr[i].getPago() << endl;
        }

        // est.ordenar(encomiendas, cmp);
        // Lista<Encomienda> copia = envios;

        // est.ordenar([], cmp);
    }
};
// Lista<Encomienda> listarOrdenado(const std::function<int(const Encomienda&, const Encomienda&)>& cmp, Ordenamiento<Encomienda> est);
