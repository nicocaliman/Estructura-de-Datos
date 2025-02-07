
// Nicolae Gabriel Caliman
// A-70

#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"

using namespace std;

const int CENTINELA = 0;

template <typename T>
class linked_list_ed_plus : public linked_list_ed<T> 
{
    using Nodo = typename linked_list_ed<T>::Nodo;

public:
    void duplicar()
    {
        Nodo* act = this->prim;

        while (act != nullptr)
        {
            Nodo* nuevo = new Nodo(act->elem, act->sig);  // Crea un nuevo nodo con el mismo valor

            act->sig = nuevo;  // Inserta el nuevo nodo después del actual
            act = nuevo->sig;  // Avanza dos posiciones en la lista            
        }
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
    int elemento;
    
    cin >> elemento;

    if (!std::cin)
        return false;

    linked_list_ed_plus<int> lista_enlazada;    //creacion de la lista enlazada

    while (elemento != CENTINELA)
    {
        lista_enlazada.push_back(elemento);
        cin >> elemento;
    }

    lista_enlazada.duplicar();  //duplicar elementos de la lista enlazada
    
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
