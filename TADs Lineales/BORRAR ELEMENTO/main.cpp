
// Nicolae Gabriel Caliman
// A-70


#include <iostream>
#include <iomanip>
#include <fstream>
#include "linked_list_ed.h"
#include "Horas.h"

using namespace std;

template<typename T>
class linked_list_ed_plus : public linked_list_ed<T>
{
    using Nodo = typename linked_list_ed<T>::Nodo;

public:

    void eliminarNodosPares()
    {
        int posicion = 1;

        Nodo* actual = this->prim;

        while (actual != nullptr)
        {
            if (posicion % 2 != 0 && actual->sig != nullptr)
            {
                if (actual->sig->sig !=nullptr)
                {
                    actual->sig = actual->sig->sig;
                }
                else
                {
                    actual->sig = nullptr;
                }                
            }

            actual = actual->sig;
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
    int n;

    cin >> n;

    if (n == 0)
        return false;

    linked_list_ed_plus<Horas> lista_enlazada;
    Horas h;

    for (int i = 0; i < n; i++)
    {
        cin >> h;
        lista_enlazada.push_back(h);
    }

    lista_enlazada.eliminarNodosPares();
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
