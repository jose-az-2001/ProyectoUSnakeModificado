#pragma once

class Nodo
{
public:
	Nodo();
	Nodo(int x, int y);
	int ObtenerX1();
	int ObtenerY1();
	Nodo* ObtenerSiguiente();
	void ModificarX1(int x);
	void ModificarY1(int y);
	void ModificarSiguiente(Nodo* puntero);
private:
	int x1;
	int y1;
	Nodo* siguiente;
};

