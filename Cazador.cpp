#include "Cazador.h"

Cazador::Cazador(int posx, int posy, int color, char caracter) :Fantasma(posx, posy, color, caracter), mtCambio(1729), distCambio(1, 2)
{

}

Cazador::~Cazador()
{

}


void Cazador::siguienteCasilla()
{
    int x, y;
    x=ContenedorDeDatos::getInst().getPosXPacman();
    y=ContenedorDeDatos::getInst().getPosYPacman();
    int mX = distCambio(mtCambio) - 1;
    int mY = distCambio(mtCambio) - 1;
    if (posx >= x)
    {
        posx -= mX;
    }
    else
    {
        posx += mX;
    }
    if (posy >= y)
    {
        posy -= mY;
    }
    else
    {
        posy += mY;
    }
}

void Cazador::colisionFantasma()
{
    if (quedarseQuieto() == false)
    {
        posicionAnterior();
        siguienteCasilla();
    }
    else
    {
        Mapa::getInst().reescribirPared(posx, posy);
        posx = posAnteriorX;
        posy = posAnteriorY;
    }
}

void Cazador::jugar()
{
    bool empezar;
    dibujar(caracter);
    while (finJuego() == false)
    {
        empezar = salirFantasma(5);
        if (empezar == true)
        {     
            dibujar(' ');
            reescribirComida();
            colisionFantasma();   
            ContenedorDeDatos::getInst().conseguirPosicionFantasma(posx, posy);
            matarPacman();
            dibujar(caracter);
        }
        else
        {
            posx = 45;
            posy = 25;
        }
        this_thread::sleep_for(chrono::milliseconds(193));
    }
}

