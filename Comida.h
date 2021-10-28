#pragma once
#include "Objeto.h"
class Comida :
    public Objeto
{
protected:

public:
    Comida(int posx, int posy, int color, char caracter,string tipo);
    ~Comida();
};

