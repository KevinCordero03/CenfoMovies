#pragma once
#include <iostream>
#include <stdlib.h>
#include "pelicula.h"
#include "categoria.h"

using namespace std;

class asociacion
{
	private:
		int idAsociacion;
		int idPelicula;
		string nombreCategoria;
		pelicula* asocPelicula;
		categoria* asocCategoria;

		asociacion* sgte;
		asociacion* ante;

	public:
		asociacion();
		asociacion(int, int, string, pelicula*, categoria*);

		int getAsociacion();
		int getIdPelicula();
		string getNombreCategoria();
		pelicula* getAsocPelicula();
		categoria* getAsocCategoria();
		asociacion* getSgte();
		asociacion* getAnte();

		void setIdAsociacion(int);
		void setIdPelicula(int);
		void setNombreCategoria(string);
		void setAsocPelicula(pelicula*);
		void setAsocCategoria(categoria*);
		void setSgte(asociacion*);
		void setAnte(asociacion*);
};

