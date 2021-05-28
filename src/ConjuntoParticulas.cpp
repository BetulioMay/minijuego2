#include "ConjuntoParticulas.h"
#include "Particula.h"
#include <iostream>
using namespace std;

// Funciones privadas
void ConjuntoParticulas::reservarMemoria(Particula * &set, const int tam) {
    if (set != NULL){
        liberaMemoria(set);
    }
    set = new Particula[tam];
}

void ConjuntoParticulas::liberaMemoria(Particula * &set) {
	if (set != NULL) {
		delete[] set;
                set = NULL;
	}
}

void ConjuntoParticulas::resizeConjunto(const int n_size) {
	Particula* temp = 0;
	reservarMemoria(temp, n_size);

	//memcpy(temp, set, sizeof(Particula) * size);
	for (int i = 0; i < GetUtiles(); ++i) {
		temp[i] = this->set[i];
	}

	liberaMemoria(this->set);

	this->set = temp;
        this->capacidad = n_size;
}

bool ConjuntoParticulas::posValida(const int pos) const {
    bool valida = false;
    
    if(pos < GetUtiles() && pos >= 0){
        valida = true;
    }
    return valida;
}

// Funciones publicas de la clase


// TODO -> Edit default constructor
ConjuntoParticulas::ConjuntoParticulas() {

	this->capacidad = 0;
	this->size = 0;
	this->set = NULL;

}

// TODO -> Edit parameter constructor
ConjuntoParticulas::ConjuntoParticulas(const int capacidad) {

	this->capacidad = capacidad;
	this->size = capacidad;
        this->set = NULL;
	reservarMemoria(this->set, this->GetCapacidad());

	/*for (int i = 0; i < this->GetCapacidad(); ++i) {
		Particula nueva;
		this->set[i] = nueva;
		this->size++;
	}*/
}

ConjuntoParticulas::~ConjuntoParticulas(){
	liberaMemoria(this->set);
}

int ConjuntoParticulas::GetCapacidad() const {
	return this->capacidad;
}

int ConjuntoParticulas::GetUtiles() const {
	return this->size;
}

void ConjuntoParticulas::AgregaParticula(const Particula & p) {
    
    int n = this->GetUtiles();
    
    if (this->GetUtiles() < this->GetCapacidad()) {
        this->set[n] = p;
    } else {
        resizeConjunto(this->GetCapacidad() + TAM_BLOQUE);
        this->set[n] = p;
    }
    
    this->size++;
}

void ConjuntoParticulas::BorraParticula(const int posicion) {

    if (posValida(posicion)){
	for (int i = posicion; i < this->GetUtiles() - 1; ++i) {
		this->set[i] = this->set[i + 1];
	}
	this->size--;

	if (GetCapacidad() - GetUtiles() > TAM_BLOQUE) {
		resizeConjunto(GetCapacidad() - TAM_BLOQUE);
	}
    }
}

Particula ConjuntoParticulas::ObtieneParticula(const int posicion) const {
    if (posValida(posicion)){
		return this->set[posicion];
    }
}

void ConjuntoParticulas::ReemplazaParticula(const int posicion, const Particula & p) {
	if (posValida(posicion)) {
		this->set[posicion] = p;
	}
}

void ConjuntoParticulas::Mover(int ancho, int alto) {
	for (int i = 0; i < this->size; ++i) {
		this->set[i].Mover(ancho, alto);
	}
}

void ConjuntoParticulas::Rebotar(int ancho, int alto) {
	for (int i = 0; i < this->size; ++i) {
		this->set[i].RebotaBordes(ancho, alto);
	}
}

void ConjuntoParticulas::Mostrar() {

	cout << "La capacidad total del conjunto -> " <<
		this->capacidad << "\n";

	cout << "Nro. de particulas actuales -> " <<
		this->size << "\n";

	for (int i = 0; i < size; ++i) {
		cout << this->set[i].ToString() << " ";
		cout << "\n";
	}

	cout << "\n";
}
