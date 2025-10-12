#pragma once 

#include <string>
#include <iostream>
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
	string codigo;
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

	Encomienda(
		string c,
		Cliente rem,
		Cliente des,
		Sucursal ori,
		Sucursal dest,
		Servicio ser,
		Seguimiento seg,
		Pago pag,
		Comprobante comp,
		Vehiculo veh,
		Repartidor repar,
		Ruta rut)
	{
		this->codigo = c;
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

	Encomienda(
		Cliente rem,
		Cliente des,
		Sucursal ori,
		Sucursal dest,
		Servicio ser,
		Seguimiento seg,
		Pago pag,
		Comprobante comp,
		Vehiculo veh,
		Repartidor repar,
		Ruta rut)
	{
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
	string getCodigo() { return codigo; }
	string getFechaPago() { return pago.getFecha(); }

	void imprimir()
	{
		cout << "Encomienda Codigo: " << codigo << endl;
		cout << "Remitente: " << remitente.getNombre() << endl;
		cout << "Destinatario: " << destinatario.getNombre() << endl;
		cout << "Origen: " << origen.getNombre() << endl;
		cout << "Destino: " << destino.getNombre() << endl;
		cout << "Servicio: " << servicio.esExpress() << endl;
		cout << "Pago: " << pago.getMonto() << endl;
		cout << "Comprobante Tipo: " << comprobante.getTipo() << endl;
		cout << "Vehiculo Placa: " << vehiculo.getPlaca() << endl;
		cout << "Repartidor Nombre: " << repartidor.getNombre() << endl;
		cout << "Ruta Estimado Horas: " << ruta.estimadoHoras() << endl;
	}

	// TODO: Guardar datos
	string formatoParaGuardar()
	{
		return codigo + ";" +
			remitente.getId() + ";" +
			remitente.getDni() + ";" +
			remitente.getNombre() + ";" +
			remitente.getTelefono() + ";" +
			remitente.getEmail() + ";";
	};
};

//string codigo;
//Cliente remitente;
//Cliente destinatario;
//Sucursal origen;
//Sucursal destino;
//Servicio servicio;
//Lista<Paquete*> paquetes;
//Seguimiento seguimiento;
//Pago pago;
//Comprobante comprobante;
//Vehiculo vehiculo;
//Repartidor repartidor;
//Ruta ruta;