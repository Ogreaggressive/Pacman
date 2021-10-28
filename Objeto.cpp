#include "Objeto.h"

Objeto::Objeto(int posx, int posy, int color, char caracter,string tipo)
{
	this->posx = posx;
	this->posy = posy;
	this->color = color;
	this->caracter = caracter;
	this->tipo = tipo;
}

Objeto::~Objeto()
{

}

void Objeto::dibujar()
{
	//color(color);
	gotoxy(posx, posy);
	cout << caracter;
}

string Objeto::getTipo()
{
	return tipo;
}

int Objeto::getPosX()
{
	return posx;
}

int Objeto::getPosY()
{
	return posy;
}

char Objeto::getCar()
{
	return caracter;
}

void Objeto::cambiarCaracter(char car)
{
	caracter = car;
}