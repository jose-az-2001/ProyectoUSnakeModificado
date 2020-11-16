#pragma once
class NodoPunteo
{
public:
	NodoPunteo();
	void ModificarNumero(int num);
	void ModificarSiguiente(NodoPunteo* siguiente);
	int ObtenerNumero();
	NodoPunteo* ObtenerSiguiente();

private:
	int numero;
	NodoPunteo* siguiente;

};

