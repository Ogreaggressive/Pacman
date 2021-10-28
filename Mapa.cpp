#include "Mapa.h"

Mapa::Mapa() :alimentos(), bolasEnergia(), paredes()
{

}

Mapa::~Mapa()
{

}


Mapa& Mapa::getInst()
{
    static Mapa instancia;
    return instancia;
}

void Mapa::conseguirMapa()
{
    fstream archEntrada;
    char objeto;
    int contx = 0;
    int conty = 0;
    archEntrada.open("mapa.txt");

    if (!archEntrada.is_open())
    {
        cout << "no pudo abrir el archivo"; return;
    }

    while (!archEntrada.eof() && archEntrada.get(objeto)) {
        if (objeto == '*')
        {
            paredes.registrar(new Pared(contx,conty,7,'*',"pared"));
            //cout <<"registrando en pos:" << "x:"<<contx << "y:" << conty << endl;
        }
        if (objeto == '.')
        {
            alimentos.registrar(new Alimento(contx, conty, 7, '.',"alimento"));
        }
        if (objeto == '&')
        {
            bolasEnergia.registrar(new BolaEnergia(contx, conty, 7, '&',"bolaEnergia"));
        }
        contx += 1;
        if (objeto == ',')
        {
            conty += 1;
            contx = -1;
        }
    }
    archEntrada.close();
}

void Mapa::dibujarParedes()
{
    Nodo<Pared>* aux = paredes.getPrimer();
    for (int i = 0; i < paredes.getTam(); i++)
    {
        aux->getDato()->dibujar();
        aux=aux->getSiguiente();
    }
}

void Mapa::dibujarAlimentos()
{
    Nodo<Alimento>* aux = alimentos.getPrimer();
    for (int i = 0; i < alimentos.getTam(); i++)
    {
        aux->getDato()->dibujar();
        aux = aux->getSiguiente();
    }
}

void Mapa::dibujarBolasEnergia()
{
    Nodo<BolaEnergia>* aux = bolasEnergia.getPrimer();
    for (int i = 0; i < bolasEnergia.getTam(); i++)
    {
        aux->getDato()->dibujar();
        aux = aux->getSiguiente();
    }
}
void Mapa::dibujar()
{
    dibujarParedes();
    dibujarAlimentos();
    dibujarBolasEnergia();
}


bool Mapa::colision(int x, int y)
{
    Nodo<Pared>* aux = paredes.getPrimer();
    for (int i = 0; i < paredes.getTam(); i++)
    {
        if (aux->getDato()->getPosX() == x && aux->getDato()->getPosY() == y)
        {
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

void Mapa::comerAlimento(int x, int y)
{
    Nodo<Alimento>* aux = alimentos.getPrimer();
    for (int i = 0; i < alimentos.getTam(); i++)
    {
        if (aux->getDato()->getPosX() == x && aux->getDato()->getPosY() == y
            && aux->getDato()->getCar()=='.')
        {
            aux->getDato()->cambiarCaracter(' ');
        }
        aux = aux->getSiguiente();
    }
}

void Mapa::reescribirPared(int x, int y)
{
    Nodo<Pared>* aux = paredes.getPrimer();
    for (int i = 0; i < paredes.getTam(); i++)
    {
        if (aux->getDato()->getPosX() == x && aux->getDato()->getPosY() == y)
        {
            aux->getDato()->dibujar();
        }
        aux = aux->getSiguiente();
    }
}

void Mapa::reescribirAlimento(int x, int y)
{
    Nodo<Alimento>* aux = alimentos.getPrimer();
    for (int i = 0; i < alimentos.getTam(); i++)
    {
        if (aux->getDato()->getPosX() == x && aux->getDato()->getPosY() == y
            && aux->getDato()->getCar() == '.')
        {
            aux->getDato()->dibujar();
        }
        aux = aux->getSiguiente();
    }
}

void Mapa::conseguirPuntaje()
{
    Nodo<Alimento>* aux = alimentos.getPrimer();
    for (int i = 0; i < alimentos.getTam(); i++)
    {
        if (aux->getDato()->getCar() == ' ')
        {
            ContenedorDeDatos::getInst().aumentarPuntaje(5);
        }
        aux = aux->getSiguiente();
    }
}

void Mapa::comerBolaEnergia(int x, int y)
{
    Nodo<BolaEnergia>* aux = bolasEnergia.getPrimer();
    for (int i = 0; i < bolasEnergia.getTam(); i++)
    {
        if (aux->getDato()->getPosX() == x && aux->getDato()->getPosY() == y
            && aux->getDato()->getCar() == '&')
        {
            aux->getDato()->cambiarCaracter(' ');
            ContenedorDeDatos::getInst().activarInvencible();
        }
        aux = aux->getSiguiente();
    }
}