#include "Alimento.h"

Alimento::Alimento(int valor) {
	this->posicionx = 0;
	this->posiciony = 0;
	this->valor = valor;
}
void Alimento::ModificarPosicionx(int x) {
	this->posicionx = x;
}
void Alimento::ModificarPosiciony(int y) {
	this->posiciony = y;
}
int Alimento::ObtenerValor() {
	return this->valor;
}