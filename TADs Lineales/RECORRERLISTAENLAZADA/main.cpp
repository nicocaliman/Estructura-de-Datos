// Nicolae Gabriel Caliman
// A-70

#include <iostream>
#include <iomanip>
#include <fstream>
#include "listed_link_ed.h"

using namespace std;

template <typename T>
class linked_list_plus : public linked_list_ed<T>
{
    using Nodo = typename linked_list_ed<T>::Nodo;

public:
    template <typename Predicate >
    void mostrarPropiedad(Predicate pred, std::ostream& o = std::cout) const {
        Nodo* aux = this -> prim;
        while (aux != nullptr && !pred(aux -> elem))
            aux = aux -> sig;
        if (aux != nullptr) {
            o << aux -> elem;
            aux = aux -> sig;
            while (aux != nullptr) {
                if (pred(aux -> elem)) o << ' ' << aux -> elem;
                aux = aux -> sig;
            }
        }
        o << '\n';
    }

};

class multiplo {
public:
    multiplo(int num) : n(num) {}
    bool operator ()(int valor) {
        return valor % n == 0;
    }
private:
    int n;
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int N;
    int multiploDe;

    cin >> N >> multiploDe;

    if (!std::cin)
        return false;

    linked_list_plus<int> lista_enlazada;
    int num;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        lista_enlazada.push_back(num);
    }

    lista_enlazada.mostrarPropiedad(multiplo(multiploDe));

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