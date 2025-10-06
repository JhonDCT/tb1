#include <string>
#include "cliente.h"
#include "sucursal.h"
#include "servicio.h"
#include "paquete.h"
#include "lista.h"
#include "pago.h"
#include "comprobante.h"
#include "vehiculo.h"
#include "seguimiento.h"

class Encomienda
{
private:
    string code;
    Cliente remitente;
    Cliente destinatario;
    Sucursal origen;
    Sucursal destino;
    Servicio servicio;
    Lista<Paquete> paquetes;
    Seguimiento seguimiento;
    Pago pago;
    Comprobante comprobante;
    Vehiculo vehiculo;
    
};