#include "encomienda.h"
#include "ordenamiento.h"

using namespace std;

class GestorEnvios
{
    private: 
        
public:
    // template <typename Comparador>
    // Lista<Encomienda> listarOrdenado(Comparador cmp, Ordenamiento<Encomienda> est);

    // Lista<Encomienda> listarOrdenado(const function<int(Encomienda &, Encomienda &)> cmp, Ordenamiento<Encomienda> est)
    void listarOrdenado(const function<int(Encomienda &, Encomienda &)> cmp, Ordenamiento<Encomienda> est)
    {
        // Lista<Encomienda> copia = envios;

        // est.ordenar([], cmp);

    }
};
// Lista<Encomienda> listarOrdenado(const std::function<int(const Encomienda&, const Encomienda&)>& cmp, Ordenamiento<Encomienda> est);
