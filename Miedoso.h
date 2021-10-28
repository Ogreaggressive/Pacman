#pragma once
#include "Fantasma.h"
class Miedoso :
    public Fantasma
{
private:
    mt19937 mtCambio;
    uniform_int_distribution<int> distCambio;
public:
    Miedoso(int posx, int posy, int color, char caracter);
    ~Miedoso();
    void siguienteCasilla();
    void jugar();
    void colisionFantasma();
};

