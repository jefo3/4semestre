// Implementar
#include <iostream>
#include <cmath>
#include "Circulo.h"
#include "Ponto.h"

struct Circulo{
    Ponto *p;
    double raio;
};

// Aloca e retorna um struct Circulo
Circulo *circ_cria(double raio, Ponto *centro){
    Circulo* c = new Circulo;
    c->p = centro;
    c->raio = raio;

    return c;
}

// Libera a memoria que foi alocada para o struct Circulo
void circ_libera(Circulo *c){
    if(c != nullptr) {
        pto_libera(c->p);
        delete c;
        std::cout << "circulo liberado" << std::endl;
    }
}

// setters
void circ_setRaio(Circulo *c, double raio){
    c->raio = raio;
}
void circ_setCentro(Circulo *c, Ponto *p){
    c->p = p;
}
// coordenada x do centro do Circulo c
void circ_setX(Circulo *c, double x){
    pto_setX(c->p, x);
} 
// coordenada y do centro do Circulo c
void circ_setY(Circulo *c, double y){
    pto_setY(c->p, y);
} 

// getters
double circ_getRaio(Circulo *c){
    return c->raio;
}

Ponto *circ_getCentro(Circulo *c){
    return c->p;
}

// coordenada x do centro do Circulo c
double circ_getX(Circulo *c){
    return pto_getX(c->p);
} 
// coordenada y do centro do Circulo c
double circ_getY(Circulo *c){
     return pto_getY(c->p);
} 

// Retorna a area do Circulo c
double circ_getArea(Circulo *c){
    return c->raio * c->raio *  M_PI;
}

// Recebe um Ponto p e um Circulo c e retorna:
// true: se o ponto esta contido no circulo;
// false: caso contrario.
bool circ_interior(Circulo *c, Ponto *p){
    if(pto_distancia(c->p, p) < c->raio){
        return true;
    }else{
        return false;
    }
}