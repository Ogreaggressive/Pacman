#include "Tiempo.h"

Tiempo::Tiempo(int posx, int posy, int color, string mensaje)
{
    this->posx = posx;
    this->posy = posy;
    this->color = color;
    this->mensaje = mensaje;
    tiempo = 0;
    aumento = 1;
    gameover = false;
}

Tiempo::~Tiempo()
{

}

int Tiempo::getTime()
{
    return tiempo;
}

bool Tiempo::finJuego()
{
   return ContenedorDeDatos::getInst().terminarJuego(gameover);
}


void Tiempo::jugar()
{
    while (finJuego() == false)
    {
        ContenedorDeDatos::getInst().borrarMensaje(posx, posy, mensaje);
        tiempo = tiempo + aumento;
        ContenedorDeDatos::getInst().aumentarTiempo(posx,posy,tiempo,mensaje);
        this_thread::sleep_for(chrono::milliseconds(1000));
    }
}