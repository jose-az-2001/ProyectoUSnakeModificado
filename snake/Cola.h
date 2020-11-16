#pragma once
#include "Nodo.h"

class Cola
{
private:
	int tamanio;
	int max;
	Nodo* frente;
	Nodo* fondo;

public:
	Cola();
	void Agregar(int x, int y);
	void Eliminar();
	void Recorrer();
	int ObtenerTamanio();
};

