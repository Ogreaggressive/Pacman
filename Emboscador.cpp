#include "Emboscador.h"

Emboscador::Emboscador(int posx, int posy, int color, char caracter) :Fantasma(posx, posy, color, caracter), mtCambio(1729), distCambio(1, 2)
{

}

Emboscador::~Emboscador()
{

}

void Emboscador::siguienteCasilla()
{
    int x, y;
    x = ContenedorDeDatos::getInst().getPosXFantasma();
    y = ContenedorDeDatos::getInst().getPosYFantasma();
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

void Emboscador::colisionFantasma()
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

void Emboscador::jugar()
{
    bool empezar;
    dibujar(caracter);
    while (finJuego() == false)
    {
        empezar = salirFantasma(15);
        if (empezar == true)
        {
            dibujar(' ');
            reescribirComida();
            colisionFantasma();
            matarPacman();
            dibujar(caracter);
        }
        else
        {
            posx = 45;
            posy = 25;
        }
        this_thread::sleep_for(chrono::milliseconds(197));
    }
}

