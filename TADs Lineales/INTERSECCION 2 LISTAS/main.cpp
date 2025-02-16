
// Nicolae Gabriel Caliman
//A-70

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

    void interseccion(const linked_list_ed_plus<T>& lista)
    {
        Nodo* p = this->prim;
        Nodo* ant = nullptr;
        Nodo* q = lista.prim;

        while (p != nullptr && q != nullptr) 
        {
            if (p->elem == q->elem) 
            {
                // Coincide, seguimos
                ant = p;
                p = p->sig;
                q = q->sig;
            }
            else if (p->elem < q->elem) {
                // p no está en q, eliminamos nodo de p
                Nodo* temp = p;
                if (ant == nullptr) {
                    this->prim = p->sig;
                }
                else {
                    ant->sig = p->sig;
                }
                p = p->sig;
                delete temp;
            }
            else {
                // q es menor, avanzamos q
                q = q->sig;
            }
        }

        // Eliminar nodos restantes en this si no están en lista
        while (p != nullptr) {
            Nodo* temp = p;
            if (ant == nullptr) {
                this->prim = p->sig;
            }
            else {
                ant->sig = p->sig;
            }
            p = p->sig;
            delete temp;
        }
    }

    void print() 
    {
        Nodo* actual = this->prim;

        while (actual != nullptr)
        {
            cout << actual->elem << " ";
            actual = actual->sig;
        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() 
{
    // leer los datos de la entrada
    int elemento;
    
    cin >> elemento;

    linked_list_ed_plus<int> lista_enlazada_simple_1;
    linked_list_ed_plus<int> lista_enlazada_simple_2;

    while (elemento != 0)
    {
        lista_enlazada_simple_1.push_back(elemento);
        cin >> elemento;
    }

    cin >> elemento;

    while (elemento != 0)
    {
        lista_enlazada_simple_2.push_back(elemento);
        cin >> elemento;
    }

    lista_enlazada_simple_1.interseccion(lista_enlazada_simple_2);

    lista_enlazada_simple_1.print();

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
