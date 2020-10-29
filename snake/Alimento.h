#pragma once
class Alimento
{
public:
	Alimento(int valor);
	void ModificarPosicionx(int x);
	void ModificarPosiciony(int y);
	int ObtenerValor();
private:
	int valor;
	int posicionx;
	int posiciony;
};

