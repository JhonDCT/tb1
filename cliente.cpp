#include "cliente.h"

bool Cliente::validar()
{
    return !id.empty() && !dniRuc.empty() && !nombre.empty();
}