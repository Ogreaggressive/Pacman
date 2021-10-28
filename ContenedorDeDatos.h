#pragma once

#include <mutex>
#include <iostream>
#include "Formato.h"

using namespace std;


class ContenedorDeDatos
{
private:
	int posx;
	int posy;
	int posxFan;
	int posyFan;
	int tiempoJuego;
	int puntaje;
	bool end;
	bool invencible;
	int tiempoInvencible;
	mutex m;
public:
	static ContenedorDeDatos& getInst();
	~ContenedorDeDatos();
	void cambiarPosicion(int x,int y);
	void printChar(int x, int y,int col,char c);
	void aumentarTiempo(int x, int y, int tiempo,string m);
	void imprimirPuntaje(int x, int y, int punt, string m);
	void borrarMensaje(int x, int y, string m);
	int getTiempo();
	int quitarElemento();
	void conseguirPosicionPacman(int x, int y);
	int getPosXPacman();
	int getPosYPacman();
	void conseguirPosicionFantasma(int x, int y);
	int getPosXFantasma();
	int getPosYFantasma();
	void aumentarPuntaje(int x);
	int getPuntaje();
	bool terminarJuego(bool fin);
	void activarInvencible();
	void desactivarInvencible();
	bool getInvencible();
private:
	ContenedorDeDatos();
};


