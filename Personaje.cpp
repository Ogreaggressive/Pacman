#include "Personaje.h"

Personaje::Personaje(int posx, int posy, int color, char caracter)
{
	this->posx = posx;
	this->posy = posy;
	this->color = color;
	this->caracter = caracter;
	posAnteriorX = 0;
	posAnteriorY = 0;
	gameover = false;
}

Personaje::~Personaje()
{

}

void Personaje::dibujar(char caracter)
{
	ContenedorDeDatos::getInst().printChar(posx, posy,color,caracter);
}

void Personaje::moverIzquierda()
{
	posx = posx - 1;
}

void Personaje::moverDerecha()
{
	posx = posx + 1;
}

void Personaje::moverArriba()
{
	posy = posy - 1;
}

void Personaje::moverAbajo()
{
	posy = posy + 1;
}


bool Personaje::quedarseQuieto()
{
	return Mapa::getInst().colision(posx,posy);
}

void Personaje::posicionAnterior()
{
	posAnteriorX = posx;
	posAnteriorY = posy;
}

int Personaje::getPosX()
{
	return posx;
}

int Personaje::getPosY()
{
	return posy;
}

bool Personaje::finJuego()
{
	return ContenedorDeDatos::getInst().terminarJuego(gameover);
}