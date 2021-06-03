#include "Particula.h"
#include "ConjuntoParticulas.h"
#include <iostream>


using namespace std;

void testP1(string s) {
    cout << s << endl;
    cout << "Prueba Particulas" << endl;
    cout << "Paso 1 " << endl;
    Particula a(8,8,-1,-1,3), b(3,3,1,1,5);
    cout << "Particula 1: " << a << endl;
    cout << "Particula 2: " << b << endl;
    
    s = "Las particulas son distintas ";
    if (a == b){
        s = "Las particulas son iguales";
    }
    
    cout << s << endl;
    
    cout << "Paso 2 " << endl;
    a = b;
    cout << "Particula 1: " << a << endl;
    cout << "Particula 2: " << b << endl;
    
    s = "Las particulas son distintas ";
    if (a == b){
        s = "Las particulas son iguales";
    }
    
    cout << s << endl;
}
/*
void testP(string s) {
    cout << s << endl;
    cout << "Lectura de datos para particula desde cin " << endl;
    Particula p;
    cin >> p;
    
    cout << "\nDatos leidos: ";
    cout << p << endl;
    
}

*/
void test1(string s) {
    cout << s << endl;
    cout << "Prueba constructores y destructor" << endl;
    ConjuntoParticulas cp1; // por defecto
    ConjuntoParticulas cp2(3); // con parametros 
    ConjuntoParticulas otro(cp2); // ctor copia
}

void test2(string s) {
    cout << s << endl;
    cout << "Sobrecarga de operador <<  " << endl;

    cout << "Crear y mostrar conjunto de 5 particulas " << endl;
    ConjuntoParticulas cp1;
    float x = 1.0;
    float y = 1.0;
    for(int i = 0; i < 5; i++){
        Particula p(x,y, -x, -y,1);
        cp1.AgregaParticula(p);
        x++; y++;
    }
    cout << cp1 << endl;

}

void test3(string s) {
    cout << s << endl;
    cout << "Sobrecarga de operador =  " << endl;


    ConjuntoParticulas cp1;
    ConjuntoParticulas cp2;
    
    cp1.AgregaParticula(Particula(1,1,0,0,3));
    cp1.AgregaParticula(Particula(-1,-1,0,0,3));

    cp2.AgregaParticula(Particula(2,2,0,0,6));
    cp2.AgregaParticula(Particula(-2,-2,0,0,6));
    cp2.AgregaParticula(Particula(3,3,0,0,6));

    
    cout << "Dos conjuntos iniciales: " << endl;
    cout << "C1: " << cp1 << endl;
    cout << "C2: " << cp2 << endl;

    ConjuntoParticulas aux(cp1);
    cp1 = cp2;
    cp2 = aux;

    cout << "Conjuntos finales intercambiados: " << endl;
    cout << "C1: " << cp1 << endl;
    cout << "C2: " << cp2 << endl;
}

void test4(string s) {
    cout << s << endl;
    cout << "Concatenacion conjuntos + " << endl;
    ConjuntoParticulas cp1;
    ConjuntoParticulas cp2;
    
    
    cp1.AgregaParticula(Particula(1,1,0,0,3));
    cp1.AgregaParticula(Particula(-1,-1,0,0,3));

    cp2.AgregaParticula(Particula(2,2,0,0,6));
    cp2.AgregaParticula(Particula(-2,-2,0,0,6));
        
    
    ConjuntoParticulas cp3 = cp1 + cp2;

    cout << "C1:  ";
    cout << cp1 << endl;
    cout << "C2:  ";
    cout << cp2 << endl;
    cout << "C3: C1 + C2 ";
    cout << cp3 << endl;

    ConjuntoParticulas cp4 = cp1 + cp2 + cp3;

    cout << "C4=C1+C2+C3:  ";
    cout << cp4 << endl;

    cout << "C5=C2+C1:  ";
    ConjuntoParticulas cp5(cp2 + cp1);
    cout << cp5 << endl;

    cout << "C1 + C2 en cout: ";
    cout << cp1 + cp2;


}

void test5(string s) {
    cout << s << endl;
    cout << "Prueba del método Area()" << endl;

    ConjuntoParticulas cp;

    Particula p1(0, 0, 1, 1, 3);
    Particula p2(3, 3, 1, 1, 3);
    Particula p3(9, 9, 1, 1, 3);
    cout << "Particulas basicas " << endl;
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
    cout << "p3: " << p3 << endl;

    cp.AgregaParticula(p1);
    cout << "Conjunto con p1" << endl;
    cout << cp;
    cout << "Area: " << cp.Area() << endl;

    cp.AgregaParticula(p2);
    cout << "Conjunto con p1, p2" << endl;
    cout << cp;
    cout << "Area: " << cp.Area() << endl;

    cp.AgregaParticula(p3);
    cout << "Conjunto con p1, p2, p3" << endl;
    cout << cp;
    cout << "Area: " << cp.Area() << endl;

}

void test6(string s) {
    cout << s << endl;
    cout << "Prueba 1 del operador < " << endl;

    ConjuntoParticulas cp1; // constructor por defecto
    ConjuntoParticulas cp2;

    Particula p1(0, 0, 1, 1, 3);
    Particula p2(10, 10, 1, 1, 3);
    Particula p3(11, 11, 1, 1, 3);

    cp1.AgregaParticula(p1);
    cp1.AgregaParticula(p2);

    cp2 = cp1; // sobrecarga de asignacion
    cp2.AgregaParticula(p3);
    cout << "Conjuntos " << endl;
    cout << cp1 << endl;
    cout << cp2 << endl;

    cout << "Areas: " << cp1.Area() << " " << cp2.Area() << endl;
    if (cp1 < cp2)
        cout << "Conj 1 es menor que Conj 2 " << endl;
    else
        cout << "Conj 2 es mayor o igual que Conj 1 " << endl;

}

void test7(string s) {
    cout << s << endl;
    cout << "Ordenar array de ConjuntoParticulas < " << endl;

    int N = 10;

    ConjuntoParticulas *cp = new ConjuntoParticulas[N];

    // cada conjunto está vacío. Les agrego 10 particulas a cada uno
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 10; j++) {
            Particula p_rnd;
            cp[i].AgregaParticula(p_rnd);
        }
    }

    cout << "\nAreas sin ordenar" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Conj: " << i << " -> Area: " << cp[i].Area() << endl;
    }

    //ordenar conjuntos
    float min;
    int posMin;

    for (int i = 0; i < N - 1; i++) {
        posMin = i;
        for (int j = i + 1; j < N; j++) {
            if (cp[j] < cp[posMin])
                posMin = j;
        }

        if (posMin != i) {
            ConjuntoParticulas aux = cp[i];
            cp[i] = cp[posMin];
            cp[posMin] = aux;
        }

    }


    cout << "\nAreas ordenadas" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Conj: " << i << " -> Area: " << cp[i].Area() << endl;
    }

    delete [] cp;

}

void testFile(string s, const char* fname){
    cout << s << endl;
    ConjuntoParticulas cp(fname);
    cout << cp << endl;
}

void separador() {
    cout << "***********************************" << endl;

}


// al ejecutar el programa, debes indicar el nro de test que quieres ejecutar
// un número entre el 0 y el 7
int main(int argc, char *argv[]) {

    if (argc < 2) {
        cerr << "Uso: pruebaFinal <nroTest> donde nroTest es un valor entre 1 y 9" << endl;
        cerr << "si nroTest=8 hace falta un segundo parámetro con el nombre del fichero de datos" << endl;
        exit(-1);
    }
    
    
    int test = atoi(argv[1]);
    

    switch (test) {
       
        case 1:
        {
            test1("\n************* Test 1 ************* ");
            break;
        }

        case 2:
        {
            test2("\n************* Test 2 ************* ");
            break;
        }

        case 3:
        {
            test3("\n************* Test 3 ************* ");
            break;
        }

        case 4:
        {
            test4("\n************* Test 4 ************* ");
            break;
        }

        case 5:
        {
            test5("\n************* Test 5 ************* ");
            break;
        }

        case 6:
        {
            test6("\n************* Test 6 ************* ");
            break;
        }

        case 7:
        {
            test7("\n************* Test 7 ************* ");
            break;
        }
       case 8:
        {   testFile("\n************* Test Constructor Fichero ************* ", argv[2]);
            break;
        }
        
        case 9:
        {
            testP1("\n************* Test particula ************* ");
            break;
        }
       
        
        
    }
    
    separador();

    return 0;
}
