#include <string>

using namespace std;

class Direccion
{
private:
    string calle;
    string numero;
    string distrito;
    string provincia;
    string departamento;
    string referencia;

public:
    string toString();
};