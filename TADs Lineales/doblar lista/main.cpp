
// Nicolae Gabriel Caliman

#include <iostream>
#include <iomanip>
#include <fstream>
#include "double_linked_list_ed.h"

using namespace std;

template<typename T>
class double_linked_list_ed_plus : public double_linked_list_ed<T>
{
    using Nodo = typename double_linked_list_ed<T>::Nodo;

public:

    void doblar()
    {
        //lista vacia o lista con un solo nodo
        if (this->empty() || this->fantasma->sig->sig == this->fantasma)
        {
            return;
        }

        Nodo* p = this->fantasma->sig;
        Nodo* q = this->fantasma->ant;

        Nodo* a_mover = nullptr;
        Nodo* posicion = nullptr;


        while (p->sig != q && p != q)
        {
            a_mover = q;

            q = q->ant; //siguiente nodo a intercalar
            q->sig = this->fantasma;    //el nuevo ultimo nodo apuntara siempre al nodo fantasma

            posicion = p;   
            p = p->sig; //siguiente posicion

            a_mover->sig = posicion->sig;
            a_mover->ant = posicion;

            posicion->sig = a_mover;
        }

    }

    void mostrar()
    {
        Nodo* actual = this->fantasma->sig;

        while (actual != this->fantasma)
        {
            cout << actual->elem << " ";
            actual = actual->sig;
        }
        
        cout << "\n";
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    double_linked_list_ed_plus<int> lista_doble;
    int elemento;

    for (int i = 0; i < n; i++)
    {
        cin >> elemento;
        lista_doble.push_back(elemento);
    }

    lista_doble.doblar();
    lista_doble.mostrar();
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
