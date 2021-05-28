#include "Particula.h"
#include "ConjuntoParticulas.h"
#include "Pintar.h"

using namespace std;

void pintarParticula(const Particula& p, Color c){
	DrawCircle(p.GetX(), p.GetY(), p.GetRadio(), c);
}

void pintarConjunto(const ConjuntoParticulas& cp, Color c){
	int N = cp.GetUtiles();

	for (int i = 0; i < N; ++i)
		pintarParticula(cp.ObtieneParticula(i), c);
}