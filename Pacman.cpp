#include "Pacman.h"

Pacman::Pacman(int posx, int posy, int color, char caracter) :Personaje(posx,posy,color,caracter)
{
    time = 15;
    invencible = false;
}

Pacman::~Pacman()
{

}

void Pacman::conseguirBolaEnergia()
{
    ContenedorDeDatos::getInst().desactivarInvencible();
    invencible=ContenedorDeDatos::getInst().getInvencible();
    if (invencible == true)
    {
        color = 2;
    }
    else
    {
        color = 7;
    }
}

void Pacman::moverPersonaje()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            moverIzquierda();
            break;
        case 'd':
            moverDerecha();
            break;
        case 'w':
            moverArriba();
            break;
        case 's':
            moverAbajo();
            break;
        }
    }
}

void Pacman::colisionPacman()
{
    if (quedarseQuieto() == false)
    {
        posicionAnterior();
        moverPersonaje();
    }
    else
    {
        Mapa::getInst().reescribirPared(posx, posy);
        posx = posAnteriorX;
        posy = posAnteriorY;
    }
}


void Pacman::jugar()
{
    int x=posx, y=posy;
    while (finJuego() == false)
    {
        dibujar(' ');
        colisionPacman();
        Mapa::getInst().comerAlimento(posx,posy);
        Mapa::getInst().comerBolaEnergia(posx,posy);
        conseguirBolaEnergia();
        ContenedorDeDatos::getInst().conseguirPosicionPacman(posx,posy);
        dibujar(caracter);
        this_thread::sleep_for(chrono::milliseconds(53));
    }
}
