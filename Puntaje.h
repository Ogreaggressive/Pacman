#pragma once

#include "MiHilo.h"
#include "ContenedorDeDatos.h"
#include "Mapa.h"


class Puntaje :
	public MiHilo
{
private:
	int posx;
	int posy;
	int color;
	string mensaje;
	int puntaje;
	bool gameover;
public:
	Puntaje(int posx, int posy, int color, string mensaje);
	~Puntaje();
	bool finJuego();
	int puntajeTot();
	void jugar();
};


