﻿
// Nicolae Gabriel Caliman
// A-70

#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"

using namespace std;

template<typename T>
class linked_list_ed_plus : public linked_list_ed<T>
{
    using Nodo = typename linked_list_ed<T>::Nodo;


public:

    //mover el ultimo nodo al principio
    void adelanta()
    {
        if (this->prim == nullptr || this->prim->sig == nullptr) return;
        
        Nodo* act = this->prim; //primer nodo de la lista
        Nodo* siguiente = nullptr;

        while (act->sig != nullptr)
        {
            siguiente = act;
            act = act->sig;
        }

        siguiente->sig = nullptr;
        act->sig = this->prim;
        this->prim = act;
    }

    void mostrar()
    {
        Nodo* act = this->prim;

        while (act != nullptr)
        {
            cout << act->elem << " ";
            act = act->sig;
        }
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementos;
    
    cin >> numElementos;

    if (numElementos == 0)
        return false;

    int num;
    linked_list_ed_plus<int> lista_enlazada;

    for (int i = 0; i < numElementos; i++)
    {
        cin >> num;
        lista_enlazada.push_back(num);
    }

    lista_enlazada.adelanta();
    lista_enlazada.mostrar();

    cout << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
