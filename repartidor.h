#include <string>

using namespace std;

class Repartidor
{
private:
    string id;
    string nombre;
    string licencia;

public:
    Repartidor() {}

    void setId(string i) { id = i; }
    void setNombre(string n) { nombre = n; }
    void setLicencia(string l) { licencia = l; }

    bool asignable();
};