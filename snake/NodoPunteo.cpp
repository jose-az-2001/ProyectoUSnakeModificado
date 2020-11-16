#include "NodoPunteo.h"
NodoPunteo::NodoPunteo() {
	this->numero = 0;
	this->siguiente = nullptr;
}
void NodoPunteo::ModificarNumero(int num) {
	this->numero = num;
}
void NodoPunteo::ModificarSiguiente(NodoPunteo* siguiente) {
	this->siguiente = siguiente;
}
int NodoPunteo::ObtenerNumero() {
	return this->numero;
}
NodoPunteo* NodoPunteo::ObtenerSiguiente() {
	return this->siguiente;
}