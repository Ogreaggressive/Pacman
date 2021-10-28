#include "ContenedorDeDatos.h"

ContenedorDeDatos::ContenedorDeDatos()
{
	end = false;
	invencible = false;
	tiempoInvencible = 15;
}

ContenedorDeDatos::~ContenedorDeDatos()
{

}

void ContenedorDeDatos::cambiarPosicion(int x, int y)
{
	m.lock();
	posx = x;
	posy = y;
	m.unlock();
}

ContenedorDeDatos& ContenedorDeDatos::getInst()
{
	static ContenedorDeDatos i;
	return i;
}

int ContenedorDeDatos::quitarElemento()
{
	int tmp = -1;
	m.lock();
	m.unlock();
	return tmp;
}

void ContenedorDeDatos::printChar(int x, int y, int col,char c)
{
	m.lock();
	color(col);
	gotoxy(x, y);
	cout << c;
	color(7);
	m.unlock();
}

void ContenedorDeDatos::aumentarTiempo(int x, int y, int tiempo,string c)
{
	m.lock();
	gotoxy(x, y);
	cout << c<<": "<< tiempo;
	tiempoJuego = tiempo;
	m.unlock();
}

void ContenedorDeDatos::borrarMensaje(int x, int y, string c)
{
	m.lock();
	gotoxy(x, y);
	cout << c << ":     ";
	m.unlock();
}

int ContenedorDeDatos::getTiempo()
{
	return tiempoJuego;
}

void ContenedorDeDatos::conseguirPosicionPacman(int x, int y)
{
	m.lock();
	posx = x;
	posy = y;
	m.unlock();
}

int ContenedorDeDatos::getPosXPacman()
{
	return posx;
}

int ContenedorDeDatos::getPosYPacman()
{
	return posy;
}

void ContenedorDeDatos::conseguirPosicionFantasma(int x, int y)
{
	m.lock();
	posxFan = x;
	posyFan = y;
	m.unlock();
}

int ContenedorDeDatos::getPosXFantasma()
{
	return posxFan;
}

int ContenedorDeDatos::getPosYFantasma()
{
	return posyFan;
}

void ContenedorDeDatos::aumentarPuntaje(int x)
{
	m.lock();
	puntaje = puntaje+x;
	m.unlock();
}

int ContenedorDeDatos::getPuntaje()
{
	return puntaje;
}

void ContenedorDeDatos::imprimirPuntaje(int x, int y, int punt, string c)
{
	m.lock();
	gotoxy(x, y);
	cout << c << ": " << punt<<"  ";
	puntaje = 0;
	m.unlock();
}

bool ContenedorDeDatos::terminarJuego(bool fin)
{
	m.lock();
	if (fin == true)
	{
		end = true;
	}
	m.unlock();
	return end;
}

void ContenedorDeDatos::activarInvencible()
{
	m.lock();
	invencible = true;
	tiempoInvencible = getTiempo() + 15;
	m.unlock();
}

void ContenedorDeDatos::desactivarInvencible()
{
	int tiempo;
	m.lock();
	if (getTiempo() > tiempoInvencible)
	{
		invencible = false;
	}
	m.unlock();
}

bool ContenedorDeDatos::getInvencible()
{
	return invencible;
}