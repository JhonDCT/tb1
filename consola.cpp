#include "consola.h"

int compararPorMonto(Encomienda &a, Encomienda &b)
{
    if (a.getPago() < b.getPago())
        return -1;
    if (a.getPago() > b.getPago())
        return 1;

    return 0;
}

void Consola::mostrarMenu()
{
    cout << "1) Listar encomiendas\n";
    cout << "0) Salir\n";

    int opcion;
    cin >> opcion;

    switch (opcion)
    {
    case 0:
        break;

    case 1:
        listarEncomiendas();
        break;

    default:
        break;
    }
}

void Consola::listarEncomiendas()
{
    Burbuja<Encomienda> qs;

    gestorEnvios.listarOrdenado(compararPorMonto, qs);
}
