#pragma once
#include "Comida.h"
class Alimento :
    public Comida
{
private:

public:
    Alimento(int posx, int posy, int color, char caracter,string tipo);
    ~Alimento();
};

