// Este arquivo está parcialmente implementado. 
// Implemente o restante das operações do TAD Ponto

// Arquivo Ponto.cpp
// Implementacao do TAD Ponto
#include <iostream>
#include <cmath>
#include "Ponto.h"

struct Ponto {
    double x;
    double y;
}; 

// Aloca e retorna um ponto com coordenadas (x,y)
Ponto *pto_cria(double x, double y){
    
    Ponto *p = new Ponto;
    p->x = x;
    p->y = y;

    return p;
} 


// Libera a memoria de um ponto previamente criado
void pto_libera(Ponto *p) { 
    if(p != nullptr) {
        delete p;
        std::cout << "ponto liberado" << std::endl;
    }
}

// getters: retornam os valores das coordenadas de um ponto 
double pto_getX(Ponto *p){
    return p->x;
}

double pto_getY(Ponto *p){
    return p->y;
}

// setters: atribuem novos valores as coordenadas de um ponto 
void pto_setX(Ponto *p, double x){
    p->x = x;
}

void pto_setY(Ponto *p, double y){
      p->y = y;
}

// Retorna a distancia entre dois pontos
double pto_distancia(Ponto* p1, Ponto* p2){
    return sqrt( pow((p2->x - p1->x), 2) +  pow((p2->x - p1->x), 2)); 
}