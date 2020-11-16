#pragma once
#include "NodoPunteo.h"
class Lista
{
public:
	void InsertarInicio(int num);
	void InsertarFinal(int num);
	void InsertarAntes(int num, int referencia);
	void InsertarDespues(int num, int referencia);
	NodoPunteo* EliminarFinal();
	NodoPunteo* BuscarEspecifico(int referencia);
	//int BuscarMemoria(NodoPunteo* referencia);
	NodoPunteo* BuscarPosicion(int referencia);
	NodoPunteo* BuscarAnterior(NodoPunteo* referencia);
	int ObtenerTamanio();
private:
	int tamanio;
	NodoPunteo* frente;
	NodoPunteo* fondo;
};

