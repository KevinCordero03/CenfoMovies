#include "asocPeliculaCategoria.h"

asocPeliculaCategoria::asocPeliculaCategoria()
{
    this->idAsociacion = 0;
    this->idPelicula = 0;
    this->nombreCategoria = "";
}

asocPeliculaCategoria::asocPeliculaCategoria(int _idAsociacion, int _idPelicula, string _NombreCategoria)
{
    this->idAsociacion = _idAsociacion;
    this->idPelicula = _idPelicula;
    this->nombreCategoria = _NombreCategoria;
}

int asocPeliculaCategoria::getIdAsociacion()
{
    return this->idAsociacion;
}

int asocPeliculaCategoria::getIdpelicula()
{
    return this->idPelicula;
}

string asocPeliculaCategoria::getNombreCategoria()
{
    return this->nombreCategoria;
}

void asocPeliculaCategoria::setIdAsociacion(int)
{
    this->idAsociacion;
}

void asocPeliculaCategoria::setIdPelicula(int)
{
    this->idPelicula;
}

void asocPeliculaCategoria::setNombreCategoria(string)
{
    this->nombreCategoria;
}
