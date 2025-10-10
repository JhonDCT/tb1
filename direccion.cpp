#include "direccion.h"

string Direccion::toString()
{
    return this->calle + " " + this->numero + ", " + this->distrito + ", " + this->provincia + ", " + this->departamento + ". Ref: " + this->referencia;
}