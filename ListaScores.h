#pragma once

#include "ListaGenerica.h"
#include "Mapa.h"
#include "Jugador.h"

class ListaScores
{
private:
	ListaGenerica<Jugador> jugadores;
public:
	ListaScores();
	~ListaScores();
	void conseguirLista();
	void cambiarLista();
	void aumentarNuevoPuntaje(string nombre, int puntaje, int tiempo);
	void imprimirNuevaLista();
};

