#include <string>

using namespace std;

class Pago
{
private:
    string id;
    double monto;
    string metodo;
    string fecha;

public:
    Pago() {}

    void setId(string i) { id = i; }
    void setMonto(double m) { monto = m; }
    void setMetodo(string met) { metodo = met; }
    void setFecha(string f) { fecha = f; }

    bool confirmado();
    double getMonto() { return monto; };
};