#include <string>
#include "lista.h"
#include "evento.h"

using namespace std;

class Seguimiento
{
private:
    string codigoTracking;
    Lista<Evento> eventos;

public:
    void agregarEvento(Evento evento);
    Evento ultimoEvento();
};