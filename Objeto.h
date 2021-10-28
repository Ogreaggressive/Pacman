#pragma once


#include "Formato.h"
#include <iostream>
#include <string>

using namespace std;

class Objeto
{
protected:
	int posx;
	int posy;
	int color;
	char caracter;
	string tipo;
public:
	Objeto(int posx, int posy, int color, char caracter,string tipo);
	~Objeto();
	void dibujar();
	string getTipo();
	int getPosX();
	int getPosY();
	char getCar();
	void cambiarCaracter(char car);
};

