#include "nombre.h"

nombre::nombre()
{
	this->dato = NULL;
	this->nombrePelicula = "";
	this->idPelicula = 0;
	this->sgte = NULL;
	this->ante = NULL;
}

nombre::nombre(pelicula* _dato, int _idPelicula, string _nombrePelicula)
{
	this->dato = _dato;
	this->idPelicula = _idPelicula;
	this->nombrePelicula = _nombrePelicula;
	this->sgte = NULL;
	this->ante = NULL;
}

pelicula* nombre::getDato()
{
	return this->dato;
}

int nombre::getIdPelicula()
{
	return this->idPelicula;
}

string nombre::getNombrePelicula()
{
	return this->nombrePelicula;
}

nombre* nombre::getSgte()
{
	return this->sgte;
}

nombre* nombre::getAnte()
{
	return this->ante;
}

void nombre::setNombre(pelicula* _dato)
{
	this->dato = _dato;
}

void nombre::setIdPelicula(int _idPelicula)
{
	this->idPelicula = _idPelicula;
}

void nombre::setNombrePelicula(string _nombrePelicula)
{
	this->nombrePelicula = _nombrePelicula;
}

void nombre::setSgte(nombre* _sgte)
{
	this->sgte = _sgte;
}

void nombre::setAnte(nombre* _ante)
{
	this->ante = _ante;
}
