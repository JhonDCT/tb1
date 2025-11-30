#include "consola.h"

void Consola::mostrarMenu()
{
	//limpiarPantalla();
	mostrarLogo();
	cout << "========================================\n";
	cout << "       MENU PRINCIPAL\n";
	cout << "========================================\n";
	cout << endl;

	cout << "1) Listar encomiendas\n";
	cout << "2) Buscar encomienda por codigo\n";
	cout << "3) Crear encomienda\n";
	cout << "4) Buscar clientes\n";
	cout << "5) Mostrar cola de prioridad\n";
	cout << "0) Salir\n";
	cout << "\nSeleccione una opcion: ";

	int opcion;
	cin >> opcion;

	switch (opcion)
	{
	case 0:
		exit(0);
		break;

	case 1:
		listarEncomiendas();
		pausar();
		break;

	case 2:
		buscarEncomiendaPorCodigo();
		pausar();
		break;

	case 3:
		crearEncomienda();
		pausar();
		break;

	case 4:
		buscarCliente();
		pausar();
		break;

	default:
		cout << "Opcion invalida.\n";
		pausar();
		break;
	}
}

void Consola::listarEncomiendas()
{
	mostrarEncabezado("LISTADO DE ENCOMIENDAS");
	gestorEnvios.listarOrdenado();
}

void Consola::buscarEncomiendaPorCodigo()
{
	mostrarEncabezado("BUSCAR ENCOMIENDA");
	cout << "Ingrese el codigo de la encomienda: ";
	string codigo;
	cin >> codigo;

	gestorEnvios.buscarEncomiendaPorCodigo(codigo);
}

void Consola::crearEncomienda()
{
	mostrarEncabezado("CREAR NUEVA ENCOMIENDA");
	string remitenteDni;
	string destinatarioDni;
	string sucursalOrigen;
	string sucursalDestino;
	string servicio;
	string pago;

	cout << "Ingrese DNI del remitente: ";
	cin >> remitenteDni;

	cout << "Ingrese DNI del destinatario: ";
	cin >> destinatarioDni;

	cout << "Ingrese el codigo de la sucursal origen: ";
	cin >> sucursalOrigen;

	cout << "Ingrese el codigo de la sucursal destino: ";
	cin >> sucursalDestino;

	cout << "Ingrese el servicio: ";
	cin >> servicio;

	cout << "Ingrese el monto del pago: ";
	cin >> pago;

	gestorEnvios.crearEncomienda(remitenteDni, destinatarioDni, sucursalOrigen, sucursalDestino, servicio, stod(pago));
}

void Consola::buscarCliente()
{
	mostrarEncabezado("BUSCAR CLIENTE");
	cout << "Ingrese el DNI del cliente: ";
	string dni;
	cin >> dni;

	Cliente cliente = gestorClientes.buscarPorDni(dni);

	cliente.imprimir();
}

void Consola::limpiarPantalla()
{
	system("cls");
}

void Consola::pausar()
{
	cout << "\nPresione Enter para continuar...";
	cin.ignore();
	cin.get();
}

void Consola::mostrarEncabezado(string titulo)
{
	limpiarPantalla();
	cout << "========================================\n";
	cout << "       " << titulo << "\n";
	cout << "========================================\n";
	cout << endl;
}

void Consola::mostrarLogo()
{
    cout << "      __\n";
    cout << " ____|  \\__\n";
    cout << "|          |\n";
    cout << "|__________|\n";
    cout << "   O    O   \n";
    cout << "OLVA CURRIER\n";
    cout << endl;
}
