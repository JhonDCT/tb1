#include "string"

using namespace std;

class Comprobante
{
private:
    string serie;
    string numero;
    double total;
    string tipo;

public:
    void imprimir();
};