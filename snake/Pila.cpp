#include "Pila.h"
#include <string>
#include <allegro5/allegro_primitives.h>

Pila::Pila() {
	this->tope = NULL;
	this->max = -1;
	this->tamanio = 0;
}
void Pila::Insertar(int x, int y) {
	if (this->max > this->tamanio || this->max == -1) {
		Nodo* nuevo = new Nodo();
		nuevo->ModificarSiguiente(this->tope);
		nuevo->ModificarX1(x);
		nuevo->ModificarY1(y);
		this->tope = nuevo;
		this->tamanio++;
	}
}
Nodo Pila::Eliminar() {
		Nodo* temporal = this->tope;
		this->tope = temporal->ObtenerSiguiente();
		temporal->ModificarSiguiente(NULL);
		this->tamanio--;
		return *temporal;
}
int Pila::ObtenerTamanio() {
	return this->tamanio;
}
void Pila::Recorrer() {
	Nodo* temporal = this->tope;
	while (this->tope != NULL) {
		Nodo* actual = this->tope;
		al_draw_filled_rectangle(actual->ObtenerX1(), actual->ObtenerY1(), actual->ObtenerX1() + 40, actual->ObtenerY1() + 40, al_map_rgb(40, 255, 13));
		Nodo* siguiente = actual->ObtenerSiguiente();
		this->tope = siguiente;
	}
	this->tope = temporal;
}