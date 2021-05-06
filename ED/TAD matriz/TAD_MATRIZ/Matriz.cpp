// Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"

using namespace std;

// Construtor: aloca matriz com l linhas e c colunas
Matriz::Matriz(int l, int c){
    _l = l;
    _c = c;
    
    _M = new float*[l];
    for(int i = 0; i < l; i++){
        _M[i] = new float[c];
    }

}

Matriz::~Matriz(){
    for(int i = 0; i < _l; i++){
      delete _M[i];
    }
    delete _M;
    cout << "matriz liberada" << endl;
}

// Retorna o numero de linhas da matriz
int Matriz::linhas(){
    return _l;
}

// Retorna o numero de colunas da matriz
int Matriz::colunas(){
    return _c;
}  

// Imprime matriz 
// O parametro largura indica o parametro que eh passado para a 
// funcao std::setw()
void Matriz::imprime(int largura){
    for(int i = 0; i < _l; i++){
        for(int j = 0; j < _c; j++){
            cout << setw(largura) << _M[i][j];
        }
        cout << endl;
    }
}

// Retorna o valor contido na celula [i][j] da matriz
float Matriz::valor(int i, int j){
    return _M[i][j];
} 

// Atribui o valor v a celula [i][j] da matriz
void Matriz::atribui(float v, int i, int j){
    _M[i][j] = v;
} 

// Recebe o ponteiro para o objeto B do tipo Matriz que possui
// l linhas e c colunas e soma a matriz B com a matriz atual.
// Lembre que a soma de uma matriz A com uma matriz B so eh possivel  
// se o numero de linhas e de colunas de A for igual ao numero de 
// linhas e de colunas de B, respectivamente. 
// Se for possivel fazer a soma, um ponteiro para uma nova matriz C
// contendo o resultado da soma deve ser retornado (note que a matriz C 
// deve ser alocada dinamicamente dentro da funcao-membro).
// Caso contrario, retorna nullptr indicando que nao foi possivel 
// fazer a soma das matrizes. 
Matriz * Matriz::soma(Matriz *B){
    if(_l == B->linhas() && _c == B->colunas()){
        Matriz* c = new Matriz(B->linhas(), B->colunas());

        for(int i = 0; i < _l; i++){
            for(int j = 0; j < _c; j++){
                c->atribui(_M[i][j] + B->valor(i,j), i, j);
            }
        }

        return c;

    }else{
        return nullptr;
    }
} 

// Recebe o ponteiro para o objeto B do tipo Matriz que possui
// l linhas e c colunas e multiplica a matriz que chamar essa funcao-membro pela matriz B.
// Lembre que a multiplicacao de uma matriz A por uma matriz B so eh possivel  
// se o numero de colunas de A for igual ao numero de linhas de B. 
// Se for possivel fazer a multiplicacao, um ponteiro para uma nova matriz C
// contendo o resultado da multiplicacao deve ser retornado (note que a matriz C 
// deve ser alocada dinamicamente dentro da funcao-membro).
// Caso contrario, retorna nullptr indicando que nao foi possivel 
// fazer a multiplicacao das matrizes. 
Matriz * Matriz::multiplica(Matriz *B){
    if(_c == B->linhas()){
        Matriz* c = new Matriz(_l, B->colunas());

        int valor = 0;
        int i, j, x;
        
        for(i = 0; i < _l; i++){
            for(j = 0; j < B->colunas(); j++){
                c->atribui(0, i, j);
            }
        }

        for(i = 0; i < _l; i++){
            for(j = 0; j < B->colunas(); j++){
               for(x = 0; x < _c; x++){
                   c->atribui( ( _M[i][x] * B->valor(x,j) + c->valor(i,j) ), i, j);
                   //c->_M[i][j] += _M[i][x] * B->valor(x,j);
                        //c->_M[i][j] += _M[i][x] * B->_M[x][j];
               }
                
            }
        }

        return c;

    }else{
        return nullptr;
    }
} 