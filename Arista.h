#pragma once
class Arista {
private:
	int destino;
	int tiempo;
	int distancia;

public: 
	Arista(int _destino, int t, int d) {
		destino = _destino;
		tiempo = t;
		distancia = d;
	}

	int getDestino() { return destino; }
	int getDistancia() { return distancia; }
};