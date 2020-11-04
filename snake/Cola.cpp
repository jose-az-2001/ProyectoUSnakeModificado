#include "Cola.h"
#include <string>
#include <allegro5/allegro_primitives.h>

Cola::Cola() {
	this->tamanio = 0;
	this->max = -1;
	this->frente = NULL;
	this->fondo = NULL;
}

int Cola::ObtenerTamanio() {
	return this->tamanio;
}

void Cola::Agregar(int x, int y) {
	if (this->max > this->tamanio || this->max == -1) {
		Nodo* nuevo = new Nodo();
		nuevo->ModificarX1(x);
		nuevo->ModificarY1(y);
		if (this->frente == NULL && this->fondo == NULL) {
			this->frente = nuevo;
			this->fondo = nuevo;
		}
		else {
			Nodo* aux = this->fondo;
			this->fondo = nuevo;
			aux->ModificarSiguiente(nuevo);
		}
		this->tamanio++;
	}
}

void Cola::Recorrer() {
	Nodo* aux = this->frente;
	while (aux != NULL) {
		al_draw_filled_rectangle(aux->ObtenerX1(), aux->ObtenerY1(), aux->ObtenerX1() + 40, aux->ObtenerY1() + 40, al_map_rgb(40, 255, 13));
		aux = aux->ObtenerSiguiente();
	}
}

void Cola::Eliminar() {
	if (this->frente == this->fondo) {
		this->frente = NULL;
		this->fondo = NULL;
		this->tamanio = 0;
	}
	else {
		Nodo* aux = this->frente;
		this->frente = this->frente->ObtenerSiguiente();
		aux->ModificarSiguiente(NULL);
		this->tamanio--;
	}
}