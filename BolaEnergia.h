#pragma once
#include "Comida.h"
class BolaEnergia :
    public Comida
{
private:

public:
    BolaEnergia(int posx, int posy, int color, char caracter,string tipo);
    ~BolaEnergia();
};

