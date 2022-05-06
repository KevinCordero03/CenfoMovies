#include "asociacion.h"

asociacion::asociacion()
{
    this->idAsociacion = 0;
    this->idPelicula = 0;
    this->nombreCategoria = "";
    this->asocPelicula = NULL;
    this->asocCategoria = NULL;
    this->sgte = NULL;
    this->ante = NULL;
}

asociacion::asociacion(int _idAsociacion, int _idPelicula, string _nombreCategoria, pelicula* _asocPelicula, categoria* _asocCategoria)
{
    this->idAsociacion = _idAsociacion;
    this->idPelicula = _idPelicula;
    this->nombreCategoria = _nombreCategoria;
    this->asocPelicula = _asocPelicula;
    this->asocCategoria = _asocCategoria;
    this->sgte = NULL;
    this->ante = NULL;
}

int asociacion::getAsociacion()
{
    return this->idAsociacion;
}

int asociacion::getIdPelicula()
{
    return this->idPelicula;
}

string asociacion::getNombreCategoria()
{
    return this->nombreCategoria;
}

pelicula* asociacion::getAsocPelicula()
{
    return this->asocPelicula;
}

categoria* asociacion::getAsocCategoria()
{
    return this->asocCategoria;
}

asociacion* asociacion::getSgte()
{
    return this->sgte;
}

asociacion* asociacion::getAnte()
{
    return this->ante;
}

void asociacion::setIdAsociacion(int _idAsociacion)
{
    this->idAsociacion = _idAsociacion;
}

void asociacion::setIdPelicula(int _idPelicula)
{
    this->idPelicula = _idPelicula;
}

void asociacion::setNombreCategoria(string _nombreCategoria)
{
    this->nombreCategoria = _nombreCategoria;
}

void asociacion::setAsocPelicula(pelicula* _asocPelicula)
{
    this->asocPelicula = _asocPelicula;
}

void asociacion::setAsocCategoria(categoria* _asocCategoria)
{
    this->asocCategoria = _asocCategoria;
}

void asociacion::setSgte(asociacion* _sgte)
{
    this->sgte = _sgte;
}

void asociacion::setAnte(asociacion* _ante)
{
    this->ante = _ante;
}
