//
//

#include "logica.h"
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <regex>

using namespace std;

bool validarCredenciales(string _usuario, string _password, int _tipo) {
	bool valido = false;
    string userAdmin = "sergio";
    string passAdmin = "1234";
    string userCliente = "sergio";
    string passCliente = "123";

    if (_tipo == 1) {
        if (_usuario == userAdmin && _password == passAdmin) {
            valido = true;
        }
    }
    else if (_tipo == 2) {
        if (_usuario == userCliente && _password == passCliente) {
            valido = true;
        }
    }
    
	return valido;
}

enum IN {

    // 13 is ASCII for carriage
    // return
    IN_BACK = 8,
    IN_RET = 13

};

string passwordDelUsuario(char sp = '*')
{
    // Stores the password
    string passwd = "";
    char ch_ipt;

    // Until condition is true
    while (true) {

        ch_ipt = _getch();

        // if the ch_ipt
        if (ch_ipt == IN::IN_RET) {
            cout << endl;
            return passwd;
        }
        else if (ch_ipt == IN::IN_BACK
            && passwd.length() != 0) {
            passwd.pop_back();

            // Cout statement is very
            // important as it will erase
            // previously printed character
            cout << "\b \b";

            continue;
        }

        // Without using this, program
        // will crash as \b can't be
        // print in beginning of line
        else if (ch_ipt == IN::IN_BACK
            && passwd.length() == 0) {
            continue;
        }

        passwd.push_back(ch_ipt);
        cout << sp;
    }
}

bool validarInteger(int _input)
{
    bool validado = false;
    regex integer_expr("[0-9]+");
    string input = to_string(_input);

    if (regex_match(input, integer_expr)) {
        validado = true;
    }
    return validado;
}

bool validarString(string _input)
{
    bool validado = false;
    regex string_expr("[a-zA-Z0-9]+");

    if (regex_match(_input, string_expr)) {
        validado = true;
    }
    return validado;
}
