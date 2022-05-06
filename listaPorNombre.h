#pragma once
#include <iostream>
#include <stdlib.h>
#include "nombre.h"

using namespace std;

class listaPorNombre
{
	private:
		nombre* cab;
		int largo;

	public:
		listaPorNombre();  // Constructor de la clase

		nombre* getCab();
		int getLargo();

		void setCab(nombre*);
		void setLargo(int);

		// **********Operaciones**********

		void agregarPeliculaPorNombre(pelicula*, int, string);
		void listarCatalogoPorNombre();
		void retirarPelicula(int);
		void modificarPelicula(pelicula*, int, string);
};

