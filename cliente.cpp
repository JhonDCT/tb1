#include "cliente.h"

bool Cliente::validar()
{
    return !id.empty() && !dni.empty() && !nombre.empty();
}