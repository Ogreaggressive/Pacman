#pragma once
#include "Fantasma.h"
class Cazador :
    public Fantasma
{
private:
    mt19937 mtCambio;
    uniform_int_distribution<int> distCambio;
public:
    Cazador(int posx, int posy, int color, char caracter);
    ~Cazador();
    void siguienteCasilla();
    void jugar();
    void colisionFantasma();
};

