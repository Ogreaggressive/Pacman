#pragma once
#include "Fantasma.h"
class Emboscador :
    public Fantasma
{
private:
    mt19937 mtCambio;
    uniform_int_distribution<int> distCambio;
public:
    Emboscador(int posx, int posy, int color, char caracter);
    ~Emboscador();
    void siguienteCasilla();
    void jugar();
    void colisionFantasma();
};

