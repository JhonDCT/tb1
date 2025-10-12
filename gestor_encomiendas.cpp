#include "gestor_encomiendas.h"

ListaDoble<Encomienda> GestorEncomiendas::listar()
{
	ListaDoble<Encomienda> encomiendas;
	string ruta = "encomiendas.txt";

	ifstream fichero;
	fichero.open(ruta);

	if (!fichero.is_open())
	{
		cout << "No se puede abrir el archivo" << ruta << endl;
	}

	string linea;
	while (getline(fichero, linea))
	{
		if (linea.empty())
			continue;

		vector<string> campos;
		istringstream ss(linea);
		string campo;
		while (getline(ss, campo, ';'))
		{
			campos.push_back(campo);
		}

		Cliente remitente = Cliente();
		remitente.setId(campos[1]);
		remitente.setDniRuc(campos[2]);
		remitente.setNombre(campos[3]);
		remitente.setTelefono(campos[4]);
		remitente.setEmail(campos[5]);

		Cliente destinatario = Cliente();
		destinatario.setId(campos[6]);
		destinatario.setDniRuc(campos[7]);
		destinatario.setNombre(campos[8]);
		destinatario.setTelefono(campos[9]);
		destinatario.setEmail(campos[10]);

		Direccion direccionOrigen = Direccion();
		direccionOrigen.setCalle(campos[13]);
		direccionOrigen.setNumero(campos[14]);
		direccionOrigen.setDistrito(campos[15]);
		direccionOrigen.setProvincia(campos[16]);
		direccionOrigen.setDepartamento(campos[17]);
		direccionOrigen.setReferencia(campos[18]);

		Sucursal origen = Sucursal();
		origen.setId(campos[11]);
		origen.setNombre(campos[12]);
		origen.setDireccion(direccionOrigen);
		origen.setTelefono(campos[19]);

		Direccion direccionDestino = Direccion();
		direccionDestino.setCalle(campos[22]);
		direccionDestino.setNumero(campos[23]);
		direccionDestino.setDistrito(campos[24]);
		direccionDestino.setProvincia(campos[25]);
		direccionDestino.setDepartamento(campos[26]);
		direccionDestino.setReferencia(campos[27]);

		Sucursal destino = Sucursal();
		destino.setId(campos[20]);
		destino.setNombre(campos[21]);
		destino.setDireccion(direccionDestino);
		destino.setTelefono(campos[28]);

		Servicio servicio = Servicio();
		servicio.setCodigo(campos[29]);
		servicio.setNombre(campos[30]);
		servicio.setDiasPromedio(stoi(campos[31]));

		Seguimiento seguimiento = Seguimiento();
		seguimiento.setCodigoTracking(campos[32]);

		Pago pago = Pago();
		pago.setId(campos[33]);
		pago.setMonto(stod(campos[34]));
		pago.setMetodo(campos[35]);
		pago.setFecha(campos[36]);

		Comprobante comprobante = Comprobante();
		comprobante.setSerie(campos[37]);
		comprobante.setNumero(campos[38]);
		comprobante.setTotal(stod(campos[39]));
		comprobante.setTipo(campos[40]);

		Vehiculo vehiculo = Vehiculo();
		vehiculo.setPlaca(campos[41]);
		vehiculo.setTipo(campos[42]);
		vehiculo.setCapacidad(stod(campos[43]));

		Repartidor repartidor = Repartidor();
		repartidor.setId(campos[44]);
		repartidor.setNombre(campos[45]);
		repartidor.setLicencia(campos[46]);

		Ruta ruta = Ruta();
		ruta.setId(campos[47]);
		ruta.setOrigen(origen);
		ruta.setDestino(destino);
		ruta.setKm(stod(campos[48]));

		Encomienda encomienda = Encomienda(
			campos[0],
			remitente,
			destinatario,
			origen,
			destino,
			servicio,
			seguimiento,
			pago,
			comprobante,
			vehiculo,
			repartidor,
			ruta);

		encomiendas.insertarInicio(encomienda);

		// TODO: Agregar Paquetes
	}

	fichero.close();

	return encomiendas;
}

Encomienda GestorEncomiendas::buscarPorCodigo(string codigo) {
	ListaDoble<Encomienda> encomiendas = listar();

	auto comparadorPorCodigo = [codigo](Encomienda a) {

		if (a.getCodigo() == codigo) return true;

		return false;
		};

	return encomiendas.buscar(comparadorPorCodigo);
}

string GestorEncomiendas::crear(
	Cliente remitente,
	Cliente destinatario,
	Sucursal origen,
	Sucursal destino,
	Servicio servicio,	
	Pago pago,	
	Vehiculo vehiculo,
	Repartidor repartidor,
	Ruta ruta
) {
	// TODO: generar numero grande aleatorio
	Seguimiento seguimiento = Seguimiento();
	seguimiento.setCodigoTracking("123");

	// TODO: generar string aleatorios 
	Comprobante comprobante = Comprobante();
	comprobante.setNumero("001");
	comprobante.setSerie("F001");
	comprobante.setTipo("factura");
	comprobante.setTotal(pago.getMonto());
	
	Encomienda encomienda = Encomienda(
		remitente,
		destinatario,
		origen,
		destino,
		servicio,
		seguimiento,
		pago,
		comprobante,
		vehiculo,
		repartidor,
		ruta
	);

	ofstream fichero;
	fichero.open(this->ruta);

	if (!fichero.is_open())
	{
		cout << "No se puede abrir el archivo" << this->ruta << endl;
	}

	fichero << encomienda.formatoParaGuardar() << endl;

	fichero.close();

	return encomienda.getCodigo();
}