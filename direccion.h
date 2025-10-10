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
    Direccion() {}

    void setCalle(string c) { calle = c; }
    void setNumero(string n) { numero = n; }
    void setDistrito(string d) { distrito = d; }
    void setProvincia(string p) { provincia = p; }
    void setDepartamento(string d) { departamento = d; }
    void setReferencia(string r) { referencia = r; }

    string toString();
};