#include "listaAsociacion.h"

listaAsociacion::listaAsociacion()
{
    this->cab = NULL;
    this->largo = 0;
}

asociacion* listaAsociacion::getCab()
{
    return this->cab;
}

int listaAsociacion::getLargo()
{
    return this->largo;
}

void listaAsociacion::setCab(asociacion* _cab)
{
    this->cab = _cab;
}

void listaAsociacion::setLargo(int _largo)
{
    this->largo = _largo;
}

// ***************Operaciones miscelaneas***************