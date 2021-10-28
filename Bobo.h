#pragma once
#include "Fantasma.h"



class Bobo :
    public Fantasma
{
private:
    mt19937 mtCambio;
    uniform_int_distribution<int> distCambio;
public:
    Bobo(int posx, int posy, int color, char caracter);
    ~Bobo();
    void siguienteCasilla();
    void jugar();
    void colisionFantasma();
};

