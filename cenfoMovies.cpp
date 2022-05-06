// cenfoMovies.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <ios>

using namespace std;

#include "pelicula.h"
#include "listaPeliculas.h"
#include "listaCategorias.h"
#include "listaPorNombre.h"
#include "logica.h"

listaPeliculas* LP = new listaPeliculas();
listaCategorias* LC = new listaCategorias();
//listaPorNombre* LN = new listaPorNombre();

void menuMantenimientoPeliculas(listaPeliculas*& LP, listaCategorias*& LC) {
    int opc = 0;
    do {
        cout << "OPERACIONES DE PELICULAS " << endl;
        cout << endl;
        cout << "(1)  Agregar a la lista " << endl;
        cout << "(2)  Retirar de la lista " << endl;
        cout << "(3)  Consultar la lista " << endl;
        cout << "(4)  Modificar la lista " << endl;
        cout << "(5)  Listado catalogo completo en forma ascendente (descendente) por codigo " << endl;
        cout << "(6)  Listado catalogo completo en forma ascendente (descendente) por nombre " << endl;
        cout << "(7)  Listar peliculas cuyo nombre contenga una hilera especifica " << endl;
        cout << "(8)  Listado de catalogo de peliculas de un rango de años especifico " << endl;
        cout << "(9)  Listar peliculas cuya solicitud sean inferior a un limite dado de fecha de filmacion " << endl;
        cout << "(10) Eliminar de la lista las peliculas cuya solicitud sea inferior a un limite dado de fecha de filmacion " << endl;
        cout << "(11) Listado de peliculas sin categoria asignada " << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                cout << "Agregar a la lista " << endl;
                int id;
                cout << "Por favor ingresar el número identificador de la película: " << endl;
                cin >> id;
                string nombre;
                cout << "Por favor ingresar el nombre de la película: " << endl;
                cin >> nombre;
                int anio;
                cout << "Por favor ingresar el año en que se filmó la película: " << endl;
                cin >> anio;
                string director;
                cout << "Por favor ingresar el nombre del director de la película: " << endl;
                cin >> director;
                int cantSolicitudes = 0;
                int cantCategorias = 0;
                bool agregado = LP->agregarPelicula(id, nombre, anio, director, cantSolicitudes, cantCategorias);

                if (agregado) {
                    cout << "La pelicula ha sido ingresada con exito al catalogo";
                }
                else {
                    cout << "La pelicula no se ha podido ingresar, por favor revisar los datos proporcionados";
                }
                break;
            }

            case 2: {
                cout << "Retirar de la lista " << endl << endl;
                int id;
                cout << "Ingrese el codigo de la pelicula a eliminar: ";
                cin >> id;
                bool eliminada = LP->retirarPelicula(id);
                if (eliminada) {
                    cout << "La pelicula " << id << " ha sido eliminada del catalogo" << endl;
                }
                else {
                    cout << "No se ha podido eliminar la pelicula";
                }
                break;
            }
            case 3: {
                cout << "Consultar la lista " << endl;
                int id;
                cout << "Ingrese el codigo de la pelicula a consultar: ";
                cin >> id;
                cout << endl;
                LP->consultarPelicula(id);
                break;
            }
            case 4: {
                cout << "Modificar la lista " << endl;
                int id;
                cout << "Ingrese el codigo de la pelicula a modificar: ";
                cin >> id;
                cout << endl;
                bool modificada = LP->modificarPelicula(id);
                if (modificada) {
                    cout << "La pelicula " << id << " ha sido modificada exitosamente" << endl;
                }
                else {
                    cout << "No se ha podido modificar la pelicula";
                }
                break;
            }
            case 5: {
                cout << "Listado catalogo completo en forma ascendente por codigo " << endl << endl;
                LP->listarCatalogoPorCodigo();
                break;
            }
            case 6: {
                cout << "Listado catalogo completo en forma ascendente por nombre " << endl << endl;
                LP->listarCatalogoPorNombre();
                break;
            }
            case 7: {
                cout << "Listar peliculas cuyo nombre contenga una hilera especifica " << endl;
                string nombre;
                cout << "Ingrese la palabra o hilera que desea buscar: ";
                cin >> nombre;
                cout << endl;
                LP->listarCatalogoPorHilera(nombre);
                break;
            }
            case 8: {
                cout << "Listado de catalogo de peliculas de un rango de años especifico " << endl;
                int inferior;
                cout << "Ingrese el año limite inferior: ";
                cin >> inferior;
                int superior;
                cout << "Ingrese el año limite superior: ";
                cin >> superior;
                cout << endl;
                LP->listarCatalogoPorRango(inferior, superior);
                break;
            }
            case 9: {
                cout << "Listar peliculas cuya solicitud sean inferior a un limite dado según el año de filmación " << endl;
                int anio;
                cout << "Ingrese el año limite: ";
                cin >> anio;
                cout << endl;
                LP->listarCatalogoPorLimite(anio);
                break;
            }
            case 10: {
                cout << "Eliminar de la lista las peliculas cuya solicitud sea inferior a un limite dado de fecha de filmacion " << endl;
                int anio;
                cout << "Ingrese el limite de año: ";
                cin >> anio;
                cout << endl;
                bool modificada = LP->eliminarPeliculasPorLimite(anio);
                if (modificada) {
                    cout << "Las peliculas filmadas antes de: " << anio << " ha sido eliminadas exitosamente" << endl;
                }
                else {
                    cout << "No se ha podido eliminar las peliculas";
                }
                break;
            }
            case 11: {
                cout << "Listado de peliculas sin categoria asignada " << endl;
                cout << endl;
                LP->listarPeliculasSinCategoria();
                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
            }

        cout << endl << endl;

    } while (opc != 0);
}

void menuMantenimientoCategorias(listaPeliculas*& LP, listaCategorias*& LC) {
    int opc = 0;
    do {
        cout << "OPERACIONES DE CATEGORIAS " << endl;
        cout << endl;
        cout << "(1)  Agregar a la categoria " << endl;
        cout << "(2)  Cerrar una categoria " << endl;
        cout << "(3)  Modificar la categoria " << endl;
        cout << "(4)  Consultar las categorias " << endl;
        cout << "(5)  Catalogo de categorias (nombre y cantidad de peliculas asociadas) " << endl;
        cout << "(6)  Agregar pelicula a una categoria " << endl;
        cout << "(7)  Retirar pelicula de una categoria " << endl;
        cout << "(8)  Consultar peliculas de una categoria en especifica " << endl;
        cout << "(9) Catalogo de categorias con detalle completo de sus peliculas " << endl;
        cout << "(0) Terminar" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;

        switch (opc) {
        case 1: {
            cout << "Agregar a la categoria " << endl;
            string nombre;
            cout << "Por favor ingresar el nombre de la categoria: " << endl;
            cin >> nombre;
            int cantPeliculas = 0;
            int cantCategorias = 0;
            bool agregado = LC->agregarCategoria(nombre, cantPeliculas);
            if (agregado) {
                cout << "La categoria ha sido ingresada con exito al catalogo";
            }
            else {
                cout << "La categoria no se ha podido ingresar, por favor revisar los datos proporcionados";
            }
            break;
        }

        case 2: {
            cout << "Cerrar una categoria " << endl;
            string nombre;
            cout << "Ingrese el nombre de la categoria a eliminar: ";
            cin >> nombre;
            bool eliminada = LC->cerrar(nombre);
            if (eliminada) {
                cout << "La categoria " << nombre << " ha sido eliminada del catalogo" << endl;
            }
            else {
                cout << "No se ha podido eliminar la categoria";
            }
            break;
        }
        case 3: {
            cout << "Modificar la categoria " << endl;
            string nombre;
            cout << "No se pueden modificar las categorias: ";
            break;
        }
        case 4: {
            cout << "Consultar las categorias " << endl;
            string nombre;
            cout << "Ingrese el codigo de la categoria a consultar: ";
            cin >> nombre;
            cout << endl;
            LC->consultarCategoria(nombre);
            break;
        }
        case 5: {
            cout << "Catalogo de categorias (nombre y cantidad de peliculas asociadas) " << endl;
            cout << "Listado catalogo completo en forma ascendente por nombre " << endl << endl;
            LC->catalogoCategorias();
            break;
        }
        case 6: {
            cout << "Agregar pelicula a una categoria " << endl;
            int id;
            cout << "Ingrese el id de la pelicula a agregar: ";
            cin >> id;
            string nombre;
            cout << "Ingrese el nombre de la categoría a la que desea agregar la pelicula: ";
            cin >> nombre;
            LC->asociarPelicula(id, nombre);
            break;
        }
        case 7: {
            cout << "Retirar pelicula de una categoria " << endl;
            int id;
            cout << "Ingrese el id de la pelicula a eliminar: ";
            cin >> id;
            string nombre;
            cout << "Ingrese el nombre de la categoría de la que desea eliminar la pelicula: ";
            cin >> nombre;
            LC->eliminarPelicula(id, nombre);
            break;
        }
        case 8: {
            cout << "Consultar peliculas de una categoria en especifica " << endl;
            string nombre;
            cout << "Ingrese el nombre de la categoria a consultar: ";
            cin >> nombre;
            LC->consultarPeliculaCategoria(nombre);
            break;
        }
        case 9: {
            cout << "Catalogo de categorias con detalle completo de sus peliculas " << endl;
            LC->catalogoCategoriasDetalles();
            break;
        }
        case 0: {
            cout << "Finalizando aplicacion.... Adios.... " << endl;
            break;
        }
        default:
            cout << "Opcion digitada no es valida " << endl;
            break;
        }

        cout << endl << endl;

    } while (opc != 0);
}

void menuAdministrador() {
    string usuario;
    string password;
    int tipo = 1;
    char sp = '*';

    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese su password: ";
    password = passwordDelUsuario(sp);
    bool valido = validarCredenciales(usuario, password, tipo);

    if (valido) {
        int opc = 0;
        do {
            cout << "OPERACIONES DE MANTENIMIENTO " << endl;
            cout << endl;
            cout << "(1)  Mantenimiento a peliculas " << endl;
            cout << "(2)  Mantenimiento a categorias " << endl;
            cout << "(0)  Terminar" << endl;
            cout << endl;
            cout << "OPCION SELECCIONADA-> "; cin >> opc;
            cout << endl << endl;
            cout << "_____________________________________________________________________";
            cout << endl << endl;

            switch (opc) {
            case 1: {
                menuMantenimientoPeliculas(LP, LC);
                break;
            }

            case 2: {
                menuMantenimientoCategorias(LP, LC);
                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
            }

            cout << endl << endl;

        } while (opc != 0);
    }
    else {
        cout << "Los credenciales no son validos" << endl;
    }
}

void menuCliente(listaPeliculas*& LP, listaCategorias*& LC) {
    string usuario;
    string password;
    int tipo = 2;
    char sp = '*';

    cout << "Ingrese el nombre de usuario: ";
    cin >> usuario;
    cout << "Ingrese su password: ";
    password = passwordDelUsuario(sp);
    bool valido = validarCredenciales(usuario, password, tipo);

    if (valido) {
        int opc = 0;
        do {
            cout << "OPERACIONES DE CONSULTA " << endl;
            cout << endl;
            cout << "(1)   Elegir pelicula " << endl;
            cout << "(2)   Consultar pelicula " << endl;
            cout << "(3)   Listar catalogo de peliculas por codigo " << endl;
            cout << "(4)   Listar catalogo de peliculas por nombre " << endl;
            cout << "(5)   Listar catalogo de peliculas por hilera " << endl;
            cout << "(6)   Listar peliculas por rango de año " << endl;
            cout << "(7)   Listar peliculas por limite de año " << endl;
            cout << "(8)   Listar peliculas sin categoria " << endl;
            cout << "(9)   Consultar categoria " << endl;
            cout << "(10)  Listar catalogo de categorias " << endl;
            cout << "(11)  Consultar peliculas por categoria " << endl;
            cout << "(12)  Consultar catalogo de categorias con codigo y nombre de peliculas " << endl;
            cout << "(13)  Consultar catalogo de categorias con todos los detalles de peliculas " << endl;
            cout << "(0)   Terminar" << endl;
            cout << endl;
            cout << "OPCION SELECCIONADA-> "; cin >> opc;
            cout << endl << endl;
            cout << "_____________________________________________________________________";
            cout << endl << endl;

            switch (opc) {
            case 1: {
                cout << "Elegir pelicula " << endl;
                int idPelicula;
                bool elegida;
                cout << "Ingrese el codigo de la pelicula a elegir: ";
                cin >> idPelicula;
                cout << endl;
                elegida = LP->elegirPelicula(idPelicula);
                if (elegida) {
                    cout << "La pelicula " << idPelicula << " ha sido seleccionada exitosamente" << endl;
                }
                else {
                    cout << "No se ha podido seleccionar la pelicula";
                }
                break;
            }
            case 2: {
                cout << "Consultar pelicula " << endl;
                int id;
                cout << "Ingrese el codigo de la pelicula a consultar: ";
                cin >> id;
                cout << endl;
                LP->consultarPelicula(id);
                break;
            }
            case 3: {
                cout << "Listar catalogo de peliculas por codigo " << endl;
                LP->listarCatalogoPorCodigo();
                break;
            }
            case 4: {
                cout << "Listar catalogo de peliculas por nombre " << endl;
                LP->listarCatalogoPorNombre();
                break;
            }
            case 5: {
                cout << "Listar catalogo de peliculas por hilera " << endl;
                string nombre;
                cout << "Ingrese la palabra o hilera que desea buscar: ";
                cin >> nombre;
                cout << endl;
                LP->listarCatalogoPorHilera(nombre);
                break;
            }
            case 6: {
                cout << "Listar peliculas por rango de año " << endl;
                int inferior;
                cout << "Ingrese el año limite inferior: ";
                cin >> inferior;
                int superior;
                cout << "Ingrese el año limite superior: ";
                cin >> superior;
                cout << endl;
                LP->listarCatalogoPorRango(inferior, superior);
                break;
            }
            case 7: {
                cout << "Listar peliculas por limite de año " << endl;
                int anio;
                cout << "Ingrese el año limite: ";
                cin >> anio;
                cout << endl;
                LP->listarCatalogoPorLimite(anio);
                break;
            }
            case 8: {
                cout << "Listar peliculas sin categoria " << endl;
                cout << endl;
                LP->listarPeliculasSinCategoria();
                break;
            }
            case 9: {
                cout << "Consultar categoria " << endl;
                string nombre;
                cout << "Ingrese el codigo de la categoria a consultar: ";
                cin >> nombre;
                cout << endl;
                LC->consultarCategoria(nombre);
                break;
            }
            case 10: {
                cout << "Listar catalogo de categorias " << endl;
                cout << "Listado catalogo completo en forma ascendente por nombre " << endl << endl;
                LC->catalogoCategorias();
                break;
            }
            case 11: {
                cout << "Consultar peliculas por categoria " << endl;
                break;
            }
            case 12: {
                cout << "Consultar catalogo de categorias con codigo y nombre de peliculas " << endl;
                break;
            }
            case 13: {
                cout << "Consultar catalogo de categorias con todos los detalles de peliculas " << endl;
                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
            }

            cout << endl << endl;

        } while (opc != 0);
    }
    else {
        cout << "Los credenciales no son validos" << endl;
    }
}

void menuPrincipal() {
    int opc = 0;
    do {
        cout << " UNIVERSIDAD CENFOTEC" << endl;
        cout << "ESTRUCTURAS DE DATOS 1\n" << endl;
        cout << "CenfoMovies Streaming\n" << endl;
        cout << "*****INTERFACE MANEJO DE PROGRAMA*****\n" << endl;
        cout << "ESCOGER TIPO DE USUARIO" << endl;
        cout << endl;
        cout << "(1) Administrador " << endl;
        cout << "(2) Cliente " << endl;
        cout << endl;
        cout << "(0) Finalizar Programa" << endl;
        cout << endl;
        cout << "OPCION SELECCIONADA-> "; cin >> opc;
        cout << endl << endl;
        cout << "_____________________________________________________________________";
        cout << endl << endl;

        switch (opc) {
            case 1: {
                menuAdministrador();
                break;
            }
            case 2: {
                menuCliente(LP, LC);
                break;
            }
            case 0: {
                cout << "Finalizando aplicacion.... Adios.... " << endl;
                break;
            }
            default:
                cout << "Opcion digitada no es valida " << endl;
                break;
        }
        cout << endl << endl;

     } while (opc != 0);
}

int main()
{
    menuPrincipal();
    return 0;
}

