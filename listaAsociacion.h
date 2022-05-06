#pragma once
#include <iostream>
#include <stdlib.h>
#include "asociacion.h"

using namespace std;

class listaAsociacion
{
	private:
		asociacion* cab;
		int largo;

	public:
		listaAsociacion(); // Constructor de la clase

		asociacion* getCab();
		int getLargo();

		void setCab(asociacion*);
		void setLargo(int);

		// **********Operaciones miscelaneas**********


};

