#pragma once
#include "Objeto.h"
class Pared :
    public Objeto
{
private:

public:
    Pared(int posx, int posy, int color, char caracter, string tipo);
    ~Pared();
    //void dibujar();
};

