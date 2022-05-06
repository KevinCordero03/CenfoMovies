#include "categoria.h"

categoria::categoria()
{
    this->nombre = "";
    this->cantPeliculasAsoc = 0;
    this->peliculas = NULL;
}

categoria::categoria(string _nombre, int _asoc)
{
    this->nombre = _nombre;
    this->cantPeliculasAsoc = _asoc;
    this->peliculas = NULL;
}

categoria::categoria(pelicula* _pelicula)
{
    this->peliculas = NULL;
}

string categoria::getNombre()
{
    return this->nombre;
}

int categoria::getCantPeliculasAsoc()
{
    return this->cantPeliculasAsoc;
}

pelicula* categoria::getPelicula()
{
    return this->peliculas;
}

categoria* categoria::getSgte()
{
    return this->sgte;
}


void categoria::setNombre(string _nombre)
{
    this->nombre = _nombre;
}

void categoria::setCantPeliculasAsoc(int _cant)
{
    this->cantPeliculasAsoc = _cant;
}

void categoria::setPelicula(pelicula* _pelicula)
{
    this->peliculas = _pelicula;
}

void categoria::setSgte(categoria* _sgte)
{
    this->sgte = _sgte;
}

