#include "ListaScores.h"

ListaScores::ListaScores()
{

}

ListaScores::~ListaScores()
{

}

void ListaScores::conseguirLista()
{
    fstream archEntrada;
    int num;
    int puntaje;
    string nombre;
    int tiempo;

    archEntrada.open("scores.txt");

    if (!archEntrada.is_open())
    {
        cout << "no pudo abrir el archivo"; return;
    }

    while (!archEntrada.eof() && archEntrada>>num>>nombre>>puntaje>>tiempo) 
    {
        jugadores.registrar(new Jugador(nombre, puntaje, tiempo));
    }
    archEntrada.close();
}

void ListaScores::cambiarLista()
{
    jugadores.ordenar(Jugador::compPuntajeDesc);
}

void ListaScores::aumentarNuevoPuntaje(string nombre, int puntaje, int tiempo)
{
    Jugador* p1 = new Jugador(nombre,puntaje,tiempo);
    jugadores.registrar(p1);
}

void ListaScores::imprimirNuevaLista()
{
    fstream archSalida;
    int num;
    int puntaje;
    string nombre;
    int tiempo;

    archSalida.open("scores.txt");

    if (!archSalida.is_open())
    {
        cout << "no pudo abrir el archivo"; return;
    }
    Nodo<Jugador>* aux = jugadores.getPrimer();
    for (int i = 0; i < 10; i++)
    {
        archSalida<< i + 1 << " " << aux->getDato()->getNombre() << " "
            <<aux->getDato()->getPuntaje()<<" "<<aux->getDato()->getTiempo()<<endl;
        aux = aux->getSiguiente();
    }  
    archSalida.close();
}