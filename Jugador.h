#pragma once

#include <sstream>
#include <iostream>
#include <string>

using namespace std;


class Jugador
{
private:
	string nombre;
	int puntaje;
	int tiempo;
public:
	Jugador(string nombre, int puntaje, int tiempo);
	Jugador(int puntaje);
	~Jugador();
	int getPuntaje();
	string getNombre();
	int getTiempo();
	void mostrar();
	static void mostrar(Jugador* Jugador);
	bool operator==(Jugador* Jugador);
	static bool compPuntajeDesc(Jugador* p1, Jugador* p2);
	static bool compNomAsc(Jugador* p1, Jugador* p2);
};







