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
    Comprobante() {
        serie = "";
        numero = "";
        total = 0.0;
		tipo = "";
    }

    void setSerie(string s) { serie = s; }
    void setNumero(string n) { numero = n; }
    void setTotal(double t) { total = t; }
    void setTipo(string ti) { tipo = ti; }

    string getTipo() { return tipo; }

    void imprimir();
};