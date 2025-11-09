#include "gestor_envios.h"

void GestorEnvios::listarOrdenado()
{
	MergeSort<Encomienda> qs;

	auto compararPorMontoPago = [](Encomienda a, Encomienda b) -> int
		{
			if (a.getPago() > b.getPago())
				return 1;

			if (a.getPago() < b.getPago())
				return -1;

			return 0;
		};

	/*ListaDoble<Encomienda> encomiendas = gestorEncomiendas.listar();*/
	ListaDoble<Encomienda> encomiendas = gestorEncomiendas.getEncomiendas();

	auto arreglo = encomiendas.convertirAArreglo();
	int q = encomiendas.getTamano();

	qs.ordenar(arreglo, q, compararPorMontoPago);

	imprimir(arreglo, q);
}

void GestorEnvios::buscarEncomiendaPorCodigo(string codigo)
{
	Encomienda encomienda = gestorEncomiendas.buscarPorCodigo(codigo);

	if (encomienda.getCodigo().empty()) {
		cout << "No se encontro la encomienda con codigo: " << codigo << endl;
		return;
	}

	encomienda.imprimir();
}

void GestorEnvios::crearEncomienda(string remitenteDni, string destinatarioDni, string sucursalDestino, string servicioNombre, double montoPago)
{
	Cliente remitente = gestorCliente.buscarPorDni(remitenteDni);
	Cliente destinatario = gestorCliente.buscarPorDni(destinatarioDni);
	// Sucursal origen = gestorSucursal.buscarPorId(sucursalOrigen);
	Sucursal destino = gestorSucursal.buscarPorId(sucursalDestino);
	Servicio servicio = Servicio();
	servicio.setNombre(servicioNombre);
	Pago pago = Pago();
	pago.setMonto(montoPago);

	// TODO: buscar sucursal por id
	Sucursal origen = Sucursal();
	// TODO: buscar vehiculo 
	Vehiculo vehiculo = Vehiculo();
	// TODO: buscar repartidor 
	Repartidor repartidor = Repartidor();
	// TODO: buscar ruta 
	Ruta ruta = Ruta();

	string encomiendaCodigo = gestorEncomiendas.crear(remitente, destinatario, origen, destino, servicio, pago, vehiculo, repartidor, ruta);

	cout << "Encomienda creada con codigo" << encomiendaCodigo << endl;
}

void GestorEnvios::imprimir(Encomienda encomiendas[], int q)
{
	for (int i = 0; i < q; i++)
	{
		cout << "Encomienda " << i + 1 << ": " << encomiendas[i].getPago() << endl;
	}
}
