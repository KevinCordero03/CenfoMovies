#include <iostream>
#include <stdlib.h>
#include "listaPeliculas.h"
#include "listaPorNombre.h"
#include <list>

listaPorNombre* LPN = new listaPorNombre();

listaPeliculas::listaPeliculas()
{
    this->cab = NULL;
    this->largo = 0;
}

pelicula* listaPeliculas::getCab()
{
    return this->cab;
}

int listaPeliculas::getLargo()
{
    return this->largo;
}

void listaPeliculas::setCab(pelicula* _cab)
{
    this->cab = _cab;
}

void listaPeliculas::setLargo(int _largo)
{
    this->largo = _largo;
}

// ***************Operaciones del TAD***************

bool listaPeliculas::agregarPelicula(int _id, string _nombre, int _anio, string _director, int _cantSolicitudes, int _cantCategorias)
{
    bool agregado = false;
    pelicula* nuevo = new pelicula(_id, _nombre, _anio, _director, _cantSolicitudes, _cantCategorias);
    pelicula* copia = nuevo;

	if (cab == NULL) {
		setCab(nuevo);
		setLargo(1);
		agregado = true;
	}
	else if (getLargo() == 1){
        if (_id < getCab()->getId()) {
            nuevo->setSgte(cab);
            nuevo->setAnte(NULL);
            cab->setAnte(nuevo);
            setCab(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
        else if (_id > getCab()->getId()) {
            nuevo->setSgte(NULL);
            nuevo->setAnte(cab);
            cab->setSgte(nuevo);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    else if (getLargo() > 1) {
        pelicula* aux = getCab();

        while (aux->getSgte() != NULL && !agregado) {
            if (_id < aux->getId()) {
                nuevo->setSgte(cab);
                nuevo->setAnte(NULL);
                cab->setAnte(nuevo);
                setCab(nuevo);
                setLargo(getLargo() + 1);
                agregado = true;
            }
            else if (_id > aux->getId() && _id < aux->getSgte()->getId()) {
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
        if (aux->getSgte() == NULL && _id > aux->getId()) {
            aux->setSgte(nuevo);
            nuevo->setAnte(aux);
            nuevo->setSgte(NULL);
            setLargo(getLargo() + 1);
            agregado = true;
        }
    }
    if (agregado) LPN->agregarPeliculaPorNombre(copia, copia->getId(), copia->getNombre());
    return agregado;
}

bool listaPeliculas::retirarPelicula(int _id)
{
    bool eliminada = false;
    pelicula* aux = getCab();

    LPN->retirarPelicula(_id);
   
    while (aux != NULL) {
        if (aux->getId() == _id) {
            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux == cab && largo > 1) {
                aux->getSgte()->setAnte(NULL);
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux->getSgte() != NULL) {
                aux->getAnte()->setSgte(aux->getSgte());
                aux->getSgte()->setAnte(aux->getAnte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux->getSgte() == NULL) {
                aux->getAnte()->setSgte(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
        }
        else {
            aux = aux->getSgte();
        }
    }
    return eliminada;
}

void listaPeliculas::consultarPelicula(int _id)
{
    pelicula* aux = getCab();
    bool encontrada = false;

    while (aux != NULL) {
        if (aux->getId() == _id) {
            cout << "Identificacion: " << aux->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
            cout << "Año de filmacion: " << aux->getAnio() << endl;
            cout << "Nombre del Director: " << aux->getDirector() << endl;
            cout << "Cantidad de veces que se ha solicitado: " << aux->getCantSolicitudes() << endl;
            cout << endl;
            encontrada = true;
            break;
        }
        else {
            aux = aux->getSgte();
        }
    }
    if (!encontrada) {
        cout << "No se pudo encontrar la pelicula en el catalogo" << endl;
    }
}

bool listaPeliculas::modificarPelicula(int _id)
{
    bool modificada = false;
    bool salir = false;
    pelicula* aux = getCab();

    while (aux != NULL && !modificada && !salir) {
        if (aux->getId() == _id) {
            int id = aux->getId();
            string nombre = aux->getNombre();;
            int anio = aux->getAnio();
            string director = aux->getDirector();
            int cantSolicitudes = aux->getCantSolicitudes();
            int cantCategorias = aux->getCantCategorias();
            int opc = 0;

            do {
                cout << "(1)  Modificar nombre de la pelicula " << endl;
                cout << "(2)  Modificar año de filamacion " << endl;
                cout << "(3)  Modificar nombre del director " << endl;
                cout << "(0)  Finalizar " << endl;
                cout << endl;
                cout << "OPCION SELECCIONADA-> "; cin >> opc;
                cout << endl << endl;
                cout << "_____________________________________________________________________";
                cout << endl << endl;

                switch (opc) {
                case 1: {
                    cout << "Ingresar el nuevo nombre: ";
                    cin >> nombre;
                    aux->setNombre(nombre);
                    LPN->modificarPelicula(aux, id, nombre);
                    modificada = true;
                    break;
                }
                case 2: {
                    cout << "Ingresar el nuevo año de filmacion: ";
                    cin >> anio;
                    aux->setAnio(anio);
                    modificada = true;
                    break;
                }
                case 3: {
                    cout << "Ingresar el nuevo nombre del director: ";
                    cin >> director;
                    aux->setDirector(director);
                    modificada = true;
                    break;
                }
                case 0: {
                    cout << "Finalizando modificacion.... Adios.... " << endl;
                    salir = true;
                    break;
                }
                default:
                    cout << "Opcion digitada no es válida " << endl;
                    break;
                }

                cout << endl << endl;

            } while (opc != 0);
        }
        else {
            aux = aux->getSgte();
        }
    }
    return modificada;
}

void listaPeliculas::listarCatalogoPorCodigo()
{
    pelicula* aux = getCab();
    cout << "Largo de la lista: " << largo << endl;
    cout << endl;

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL) {
            cout << "Identificacion: " << aux->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
            cout << "Año de filmacion: " << aux->getAnio() << endl;
            cout << "Nombre del Director: " << aux->getDirector() << endl;
            cout << "Cantidad de veces que se ha solicitado: " << aux->getCantSolicitudes() << endl;
            cout << endl;
            aux = aux->getSgte();
        }
        cout << "fin" << endl;
    }
}

void listaPeliculas::listarCatalogoPorNombre()
{
    LPN->listarCatalogoPorNombre();
}

void listaPeliculas::listarCatalogoPorHilera(string _nombre)
{
    pelicula* aux = getCab();

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL) {
            if (aux->getNombre() == _nombre) {
                cout << "Identificacion: " << aux->getId() << endl;
                cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
                cout << endl;
                aux = aux->getSgte();
            }
            else {
                aux = aux->getSgte();
            }
        }
        cout << "fin" << endl;
    }
}

void listaPeliculas::listarCatalogoPorRango(int _inferior, int _superior)
{
    pelicula* aux = getCab();

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL) {
            if (_inferior <= aux->getAnio() && aux->getAnio() <= _superior) {
                cout << "Identificacion: " << aux->getId() << endl;
                cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
                cout << "Año de filmacion: " << aux->getAnio() << endl;
                cout << "Nombre del Director: " << aux->getDirector() << endl;
                cout << "Cantidad de veces que se ha solicitado: " << aux->getCantSolicitudes() << endl;
                cout << endl;
                aux = aux->getSgte();
            }
            else {
                aux = aux->getSgte();
            }
        }
        cout << "fin" << endl;
    }
}

void listaPeliculas::listarCatalogoPorLimite(int _anio)
{
    pelicula* aux = getCab();

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL && aux->getAnio() < _anio) {
            cout << "Identificacion: " << aux->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
            cout << endl;
            aux = aux->getSgte();
        }
        cout << "fin" << endl;
    }
}

void listaPeliculas::listarPeliculasSinCategoria()
{
    pelicula* aux = getCab();

    if (aux == NULL) {
        cout << "Esta vacia la lista" << endl;;
    }
    else {
        while (aux != NULL && aux->getCantCategorias() == 0) {
            cout << "Identificacion: " << aux->getId() << endl;
            cout << "Nombre de la pelicula: " << aux->getNombre() << endl;
            cout << endl;
            aux = aux->getSgte();
        }
        cout << "fin" << endl;
    }
}

bool listaPeliculas::eliminarPeliculasPorLimite(int _limite)
{
    bool eliminada = false;
    bool borrada = false;
    pelicula* aux = getCab();
    pelicula* sgte = NULL;
    bool eliminadaNombre = false;

    while (aux != NULL) {
        borrada = false;
        if (aux->getAnio() < _limite) {

            LPN->retirarPelicula(aux->getId());

            if (aux == cab && largo == 1) {
                setCab(NULL);
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                break;
            }
            if (aux == cab && largo > 1) {
                aux->getSgte()->setAnte(NULL);
                setCab(aux->getSgte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                aux = getCab();
            }
            if (aux->getSgte() != NULL && aux != cab && !borrada) {
                sgte = aux->getSgte();
                aux->getAnte()->setSgte(aux->getSgte());
                aux->getSgte()->setAnte(aux->getAnte());
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                borrada = true;
                aux = sgte;
            }
            if (aux->getSgte() == NULL && aux != cab && !borrada) {
                aux->getAnte()->setSgte(NULL);  
                delete aux;
                setLargo(getLargo() - 1);
                eliminada = true;
                aux = NULL;
            }
        }
        else {
            aux = aux->getSgte();
        }
    }
    return eliminada;
}

bool listaPeliculas::elegirPelicula(int _id)
{
    bool elegida = false;
    pelicula* aux = getCab();
    bool encontrada = false;

    while (aux != NULL) {
        if (aux->getId() == _id) {
            aux->setCantSolicitudes(aux->getCantSolicitudes() + 1);
            elegida = true;
            break;
        }
        else {
            aux = aux->getSgte();
        }
    }
    return elegida;
}

void listaPeliculas::ordenarPorNombre(pelicula*& _puntero)
{
   
}
