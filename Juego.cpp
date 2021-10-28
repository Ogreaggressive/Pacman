#include "Juego.h"

Juego::Juego()
{

}

Juego::~Juego()
{

}

string Juego::conseguirNombre()
{
	string nombreJugador;
	cout << "inserte nombre de jugador" << endl;
	cin >> nombreJugador;
	return nombreJugador;
}

void Juego::registrarPuntaje(string nombre, int puntaje, int tiempo)
{
	ListaScores s;
	s.conseguirLista();
	s.aumentarNuevoPuntaje(nombre,puntaje,tiempo);
	s.cambiarLista();
	s.imprimirNuevaLista();
}

void Juego::inicializarMapa()
{
	Mapa::getInst().conseguirMapa();

	Mapa::getInst().dibujar();
}

void Juego::iniciar()
{
	string nombreJugador;
	nombreJugador=conseguirNombre();

	inicializarMapa();

	Bobo b(45, 20, 3, 'b');
	Tiempo t(0, 35, 7, "tiempo jugado");
	Puntaje pun(30,35,7,"puntaje total");
	Cazador c(41, 20, 6, 'c');
	Pacman p(50, 30, 7, 'p');
	Emboscador e(43, 20, 5, 'e');
	Miedoso m(39, 20, 4, 'm');

	p.iniciar();
	t.iniciar();
	c.iniciar();
	b.iniciar();
	e.iniciar();
	m.iniciar();
	pun.iniciar();

	p.join();
	t.join();
	c.join();
	b.join();
	e.join();
	m.join();
	pun.join();

	registrarPuntaje(nombreJugador,pun.puntajeTot(),t.getTime());
}

void Juego::finalizar()
{
	gotoxy(0,37);
	cout << "juego finalizado" << endl;
	gotoxy(0, 38);
}