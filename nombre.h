#pragma once
#include <iostream>
#include <stdlib.h>
#include "pelicula.h"

using namespace std;

class nombre
{
private:
	pelicula* dato;
	int idPelicula;
	string nombrePelicula;

	nombre* sgte;
	nombre* ante;

public:
	nombre(); // constructor de la clase
	nombre(pelicula*, int, string); // constructor sobrecargado

	pelicula* getDato();
	int getIdPelicula();
	string getNombrePelicula();
	nombre* getSgte();
	nombre* getAnte();

	void setNombre(pelicula*);
	void setIdPelicula(int);
	void setNombrePelicula(string);
	void setSgte(nombre*);
	void setAnte(nombre*);
};

