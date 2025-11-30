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
		cout << "\n[!] No se encontro la encomienda con codigo: " << codigo << endl;
		return;
	}

	cout << "\n--- DETALLES DE LA ENCOMIENDA ---\n";
	encomienda.imprimir();
	cout << "---------------------------------\n";
}

void GestorEnvios::crearEncomienda(string remitenteDni, string destinatarioDni, string sucursalOrigen, string sucursalDestino, string servicioNombre, double montoPago)
{
	Cliente remitente = gestorCliente.buscarPorDni(remitenteDni);
	Cliente destinatario = gestorCliente.buscarPorDni(destinatarioDni);
	Sucursal origen = gestorSucursal.buscarPorId(sucursalOrigen);
	Sucursal destino = gestorSucursal.buscarPorId(sucursalDestino);

	Servicio servicio = Servicio();
	servicio.setNombre(servicioNombre);

	Pago pago = Pago();
	pago.setMonto(montoPago);

	Vehiculo vehiculo = Vehiculo();
	Repartidor repartidor = Repartidor();

	Ruta ruta = Ruta();
	ruta.setDestino(destino);
	ruta.setOrigen(origen);

	/*Dijkstra dijkstra;
	dijkstra.buscarRuta(stoi(origen.getId()));*/
	gestorRutas.calcularRuta(origen, destino);

	string encomiendaCodigo = gestorEncomiendas.crear(remitente, destinatario, origen, destino, servicio, pago, vehiculo, repartidor, ruta);

	cout << "\n[+] Encomienda creada exitosamente.\n";
	cout << "    Codigo de rastreo: " << encomiendaCodigo << endl;
}

void GestorEnvios::imprimir(Encomienda encomiendas[], int q)
{
	cout << "--------------------------------------------------------\n";
	cout << " No. | Codigo | Remitente | Destinatario | Pago | Fecha \n";
	cout << "--------------------------------------------------------\n";
	for (int i = 0; i < q; i++)
	{
		cout <<
			" " << i + 1 << " | " <<
			encomiendas[i].getCodigo() << " | " <<
			encomiendas[i].getRemitente() << " | " <<
			encomiendas[i].getDestinatario() << " | " <<
			encomiendas[i].getPago() << " | " <<
			encomiendas[i].getFechaPago() << endl;
	}
	cout << "--------------------------------------------------\n";
}
