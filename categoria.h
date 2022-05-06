#pragma once
#include <iostream>
#include "pelicula.h"
#include <stdlib.h>

using namespace std;

class categoria
{
	private:
		string nombre;
		int cantPeliculasAsoc;
		pelicula* peliculas;

		categoria* sgte;

	public:
		categoria(); // constructor de la clase
		categoria(string, int); // constructor sobrecargado
		categoria(pelicula*);

		string getNombre();
		int getCantPeliculasAsoc();
		pelicula* getPelicula();
		categoria* getSgte();

		void setNombre(string);
		void setCantPeliculasAsoc(int);
		void setPelicula(pelicula*);
		void setSgte(categoria*);
};

