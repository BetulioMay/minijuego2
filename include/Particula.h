#ifndef _PARTICULA_
#define _PARTICULA_

#include <iostream>
const int MAX_VEL = 6;
const int MIN_DIM = 800;
const float RADIO = 7.0;
const float EPSILON = 0.01;

// Funciones externas a la clase

class Particula {
private:
    float x, y, dx, dy;
    float radio;
    // control de bordes
    void AjustarPosicion(int ancho, int alto); 
    
public:
    
    // crea una partícula con valores al azar en posicion y velocidad
    // 0 <= x, y < MIN_DIM
    // 0 <= dx, dx < MAX_VEL
    // radio constante
    Particula();

    // constructor con parámetros
    Particula(float _x, float _y, float _dx, float _dy, float _r) : x(_x), y(_y), dx(_dx), dy(_dy), radio(_r) {
    };

    // Setters / Getters
    float GetX() const;
    float GetY() const;
    float GetDX()const;
    float GetDY()const;
    float GetRadio()const;
    
    void SetXY(float, float);
    void SetDX(float);
    void SetDY(float);

    // calcula distancia euclidea entre dos partículas
    float Distancia(const Particula & otra) const; 
    
    // detecta si dos partículas chocan
    // la distancia tiene que ser menor que la suma de sus radios
    bool Colision(const Particula & otra) const; 
    
    // controla si la partícula choca con los bordes
    // en ese caso, cambia el signo de la velocidad
    void RebotaBordes(int ancho, int alto);

    // cambia la posicion, sumándole la velocidad
    void Mover(int ancho, int alto);
    
    // realiza un movimiento en una direccion dada
    // dir = {'U', 'D', 'L', 'R'} (arriba, abajo, izq, der)
     // recibe las dimensiones del mundo para evitar que la partícula 
    // salga del mundo
    void MoverGrid(char dir, int ancho, int alto);
    
    // rota la partícula sobre el punto (posX, posY) rads radianes
    // Si quiere transformar grados a radianes debe hacer 
    // rads = grados * (M PI / 180.0). La constanteM_PI esta definida en cmath.
    void Rotar(float posX, float posY, double rads);
    
    // transforma el contenido de la particula en un string
    std::string ToString() const;

    // '==' override
    bool operator==(const Particula & _p) const;    

};

// '<<' operator override
std::ostream & operator<<(std::ostream & stream, const Particula & p);

#endif
