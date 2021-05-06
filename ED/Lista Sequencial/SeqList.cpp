#include <iostream>
#include <sstream>
#include "SeqList.h"

using namespace std;

// Construtor: recebe como argumento a capacidade n da lista
SeqList::SeqList(int n){
    capacity_vec = n;
    size_vec = 0;
    vec = new int[capacity_vec];
}  

// Destrutor: libera memoria alocada
// Apos liberar a memoria alocada, 
// o destrutor deve escrever na tela a mensagem: "lista removida"
SeqList::~SeqList(){
    size_vec = 0;
    capacity_vec = 0;
    delete vec;
    cout << "lista removida" << endl; 
}  

// Recebe um inteiro x como argumento e adiciona o 
// inteiro x logo apos o ultimo elemento da lista. 
// Retorna 'true' se for bem sucedido, ou 'false' 
// caso contrario. Nenhum elemento deve ser adicionado 
// se a lista estiver cheia.
bool SeqList::add(int x){
    
    if(size_vec >= capacity_vec){
        return false;
    }

    vec[size_vec] = x;
    size_vec++;

    return true;
} 

// Remove o primeiro valor x que estiver na lista
// Se nao remover nenhum valor x retorna false;
// caso contrario retorna true
bool SeqList::remove(int x){
    
    for(int i = 0; i < size_vec; i++){
       if(vec[i] == x){
           
           for(int j = i+1; j < size_vec; j++){
               vec[j-1] = vec[j];
            }

            size_vec--;

            return true;
       }
    }

    return false;
} 

// Busca um elemento x e retorna seu indice se
// ele existir; ou -1 caso contrario
int SeqList::search(int x){

    for(int i = 0; i < size_vec; i++){
        if(vec[i] == x){
            return i;
        } 
    }

    return -1;
} 

// Retorna o elemento no indice k
// Supoe que o indice passado eh valido
int SeqList::at(int k){
    return vec[k];
}

// Retorna o numero de elementos na lista
int SeqList::size(){
    return size_vec;
} 

// Retorna true se lista estiver cheia;
// ou retorna false caso contrario
bool SeqList::isFull(){
    if(size_vec == capacity_vec){
        return true;
    }

    return false;
} 

// Deixa a lista vazia, ou seja, com size() == 0
void SeqList::clear(){
    size_vec = 0;
} 

// Retorna a lista como uma std::string
// Por exemplo, se a lista tiver elementos 2,5,7,8 nesta ordem
// entao deve ser retornada a string "[2,5,7,8]"
// Se, por outro lado, a lista estiver vazia, deve
// ser retornada a string "[]"
std::string SeqList::toString(){
    
    string result;
    
    result = "[";

    for(int i = 0; i < size_vec; i++){
        
        std::stringstream numConvert;
        
        numConvert << vec[i];
        result = result + numConvert.str(); 
        
        if(i < size_vec-1){
            result = result + ",";
        }
        
    }
    
    result = result + "]";

    return result;
} 

// Member function: bool replaceAt(int x, int k);
// Troca o elemento na posicao com indice k pelo elemento x,
// somente se 0 <= k <= size()-1.
// Retorna true se a troca for feita com sucesso;
// ou retorna false caso contrario.
bool SeqList::replaceAt(int x, int k){
    
    if( k >= 0 && k <= size()-1){
        vec[k] = x;

        return true;
    }

    return false;

} 

// Member function: bool removeAt(int k);
// Remove da lista o elemento com indice k. 
// Para que a remocao seja realizada, deve-se ter 0 <= k <= size()-1.
// Os elementos resultantes devem ter a mesma ordem relativa
// na lista apos a remocao do elemento com indice k.
// A funcao retorna true se a remocao for feita com sucesso;
// ou retorna false caso contrario.
bool SeqList::removeAt(int k){
    if( k >= 0 && k <= size()-1){
        for(int i = k+1; i < size_vec; i++){
            vec[i-1] = vec[i];
        }
        size_vec--;

        return true;
    }

    return false;
}

// Member function: bool insertAt(int x, int k);
// Adiciona o elemento x na posicao com indice k da lista,
// somente se 0 <= k <= size() e size() < capacity_vec. 
// Antes de fazer a insercao, todos os elementos da 
// posicao k em diante sao deslocados uma posicao para a direita.
// A funcao retorna true se a insercao for feita com sucesso;
// ou retorna false caso contrario.
bool SeqList::insertAt(int x, int k){
    
     if(size() == 0 && k == size()){
        vec[k] = x;
        size_vec++;
        return true;
    }
    
    if( k >= 0 && k <= size() && size() < capacity_vec ){

        for(int i = size()-1; i >= k; i--){
            vec[i+1] = vec[i];
        }

        vec[k] = x;

        return true;
    }

    return false;
} 

// Member function: void removeAll(int x); 
// Remove todas as ocorrencias do elemento x da lista.
// Na implementacao desta funcao esta impedido o uso de quaisquer outras funcoes.
// Escreva o codigo desta funcao sem chamar qualquer outra funcao.
void SeqList::removeAll(int x){

    int quantMenos = 0;

    for(int i = 0; i < size_vec; i++){
        if(vec[i] == x){
            quantMenos++;
        }
    }

    for(int i = 0; i < size_vec; i++){
        if(vec[i] == x){

            for(int j = i+1; j < size_vec; j++){
                if(vec[i] != vec[j]){
                    int aux = vec[i];
                    vec[i] = vec[j];
                    vec[j] = aux;
                    break;
                }
            }
        }
    }

    size_vec -= quantMenos;

} 

