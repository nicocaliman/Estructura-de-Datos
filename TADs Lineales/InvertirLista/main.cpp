
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

    void invertirNodos()
    {
        Nodo* actual = this->prim;
        Nodo* prev = nullptr;
        Nodo* siguiente = nullptr;

        while (actual != nullptr)
        {
            siguiente = actual->sig;
            actual->sig = prev;
            prev = actual;
            actual = siguiente;
        }

        this->prim = prev;
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

    linked_list_ed_plus<int> lista_enlazada;

    while (elemento != 0)
    {
        lista_enlazada.push_back(elemento);
        cin >> elemento;
    }

    lista_enlazada.invertirNodos();
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
