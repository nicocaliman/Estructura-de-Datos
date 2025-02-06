﻿// Nicolae Gabriel Caliman
// A-70

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Complejo.h"

using namespace std;


const int MINIMO_ITERACIONES = 100;
const int MAXIMO_ITERACIONES = 500;

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
    // leer los datos de la entrada
    Complejo c, aux;
    bool valido = true;
    int num_iteraciones;
    int i = 0;
        
    cin >> c;   //lectura del numero Complejo
    cin >> num_iteraciones; //leer el numero de  iteraciones

    aux = c;

    while (i < num_iteraciones && valido)
    {
       if (c % c > 2)
       {
          valido = false;
       }
       else
       {
           c = (c * c) + aux;
       }
          ++i;
    }

    valido == true ? cout << "SI" : cout << "NO";

    cout << "\n";    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}