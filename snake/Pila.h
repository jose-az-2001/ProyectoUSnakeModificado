#pragma once
#include "Nodo.h"
class Pila
{
public:
	Pila();
	void Insertar(int x, int y);
	Nodo Eliminar();
	int ObtenerTamanio();
	void Recorrer();
private:
	Nodo* tope;
	int max;
	int tamanio;
};

