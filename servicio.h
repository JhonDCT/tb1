#include <string>

using namespace std;

class Servicio
{
private:
    string codigo;
    string nombre;
    int dias_promedio;

public:
    Servicio(){
        codigo = "";
        nombre = "";
		dias_promedio = 0;
    }

    void setCodigo(string c) { codigo = c; }
    void setNombre(string n) { nombre = n; }
    void setDiasPromedio(int d) { dias_promedio = d; }

    bool esExpress();
};