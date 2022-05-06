#pragma once
#include <iostream>
#include <stdlib.h>
#include "categoria.h"

using namespace std;

class listaCategorias
{
	private:
		categoria* cab;
		int largo;


	public:
		listaCategorias(); // Constructor de la clase

		categoria* getCab();
		int getLargo();

		void setCab(categoria*);
		void setLargo(int);

		// **********Operaciones del TAD**********

		bool agregarCategoria(string, int);
		bool cerrar(string);
		bool modificarCategoria(string);
		void consultarCategoria(string);
		void catalogoCategorias();
		void asociarPelicula(int, string);
		void eliminarPelicula(int, string);
		void consultarPeliculaCategoria(string);
		void catalogoCategoriasDetalles();
};

