#pragma once 

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
#include "repartidor.h"
#include "ruta.h"

using namespace std;

class Encomienda
{
private:
    string code;
    Cliente remitente;
    Cliente destinatario;
    Sucursal origen;
    Sucursal destino;
    Servicio servicio;
    Lista<Paquete*> paquetes;
    Seguimiento seguimiento;
    Pago pago;
    Comprobante comprobante;
    Vehiculo vehiculo;
    Repartidor repartidor;
    Ruta ruta;

public:
    Encomienda() {}

    Encomienda(string c, Cliente rem, Cliente des, Sucursal ori, Sucursal dest, Servicio ser, Seguimiento seg, Pago pag, Comprobante comp, Vehiculo veh, Repartidor repar, Ruta rut)
    {
        this->code = c;
        this->remitente = rem;
        this->destinatario = des;
        this->origen = ori;
        this->destino = dest;
        this->servicio = ser;
        this->pago = pag;
        this->comprobante = comp;
        this->vehiculo = veh;
        this->repartidor = repar;
        this->ruta = rut;
        // this->paquetes = Lista<Paquete>();
    }

    // void setPaquetes(Lista<Paquete> &&paq) { paquetes = std::move(paq); }

    double getPago() { return pago.getMonto(); };
};
