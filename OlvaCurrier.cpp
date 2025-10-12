#include <iostream>
#include "consola.h"

using namespace std;

int main()
{
    cout << "Hola" << endl;

    Consola consola;
    // Consola consola();

    while (true)
    {
        consola.mostrarMenu();
    }

    return 0;
}