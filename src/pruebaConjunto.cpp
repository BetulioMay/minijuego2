#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "Pintar.h"
#include <iostream>

using namespace std;

const float ANCHO = 800.0;
const float ALTO = 800.0;

void test1(string s) {
    cout << s << endl;
    cout << "Prueba Constructores " << endl;
    ConjuntoParticulas cp1;
    ConjuntoParticulas cp2(10);
}

void test2(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1(5);

    cout << "Conjunto Inicial " << endl;
    cp1.Mostrar();


    Particula nueva(5.0, 5.0, 0.0, 0.0, 5);
    int n = cp1.GetUtiles();
    for (int i = -1; i <= n + 1; i++)
        cp1.ReemplazaParticula(i, nueva);

    cout << "----- Después de reemplazar particulas ---- " << endl;
    cp1.Mostrar();
}

void test3(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1;

    cout << " ---- Conjunto Inicial ----" << endl;
    cp1.Mostrar();
    int n = 12;
    for (int i = 0; i < n; i++) {
        Particula nueva;
        cp1.AgregaParticula(nueva);
    }

    cout << " ---- Conjunto Final -----" << endl;
    cp1.Mostrar();
}

void test4(string s) {
    cout << s << endl;
    ConjuntoParticulas cp1(11);


    cout << " ---- Conjunto Inicial ----" << endl;
    cp1.Mostrar();

    int n = cp1.GetUtiles();
    for (int i = 0; i < n; i++) {
        int nro = cp1.GetUtiles();
        if (nro > 0)
            cp1.BorraParticula(rand() % nro);
    }
    cout << " ---- Conjunto Final -----" << endl;
    cp1.Mostrar();
}

void test5(string s) {
    cout << s << endl;
    int N = 10;
    // creación de objetos
    //---------------------------------------------------------
    ConjuntoParticulas nube(N);
    for (int i = 0; i < 100; i++) {
        if ((rand() % 10) > 5)
            for (int j = 0; j < 7; j++) {
                Particula nueva;
                nube.AgregaParticula(nueva);
            }
        else {
            for (int j = 0; j < 7; j++) {
                int nro = nube.GetUtiles();
                if (nro > 0)
                    nube.BorraParticula((rand() % nro));
            }
        }
        nube.Mover(ANCHO, ALTO);
        nube.Rebotar(ANCHO, ALTO);

    }

}

int main(void) {

    test1("\n************* Test 1 ************* ");
    test2("\n************* Test 2 ************* ");
    test3("\n************* Test 3 ************* ");
    test4("\n************* Test 4 ************* ");
    test5("\n************* Test 5 ************* ");
    return 0;
}