#include "consola.h"

void Consola::mostrarMenu()
{
    cout << "1) Listar encomiendas\n";
    cout << "0) Salir\n";

    int op;
    cin >> op;

    switch (op)
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
    Ordenamiento<Encomienda> qs = QuickSort<Encomienda>();

    // gestorEnvios.listarOrdenado(compararPorMonto, qs);
}

int compararPorMonto(Encomienda a, Encomienda b)
{
    if (a.getPago() < b.getPago())
        return -1;
    if (a.getPago() > b.getPago())
        return 1;

    return 0;
}