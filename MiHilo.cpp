#include "MiHilo.h"

MiHilo::MiHilo()
{

}

MiHilo::~MiHilo()
{

}

void MiHilo::iniciar()
{
	t = new thread(ejecutarProcesar, this);
}

void MiHilo::join()
{
	t->join();
}

void MiHilo::ejecutarProcesar(MiHilo* h)
{
	h->jugar();
}