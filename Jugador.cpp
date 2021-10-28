#include "Jugador.h"

Jugador::Jugador(string nombre, int puntaje, int tiempo)
{
	this->puntaje = puntaje;
	this->nombre = nombre;
	this->tiempo = tiempo;
}

Jugador::Jugador(int puntaje)
{
	this->puntaje = puntaje;
}


Jugador::~Jugador()
{

}

int Jugador::getPuntaje()
{
	return puntaje;
}

string Jugador::getNombre()
{
	return nombre;
}

int Jugador::getTiempo()
{
	return tiempo;
}

void Jugador::mostrar()
{
	//cout << "Jugador:" << endl;
	cout << "nombre: " << nombre << endl;
}


void Jugador::mostrar(Jugador* Jugador)
{
	Jugador->mostrar();
}

bool Jugador::operator==(Jugador* Jugador)
{
	if (puntaje == Jugador->puntaje)
	{
		return true;
	}
	return false;
}

bool Jugador::compPuntajeDesc(Jugador* p1, Jugador* p2)
{
	return p1->puntaje < p2->puntaje;
}

bool Jugador::compNomAsc(Jugador* p1, Jugador* p2)
{
	return p1->nombre > p2->nombre;
}
