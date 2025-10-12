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
    Pago() {
        id = "";
        monto = 0.0;
        metodo = "";
		fecha = "";
    }

    void setId(string i) { id = i; }
    void setMonto(double m) { monto = m; }
    void setMetodo(string met) { metodo = met; }
    void setFecha(string f) { fecha = f; }

    double getMonto() { return monto; };
    string getFecha() { return fecha; };

    bool confirmado();    
};