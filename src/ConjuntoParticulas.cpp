#include "Particula.h"
#include "ConjuntoParticulas.h"
#include <iostream>
#include <cmath>
#include <assert.h>
#include <fstream>
using namespace std;

// Funciones externas a la clase

std::ostream & operator<<(std::ostream & stream, const ConjuntoParticulas & cp){

	cp.Mostrar();
	return stream;
}

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

// Metodo privado que hace la funcion de 'Deep copy' para el objeto en cuestion
void ConjuntoParticulas::dpCopia(const ConjuntoParticulas & _cp){
	this->capacidad = _cp.GetCapacidad();
	this->size = _cp.GetUtiles();

	reservarMemoria(this->set, this->GetCapacidad());

	for (int i = _cp.GetUtiles() - 1; i >= 0; --i) {
		this->ReemplazaParticula(i, _cp.ObtieneParticula(i));
	}
}

// Metodo privado para calcular las coordenadas minimas y maximas del
// conjunto en cuestion
void ConjuntoParticulas::MinMaxCoord(float & minX, float & minY,
									float & maxX, float & maxY) const 
{
	minX = maxX = ObtieneParticula(0).GetX();
	minY = maxY = ObtieneParticula(0).GetY();

	float X, Y;
	
	for (int i = 1; i < this->GetUtiles(); ++i){
		X = ObtieneParticula(i).GetX();
		Y = ObtieneParticula(i).GetY();

		if (minX > X){
			minX = X;
		}
		if (minY > Y){
			minY = Y;
		}
		if (maxX < X){
			maxX = X;
		}
		if (maxY < Y){
			maxY = Y;
		}
	}
}

// Metodos publicos de la clase

ConjuntoParticulas::ConjuntoParticulas() {

	this->capacidad = 0;
	this->size = 0;
	this->set = NULL;

}

ConjuntoParticulas::ConjuntoParticulas(const int capacidad) {

	assert(capacidad > 0);		// Comprobamos que capacidad es un tamanio valido

	this->capacidad = capacidad;
	this->size = this->GetCapacidad();
    this->set = NULL;
	reservarMemoria(this->set, this->GetCapacidad());

}

ConjuntoParticulas::ConjuntoParticulas(const ConjuntoParticulas & _cp) {
	// this->capacidad = _cp.GetCapacidad();
	// this->size = _cp.GetUtiles();
	// reservarMemoria(this->set, this->GetCapacidad());

	// for(int i = 0; i < _cp.GetUtiles(); ++i){
	// 	this->AgregaParticula(_cp.ObtieneParticula(i));
	// }
	this->set = NULL;
	this->dpCopia(_cp);
}

ConjuntoParticulas::ConjuntoParticulas(const char * nombre) {
	// Abrimos el fichero
	fstream f;
	f.open(nombre, ios::in);

	if (!f) {
		// Comprobamos que no hubo error al abrirlo
		cerr << "Error: File not opened." << endl;
		exit(1);
	}

	// Inicializamos el conjunto
	this->capacidad = 0;
	this->size = 0;
	this->set = NULL;

	reservarMemoria(this->set, this->GetCapacidad());

	// Leemos del fichero los datos y agregamos al conjunto
	int capacidad;
	float x, y, dx, dy, r;

	f >> capacidad;
	for (int i = 0; i < capacidad && !f.eof(); ++i) {
		Particula p;
		f >> p;
		this->AgregaParticula(p);
	}

	f.close();
}

ConjuntoParticulas::~ConjuntoParticulas() {
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

	assert(posValida(posicion));
	for (int i = posicion; i < this->GetUtiles() - 1; ++i) {
		this->set[i] = this->set[i + 1];
	}
	this->size--;

	if (GetCapacidad() - GetUtiles() > TAM_BLOQUE) {
		resizeConjunto(GetCapacidad() - TAM_BLOQUE);
	}
}

Particula ConjuntoParticulas::ObtieneParticula(const int posicion) const {
	assert(posValida(posicion));
	return this->set[posicion];
}

void ConjuntoParticulas::ReemplazaParticula(const int posicion, const Particula & p) {
	if (posValida(posicion)){
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

void ConjuntoParticulas::Mostrar() const {

	cout << "La capacidad total del conjunto -> " <<
		this->GetCapacidad() << "\n";

	cout << "Nro. de particulas actuales -> " <<
		this->GetUtiles() << "\n";

	for (int i = 0; i < size; ++i) {
		cout << this->set[i].ToString() << " ";
		cout << "\n";
	}

}
ConjuntoParticulas & ConjuntoParticulas::operator=(const ConjuntoParticulas & _cp) {

	if (this != &_cp){
		liberaMemoria(this->set);
		dpCopia(_cp);
	}

	return *this;
}

ConjuntoParticulas ConjuntoParticulas::operator+(const ConjuntoParticulas & _cp) const {
	ConjuntoParticulas n_cp(*this);

	for (int i = 0; i < _cp.GetUtiles(); ++i){
		n_cp.AgregaParticula(_cp.ObtieneParticula(i));
	}

	return n_cp;
}

bool ConjuntoParticulas::operator<(const ConjuntoParticulas & _cp) const {
	bool esMenor = false;

	if (this->Area() < _cp.Area()){
		esMenor = true;
	}

	return esMenor;
}

float ConjuntoParticulas::Area() const {
	// Obtenemos las minimas coordenadas que tiene un particula del conjunto
	// Asimismo, con las maximas coordenadas
	// Devolvemos el area del rectangulo definido por las coordenadas
	float minX, minY;
	float maxX, maxY;
	float area;
	if (this->GetUtiles() < 1){
		area = 0;
	}
	else{
		// Get the coordinates
		MinMaxCoord(minX, minY, maxX, maxY);
		area = (maxX - minX) * (maxY - minY);
	}
	return area;
}

