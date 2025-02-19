
// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"

using namespace std;

const int CENTINELA = 0;

template<typename T>
class linked_list_ed_plus : public linked_list_ed<T>
{
    using Nodo = typename linked_list_ed<T>::Nodo;

public:
    void intercambiar()
    {
        // Si la lista está vacía o solo tiene un elemento, no hay nada que intercambiar
        if (this->prim == nullptr || this->prim->sig == nullptr)
            return;

        Nodo* actual = this->prim;
        Nodo* prev = nullptr;

        // La nueva cabeza de la lista será el segundo nodo
        this->prim = actual->sig;

        while (actual != nullptr && actual->sig != nullptr)
        {
            Nodo* siguiente = actual->sig;
            Nodo* siguiente_siguiente = siguiente->sig;

            // Intercambiar
            siguiente->sig = actual;
            actual->sig = siguiente_siguiente;

            // Ajustar el puntero del nodo previo
            if (prev != nullptr)
                prev->sig = siguiente;

            // Moverse al siguiente par
            prev = actual;
            actual = siguiente_siguiente;
        }
    }

    void mostrar()
    {
        Nodo* actual = this->prim;

        while (actual != nullptr)
        {
            cout << actual->elem << ' ';
            actual = actual->sig;
        }

        cout << "\n";
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == CENTINELA)
        return false;

    linked_list_ed_plus<int> lista_enlazada_simple;
    int elemento;

    for (int i = 0; i < n; i++)
    {
        cin >> elemento;
        lista_enlazada_simple.push_back(elemento);
    }

    lista_enlazada_simple.intercambiar();   //intercambiar valores 2 a 2
    lista_enlazada_simple.mostrar();    //mostrar lista enlazada

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
