#include "pelicula.h"

pelicula::pelicula()
{
    this->id = 0;
    this->nombre = "";
    this->anio = 0;
    this->director = "";
    this->cantSolicitudes = 0;
    this->cantCategorias = 0;
    this->sgte = NULL;
    this->ante = NULL;
}

pelicula::pelicula(int _id, string _nombre, int _anio, string _director, int _cantSolicitudes, int _cantCategorias)
{
    this->id = _id;
    this->nombre = _nombre;
    this->anio = _anio;
    this->director = _director;
    this->cantSolicitudes = _cantSolicitudes;
    this->cantCategorias = _cantCategorias;
    this->sgte = NULL;
    this->ante = NULL;
}

int pelicula::getId()
{
    return this->id;
}

string pelicula::getNombre()
{
    return this->nombre;
}

int pelicula::getAnio()
{
    return this->anio;
}

string pelicula::getDirector()
{
    return this->director;
}

int pelicula::getCantSolicitudes()
{
    return this->cantSolicitudes;
}

int pelicula::getCantCategorias()
{
    return this->cantCategorias;
}

pelicula* pelicula::getSgte()
{
    return this->sgte;
}

pelicula* pelicula::getAnte()
{
    return this->ante;
}

void pelicula::setId(int _id)
{
    this->id = _id;
}

void pelicula::setNombre(string _nombre)
{
    this->nombre = _nombre;
}

void pelicula::setAnio(int _anio)
{
    this->anio = _anio;
}

void pelicula::setDirector(string _director)
{
    this->director = _director;
}

void pelicula::setCantSolicitudes(int _cantSolicitudes)
{
    this->cantSolicitudes = _cantSolicitudes;
}

void pelicula::setCantCategorias(int _cantCategorias)
{
    this->cantCategorias = _cantCategorias;
}

void pelicula::setSgte(pelicula* _sgte)
{
    this->sgte = _sgte;
}

void pelicula::setAnte(pelicula* _ante)
{
    this->ante = _ante;
}
