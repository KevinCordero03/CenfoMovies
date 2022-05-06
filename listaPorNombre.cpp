#include <iostream>
#include <stdlib.h>
#include "listaPorNombre.h"
#include "pelicula.h"

listaPorNombre::listaPorNombre()
{
    this->cab = NULL;
    this->largo = 0;
}

nombre* listaPorNombre::getCab()
{
    return this->cab;
}

int listaPorNombre::getLargo()
{
    return this->largo;
}

void listaPorNombre::setCab(nombre* _cab)
{
    this->cab = _cab;
}

void listaPorNombre::setLargo(int _largo)
{
    this->largo = _largo;
}

// ***************Operaciones***************

void listaPorNombre::agregarPeliculaPorNombre(pelicula* _aux, int _idPelicula, string _nombrePelicula)
{
    bool agregado = false;
    nombre* nuevo = new nombre(_aux, _idPelicula, _nombrePelicula);

    if (cab == NULL) {
        setCab(nuevo);
        setLargo(1);
        agregado = true;
    }
    else if (getLargo() == 1) {
        if (_nombrePelicula.compare(getCab()->getDato()->getNombre()) < 0) {
            nuevo->setSgte(cab);
            nuevo->setAnte(NULL);
            cab->setAnte(nuevo);
            setCab(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
        else if (_nombrePelicula.compare(getCab()->getDato()->getNombre()) > 0) {
            nuevo->setSgte(NULL);
            nuevo->setAnte(cab);
            cab->setSgte(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    else if (getLargo() > 1) {
        nombre* aux = getCab();

        while (aux->getSgte() != NULL && !agregado) {
            if (_nombrePelicula.compare(aux->getDato()->getNombre()) < 0) {
                nuevo->setSgte(cab);
                nuevo->setAnte(NULL);
                cab->setAnte(nuevo);
                setCab(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else if ((_nombrePelicula.compare(aux->getDato()->getNombre()) > 0) && (_nombrePelicula.compare(aux->getSgte()->getDato()->getNombre()) < 0)) {
                nuevo->setSgte(aux->getSgte());
                nuevo->setAnte(aux);
                aux->getSgte()->setAnte(nuevo);
                aux->setSgte(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else {
                aux = aux->getSgte();
            }
        }
        if (aux->getSgte() == NULL && _nombrePelicula.compare(aux->getDato()->getNombre()) > 0) {
            aux->setSgte(nuevo);
            nuevo->setAnte(aux);
            nuevo->setSgte(NULL);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
}

void listaPorNombre::listarCatalogoPorNombre()
{
    nombre* aux = getCab();
    cout << "Largo de la lista: " << largo << endl;
    cout << endl;

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;
    }
    else {
        while (aux != NULL) {
            cout << "Identificacion: " << aux->getDato()->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getDato()->getNombre() << endl;
            cout << "Año de filmacion: " << aux->getDato()->getAnio() << endl;
            cout << "Nombre del Director: " << aux->getDato()->getDirector() << endl;
            cout << "Cantidad de veces que se ha solicitado: " << aux->getDato()->getCantSolicitudes() << endl;
            cout << endl;
            aux = aux->getSgte();
        }
        cout << "fin" << endl;
    }
}

void listaPorNombre::retirarPelicula(int _id)
{
    nombre* aux = getCab();

    while (aux != NULL) {
        if (aux->getIdPelicula() == _id) {
            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux == cab && largo > 1) {
                aux->getSgte()->setAnte(NULL);
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux->getSgte() != NULL) {
                aux->getAnte()->setSgte(aux->getSgte());
                aux->getSgte()->setAnte(aux->getAnte());
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
            if (aux->getSgte() == NULL) {
                aux->getAnte()->setSgte(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                break;
            }
        }
        else {
            aux = aux->getSgte();
        }
    }
}

void listaPorNombre::modificarPelicula(pelicula* _aux, int _id, string _nombre)
{
    nombre* aux = getCab();
    nombre* temp = NULL;

    while (aux != NULL) {
        if (aux->getIdPelicula() == _id) {
            retirarPelicula(_id);
            agregarPeliculaPorNombre(_aux, _id, _nombre);
            break;
        }
        else {
            aux = aux->getSgte();
        }
    }
}

