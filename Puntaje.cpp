#include "Puntaje.h"

Puntaje::Puntaje(int posx, int posy, int color, string mensaje)
{
    this->posx = posx;
    this->posy = posy;
    this->color = color;
    this->mensaje = mensaje;
    puntaje = 0;
    gameover = false;
}

Puntaje::~Puntaje()
{

}

bool Puntaje::finJuego()
{
   return ContenedorDeDatos::getInst().terminarJuego(gameover);
}

int Puntaje::puntajeTot()
{
    return puntaje;
}

void Puntaje::jugar()
{
    while (finJuego() == false)
    {
        ContenedorDeDatos::getInst().borrarMensaje(posx, posy, mensaje);
        Mapa::getInst().conseguirPuntaje();
        puntaje = ContenedorDeDatos::getInst().getPuntaje();
        ContenedorDeDatos::getInst().imprimirPuntaje(posx, posy, puntaje, mensaje);
        this_thread::sleep_for(chrono::milliseconds(2017));
    }
}
