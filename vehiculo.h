#include <string>

using namespace std;

class Vehiculo
{
private:
    string placa;
    string tipo;
    double capacidad;

public:
    bool disponible();
};