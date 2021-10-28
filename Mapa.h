#pragma once

#include <fstream>

#include "Objeto.h"
#include "Personaje.h"
#include "BolaEnergia.h"
#include "Alimento.h"
#include "Pared.h"
#include "ListaGenerica.h"

class Mapa
{
private:
	ListaGenerica<Pared> paredes;
	ListaGenerica<Alimento> alimentos;
	ListaGenerica<BolaEnergia> bolasEnergia;
public:
	static Mapa& getInst(); 
	~Mapa();
	void dibujar();
	void conseguirMapa();
	void dibujarParedes();
	void dibujarAlimentos();
	void dibujarBolasEnergia();
	bool colision(int x, int y);
	void comerAlimento(int x, int y);
	void comerBolaEnergia(int x, int y);
	void reescribirPared(int x, int y);
	void reescribirAlimento(int x, int y);
	void conseguirPuntaje();
private:
	Mapa();
};

