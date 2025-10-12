#include "ruta.h"

double Ruta::estimadoHoras()
{	
	const double velocidadPromedio = 60.0;
	if (velocidadPromedio <= 0) return 0.0;

	return km / velocidadPromedio;
}