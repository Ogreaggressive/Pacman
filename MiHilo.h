#pragma once

#include "Formato.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <random>

using namespace std;

class MiHilo
{
private:
	thread* t;
public:
	MiHilo();
	~MiHilo();
	void iniciar();
	void join();
private:
	static void ejecutarProcesar(MiHilo* h);
protected:
	virtual void jugar() = 0;
};

