#pragma once

#include "Personaje.h"
#include "Bobo.h"
#include "Miedoso.h"
#include "Cazador.h"
#include "Emboscador.h"
#include "Pacman.h"

#include "Mapa.h"
#include "Objeto.h"

#include "Tiempo.h"
#include "Puntaje.h"

#include "Jugador.h"
#include "ListaScores.h"

class Juego
{
private:

public:
	Juego();
	~Juego();
	void iniciar();
	string conseguirNombre();
	void inicializarMapa();
	void registrarPuntaje(string nombre, int puntaje, int tiempo);
	void finalizar();
};

