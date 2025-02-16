
// Nicolae Gabriel Caliman
//A-70

#include <iostream>
#include <iomanip>
#include <fstream>
#include "double_linked_list_ed.h"

using namespace std;

template<typename T>
class linked_list_ed_plus : public double_linked_list_ed<T> 
{
    using Nodo = typename double_linked_list_ed<T>::Nodo;

public:

    linked_list_ed_plus<T> eliminarRepetidos()
    {
        linked_list_ed_plus<T> lista_eliminados;

        Nodo* actual = this->fantasma->sig;
        Nodo* siguiente = this->fantasma->sig->sig;


        while (actual->sig != this->fantasma)
        {
            if (actual->elem == siguiente->elem)
            {
                Nodo* a_borrar = actual->sig;
                lista_eliminados.push_back(a_borrar->elem);

                actual->sig = a_borrar->sig;
                a_borrar->sig->ant = a_borrar->ant;

                siguiente = siguiente->sig;

                delete a_borrar;
            }

            else
            {
                actual = siguiente;
                siguiente = siguiente->sig;
            }
        }

        return lista_eliminados;
    }

    void print()
    {
        Nodo* actual = this->fantasma;

        while (actual->sig != this->fantasma)
        {
            cout << actual->sig->elem << " ";
            actual = actual->sig;
        }
    }
   
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    char letra;

    cin >> n;

    if (n == -1)
        return false;

    linked_list_ed_plus<char> lista_doble;

    for (int i = 0; i < n; i++)
    {
        cin >> letra;
        lista_doble.push_back(letra);
    }

    linked_list_ed_plus<char> lista_eliminados = lista_doble.eliminarRepetidos();

    lista_doble.print();

    cout << "\n";

    lista_eliminados.print();

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