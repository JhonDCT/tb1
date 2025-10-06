#include <string>

using namespace std;

class Paquete
{
private:
    string id;
    double pesoKg;
    double altoCm;
    double anchoCm;
    double largoCm;
    string contenido;

public:
    double volumen();
};