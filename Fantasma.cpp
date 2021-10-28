#include "Fantasma.h"

Fantasma::Fantasma(int posx, int posy, int color, char caracter) :Personaje(posx, posy, color, caracter)
{
	comido = false;
}

Fantasma::~Fantasma()
{

}

bool Fantasma::salirFantasma(int tiempo)
{
	if (ContenedorDeDatos::getInst().getTiempo() > tiempo)
	{
		return true;
	}
	return false;
}

void Fantasma::reescribirComida()
{
	Mapa::getInst().reescribirAlimento(posx,posy);
}

void Fantasma::matarPacman()
{
	if (posx == ContenedorDeDatos::getInst().getPosXPacman()
		&& posy == ContenedorDeDatos::getInst().getPosYPacman()
		&& ContenedorDeDatos::getInst().getInvencible()==false)
	{
		gameover = true;
	}
	else if (posx == ContenedorDeDatos::getInst().getPosXPacman()
		&& posy == ContenedorDeDatos::getInst().getPosYPacman()
		&& ContenedorDeDatos::getInst().getInvencible() == true
		&& comido==false)
	{
		ContenedorDeDatos::getInst().aumentarPuntaje(200);
		comido == true;
	}
}