#include <string>

using namespace std;

class Cliente
{
private:
    string id;
    string dniRuc;
    string nombre;
    string telefono;
    string email;

public:
    bool validar();
};