#include <string>
#include "lista.h"
#include "evento.h"

using namespace std;

class Seguimiento
{
private:
    string codigoTracking;

public:
    Seguimiento() {
    }

    void setCodigoTracking(string c) { codigoTracking = c; }
};