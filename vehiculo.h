#include <string>

using namespace std;

class Vehiculo
{
private:
    string placa;
    string tipo;
    double capacidad;

public:
    Vehiculo() {
        placa = "";
        tipo = "";
		capacidad = 0.0;
    }

    void setPlaca(string p) { placa = p; }
    void setTipo(string t) { tipo = t; }
    void setCapacidad(double c) { capacidad = c; }

	string getPlaca() { return placa; }

    bool disponible();
};