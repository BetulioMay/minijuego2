#ifndef CONJUNTOPARTICULAS_H
#define CONJUNTOPARTICULAS_H
#include "Particula.h"

const int MIN_SIZE = 5;
const int TAM_BLOQUE = 3;

class ConjuntoParticulas {
private:
	Particula* set;			// Array de Particulas
	int capacidad;			// Maxima capacidad del array
	int size;               // Nro. de particulas utilizadas
        
    void reservarMemoria(Particula * &set, const int tam);
    void liberaMemoria(Particula * &set);
    void resizeConjunto(const int n_size);
    bool posValida(const int pos) const;
	void dpCopia(const ConjuntoParticulas & _cp);

public:

	// Constructor sin parametros
	// Inicializa el array con una capacidad de MIN_SIZE = 5
	ConjuntoParticulas();

	// Contructor con parametros
	// Inicializa el array con el tama�o que le pasemos
	// como parametro
	ConjuntoParticulas(const int capacidad);

	// Constructor de copia
	ConjuntoParticulas(const ConjuntoParticulas & _cp);

	// Destructor
	// Libera la memoria utilizada cuando termina el programa
	~ConjuntoParticulas();

	// Getters de la clase
	int GetCapacidad() const;
	int GetUtiles() const;

	// Agregar, borrar, obtener y reemplazar una particula del conjunto
	void AgregaParticula(const Particula & p);
	void BorraParticula(const int posicion);
	Particula ObtieneParticula(const int posicion) const;
	void ReemplazaParticula(const int posicion, const Particula & p);

	// Motions de las particulas del conjunto
	void Mover(int ancho, int alto);
	void Rebotar(int ancho, int alto);
	void Mostrar() const;

	// '=' override
	ConjuntoParticulas & operator=(const ConjuntoParticulas & _cp);
	// '+' override
	ConjuntoParticulas operator+(const ConjuntoParticulas & _cp) const;
};

// '<<' override
std::ostream & operator<<(std::ostream & stream, const ConjuntoParticulas & cp);

#endif	/* CONJUNTOPARTICULAS_H */