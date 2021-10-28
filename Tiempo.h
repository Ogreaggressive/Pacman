#pragma once

#include "MiHilo.h"
#include "ContenedorDeDatos.h"


class Tiempo :
    public MiHilo
{
private:
	float tiempo;
	float aumento;
	int posx;
	int posy;
	int color;
	string mensaje;
	bool gameover;
public:
	Tiempo(int posx, int posy, int color, string mensaje);
	~Tiempo();
	int getTime();
	bool finJuego();
	void jugar();
};

