#include "Nodo.h"
#include <allegro5/allegro.h>

Nodo::Nodo() {
	this->x1 = 0;
	this->y1 = 0;
	this->siguiente = NULL;
}
Nodo::Nodo(int x, int y) {
	this->x1 = x;
	this->y1 = y;
	this->siguiente = NULL;
}
int Nodo::ObtenerX1() {
	return this->x1;
}
int Nodo::ObtenerY1() {
	return this->y1;
}
Nodo* Nodo::ObtenerSiguiente() {
	return this->siguiente;
}
void Nodo::ModificarX1(int x) {
	this->x1 = x;
}
void Nodo::ModificarY1(int y) {
	this->y1 = y;
}
void Nodo::ModificarSiguiente(Nodo* puntero) {
	this->siguiente = puntero;
}