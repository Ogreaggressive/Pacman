#pragma once
#include "Personaje.h"
#include <conio.h>

class Pacman :
    public Personaje
{
private:
    bool invencible;
    int time;
public:
    Pacman(int posx, int posy, int color, char caracter);
    ~Pacman();
    void jugar();
    void colisionPacman();
    void conseguirBolaEnergia();
    void moverPersonaje();
};

