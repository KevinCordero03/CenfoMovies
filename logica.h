#pragma once
#include <iostream>
#include <stdlib.h>
#include <regex>
#include "pelicula.h"
#include "listaPeliculas.h"

using namespace std;

bool validarCredenciales(string, string, int);

string passwordDelUsuario(char);

bool validarInteger(int);

bool validarString(string);
