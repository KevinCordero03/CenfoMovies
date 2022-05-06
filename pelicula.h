#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

class pelicula
{
	private:
		int id;
		string nombre;
		int anio;
		string director;
		int cantSolicitudes;
		int cantCategorias;

		pelicula* sgte;
		pelicula* ante;

	public:
		pelicula(); // constructor de la clase
		pelicula(int, string, int, string, int, int); // constructor sobrecargado

		int getId();
		string getNombre();
		int getAnio();
		string getDirector();
		int getCantSolicitudes();
		int getCantCategorias();
		pelicula* getSgte();
		pelicula* getAnte();

		void setId(int);
		void setNombre(string);
		void setAnio(int);
		void setDirector(string);
		void setCantSolicitudes(int);
		void setCantCategorias(int);
		void setSgte(pelicula*);
		void setAnte(pelicula *);
};
