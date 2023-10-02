#include <iostream>
#include "conjuntos_disjuntos.h"
#include <vector>
#include <cstdlib>

using namespace std;

int Aleatorio(int minimo, int maximo){
    double aleatorio=rand()/(RAND_MAX+1.0);
    int NumeroAleatorio=(maximo-minimo+1)*aleatorio+minimo;
    return NumeroAleatorio;
}

return ConjDisjuntos    UnirConjuntos(int a, int b, ConjDisjuntos c){
    for (int i=1; i<=NITEMS; ++i)
        c.unir(a,b);
return c
}

int main()
{
    const int NITEMS= NumHabitaciones;

    ConjDisjuntos c(NITEMS);

    while(ConjDisjuntos>1){
        int a=Aleatorio(0,NumHabitaciones-1);
        if(!c.sonEquiv(p.))

        UnirConjuntos(a,b);

    }


}
