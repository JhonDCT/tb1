#include "encomienda.h"

void Encomienda::imprimir()
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

// TODO: Guardar datos, crear un metodo formato para guardar en cada clase involucrada
string Encomienda::formatoParaGuardar()
{
	return codigo + ";" +
		remitente.getId() + ";" +
		remitente.getDni() + ";" +
		remitente.getNombre() + ";" +
		remitente.getTelefono() + ";" +
		remitente.getEmail() + ";";
};