#include "Lista.h"
NodoPunteo* Lista::BuscarEspecifico(int referencia) {
	NodoPunteo* aux = this->frente;
	while (aux != nullptr) {
		if (aux->ObtenerNumero() == referencia) {
			return aux;
		}
		aux = aux->ObtenerSiguiente();
	}
	return aux;
}
NodoPunteo* Lista::BuscarPosicion(int referencia) {
	NodoPunteo* aux = this->frente;
	if (referencia<0 || referencia>this->tamanio) {
		throw "El valor no esta dentro de los parametros";
	}
	else {
		for (int i = 0; i < referencia; i++) {
			aux = aux->ObtenerSiguiente();
		}
		return aux;
	}
}
NodoPunteo* Lista::BuscarAnterior(NodoPunteo* referencia) {
	NodoPunteo* aux = this->frente;
	while (aux != nullptr) {
		if (aux->ObtenerSiguiente() == referencia) {
			return aux;
		}
		else {
			aux = aux->ObtenerSiguiente();
		}
	}
	return aux;
}
void Lista::InsertarInicio(int num) {
	NodoPunteo* nuevo = new NodoPunteo();
	nuevo->ModificarNumero(num);

	if (this->frente == nullptr && this->fondo == nullptr) {
		this->frente = nuevo;
		this->fondo = nuevo;
		this->tamanio = 1;
	}
	else {
		NodoPunteo* aux = this->frente;
		this->frente = nuevo;
		nuevo->ModificarSiguiente(aux);
		this->tamanio++;
	}
}
void Lista::InsertarFinal(int num) {
	NodoPunteo* nuevo = new NodoPunteo();
	nuevo->ModificarNumero(num);

	if (this->frente == nullptr && this->fondo == nullptr) {
		this->frente = nuevo;
		this->fondo = nuevo;
		this->tamanio++;
	}
	else {
		NodoPunteo* aux = this->fondo;
		this->fondo = nuevo;
		aux->ModificarSiguiente(nuevo);
		this->tamanio++;
	}
}
void Lista::InsertarAntes(int num, int referencia) {
	NodoPunteo* refe = this->BuscarEspecifico(referencia);
	NodoPunteo* nuevo = new NodoPunteo;
	nuevo->ModificarNumero(num);
	if (refe == nullptr) {
		throw "La referencia no existe";
	}
	else {
		if (refe == this->frente) {
			this->frente = nuevo;
			nuevo->ModificarSiguiente(refe);
			this->tamanio++;
		}
		else {
			NodoPunteo* anterior = this->BuscarAnterior(refe);
			anterior->ModificarSiguiente(nuevo);
			nuevo->ModificarSiguiente(refe);
			this->tamanio++;
		}
	}
}
void Lista::InsertarDespues(int num, int referencia) {
	NodoPunteo* ref = this->BuscarEspecifico(referencia);
	NodoPunteo* nuevo = new NodoPunteo;
	nuevo->ModificarNumero(num);
	if (ref == nullptr) {
		throw "La referencia no existe";
	}
	else if (ref == this->fondo) {
		this->fondo = nuevo;
		ref->ModificarSiguiente(nuevo);
		this->tamanio++;
	}
	else {
		NodoPunteo* aux = ref->ObtenerSiguiente();
		ref->ModificarSiguiente(nuevo);
		nuevo->ModificarSiguiente(aux);
		this->tamanio++;
	}
}
NodoPunteo* Lista::EliminarFinal() {
	NodoPunteo* aux = this->fondo;
	if (this->tamanio == 0) {
		throw "error subdesbordamiento";
	}
	else if (this->frente == this->fondo) {
		this->frente = nullptr;
		this->fondo = nullptr;
		tamanio = 0;
	}
	else {
		NodoPunteo* anterior = this->BuscarAnterior(this->fondo);
		this->fondo = anterior;
		anterior->ModificarSiguiente(nullptr);
	}
	this->tamanio--;
	return aux;
}
int Lista::ObtenerTamanio() {
	return this->tamanio;
}