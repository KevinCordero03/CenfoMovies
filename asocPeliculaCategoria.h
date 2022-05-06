#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class asocPeliculaCategoria
{
	private:
		int idAsociacion;
		int idPelicula;
		string nombreCategoria;

		asocPeliculaCategoria* sgte;
		asocPeliculaCategoria* ante;

	public:
		asocPeliculaCategoria();
		asocPeliculaCategoria(int, int, string);

		int getIdAsociacion();
		int getIdpelicula();
		string getNombreCategoria();

		void setIdAsociacion(int);
		void setIdPelicula(int);
		void setNombreCategoria(string);
};

