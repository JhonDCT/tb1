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
    bool confirmado();
    double getMonto() { return monto; };
};