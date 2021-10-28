#include "Bobo.h"

Bobo::Bobo(int posx, int posy, int color, char caracter) :Fantasma(posx, posy, color, caracter), mtCambio(1729), distCambio(0, 2)
{

}

Bobo::~Bobo()
{

}


void Bobo::siguienteCasilla()
{
    int mX = distCambio(mtCambio)-1;
    int mY = distCambio(mtCambio)-1;
    posx += mX;
    posy += mY;
}

void Bobo::colisionFantasma()
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

void Bobo::jugar()
{
    bool empezar;
    dibujar(caracter);
	while(finJuego() == false)
	{
        empezar=salirFantasma(10);
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
        this_thread::sleep_for(chrono::milliseconds(211));
	}
}


