#pragma once
#include "Personaje.h"
class Fantasma :
    public Personaje
{
protected:
    bool comido;
public:
    Fantasma(int posx, int posy, int color, char caracter);
    ~Fantasma();
    void jugar()=0;
    virtual void siguienteCasilla() = 0;
    virtual void colisionFantasma() = 0;
    bool salirFantasma(int tiempo);
    void reescribirComida();
    void matarPacman();
};

