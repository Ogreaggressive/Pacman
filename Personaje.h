#pragma once

#include "MiHilo.h"
#include "Formato.h"
#include "ContenedorDeDatos.h"
#include "Mapa.h"

#include <random>
#include <iostream>
#include <string>

using namespace std;

class Personaje :public MiHilo 
{
protected:
	int posx;
	int posy;
	int color;
	char caracter;
	int posAnteriorX;
	int posAnteriorY;
	bool gameover;
public:
	Personaje(int posx,int posy, int color, char caracter);
	~Personaje();
	void dibujar(char caracter);
	void moverIzquierda();
	void moverDerecha();
	void moverArriba();
	void moverAbajo();
	bool quedarseQuieto();
	void posicionAnterior();
	int getPosX();
	int getPosY();
	bool finJuego();
	virtual void jugar() = 0;
};

