#include <iostream>
#include <string>
#include <climits>
#include <sstream>
#include "List.h"

using namespace std;

struct Node {
    int value;
    Node *next;
    ~Node() { std::cout << "no com valor " << value << " liberado" << std::endl; }
};

List::List() {
    head = new Node;
    head->next = head;
    head->value = 77777777;
}

// Destrutor: libera toda memoria que foi alocada
List::~List(){
    clear();
    delete head;
    cout << "lista liberada" << endl;
} 

// contains: retorna true se a lista contem um no com valor x;
// retorna false caso contrario
bool List::contains(int x){
    Node *aux = head->next;
    
    while(aux != head) {
        if(aux->value == x){
            return true;
        }

        aux = aux->next;
    }

    return false;
} 

// empty: retorna true se a lista estiver vazia;
// retorna false caso contrario
bool List::empty(){
    if(head->next == head){
        return true;
    }

    return false;
} 

// size: retorna a quantidade de elementos na lista
int List::size(){
    int tam = 0;

    Node *aux = head->next;
    
    while(aux != head) {
        tam++;
        aux = aux->next;
    }

    return tam;
    
} 

// clear: deixa a lista vazia, sem elementos  
void List::clear(){
    Node *aux = head->next;

    while(aux != head){
        head->next = aux->next;
        delete aux;
        aux = head->next;
    }
} 

// add_back: insere um no com valor x ao final da lista
void List::add_back(int x){
    Node *aux = head;
    
    while(aux->next != head) {
        aux = aux->next;
    }
    
    Node *novo = new Node;
    novo->value = x;
    novo->next = head;
    
    aux->next = novo;
    
} 

// add_front: insere um no com valor x no inicio da lista
void List::add_front(int x){
    
    Node *aux = head->next;
    
    Node *novo = new Node;
    novo->value = x;
    
    novo->next = aux;

    head->next = novo;
} 

// remove_front: remove o elemento que esta no inicio da lista
// retorna o valor do no caso ele exista; 
// ou retorna INT_MIN caso não exista primeiro elemento
int List::remove_front(){
    Node *aux = head->next;
    
    if(aux != head){
        int valor = aux->value;
        head->next = aux->next;
        delete aux;

        return valor;
    }

    return INT_MIN; 
}

// remove_back: remove o elemento que esta no final da lista 
// retorna o valor do no caso ele exista; 
// ou retorna INT_MIN caso não exista ultimo elemento
int List::remove_back(){
    Node *aux = head;
    Node *anterior = head; 
    
    while(aux->next != head) {
        anterior = aux;
        aux = aux->next;
    }

    if(aux != head){
        int valor = aux->value;
        anterior->next = head;

        delete aux;

        return valor;
    }

    return INT_MIN;
}

// remove: remove o primeiro no com valor x
void List::remove(int x){
    Node *aux = search(x);

    if(aux != nullptr) {
        Node *aux2 = aux->next;
        aux->next = aux->next->next;
        
        delete aux2;
    }
} 

// removeAll: remove todos os nos com valor x
void List::removeAll(int x){
    Node *aux = head->next;

    while(aux != head){
        if(aux->value == x){
            remove(x);
        }

        aux = aux->next;
    }
} 

// toString: retorna a lista como uma std::string
std::string List::toString(){
    int i = 0;
    string result;
    result = "[";

    Node *aux = head->next;
    
    while(aux != head) {
        std::stringstream numConvert;
        
        numConvert << aux->value;
        result = result + numConvert.str(); 

        if(i < size()-1){
            result = result + ",";
        }

        i++;
        aux = aux->next;
    }

    result = result + "]";

    return result;
}

// Operacao auxiliar: retorna o no anterior ao no com valor x; 
// ou retorna nullptr caso nenhum no com valor x esteja presente 
Node * List::search(int x){
    
    Node *aux = head->next;
    Node *anterior = head;

    while(aux != head) {
        if(aux->value == x){
            return anterior;
        }

        anterior = aux;
        aux = aux->next;
    }

    return nullptr;
}