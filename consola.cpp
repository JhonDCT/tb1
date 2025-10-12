#include "consola.h"

void Consola::mostrarMenu()
{
	cout << "1) Listar encomiendas\n";
	cout << "2) Buscar encomienda por codigo\n";
	cout << "3) Crear encomienda\n";
	cout << "0) Salir\n";

	int opcion;
	cin >> opcion;

	switch (opcion)
	{
	case 0:
		break;

	case 1:
		listarEncomiendas();
		break;

	case 2:
		buscarEncomiendaPorCodigo();
		break;

	case 3:
		crearEncomienda();
		break;

	default:
		break;
	}
}

void Consola::listarEncomiendas()
{
	Burbuja<Encomienda> qs;

	auto compararPorMonto = [](Encomienda a, Encomienda b) -> int
		{
			if (a.getPago() > b.getPago())
				return 1;

			if (a.getPago() < b.getPago())
				return -1;

			return 0;			
		};

	gestorEnvios.listarOrdenado(compararPorMonto, qs);
}

void Consola::buscarEncomiendaPorCodigo()
{
	cout << "Ingrese el codigo de la encomienda: ";
	string codigo;
	cin >> codigo;

	gestorEnvios.buscarEncomiendaPorCodigo(codigo);
}

void Consola::crearEncomienda()
{
	string remitenteDni;
	string destinatarioDni;
	string sucursalDestino;
	string servicio;
	string pago;

	cout << "Ingrese dni del remitente";
	cin >> remitenteDni;

	cout << "Ingrese dni del destinatario";
	cin >> destinatarioDni;

	cout << "Ingrese el codigo de la sucursal destino";
	cin >> sucursalDestino;

	cout << "Ingrese el servicio";
	cin >> servicio;

	cout << "Ingrese el monto del pago";
	cin >> pago;

	gestorEnvios.crearEncomienda(remitenteDni, destinatarioDni, sucursalDestino, servicio, stod(pago));
}