/**
 * Implemente as funções-membro da classe List neste arquivo.
 * Algumas funções já estão implementadas abaixo
 */

// Implementacao da classe List
#include <iostream>
#include <climits>
#include <sstream>
#include "List.h"

using namespace std;
// Definicao do struct Node
// Possui dois campos: value (valor inteiro) e 
// next (que eh um ponteiro para Node)
// Em C++, structs tambem podem ter construtores e destrutores. Aqui,
// Eu coloquei um destrutor que imprime uma mensagem na tela a fim 
// de rastrear se todos os nos alocados dinamicamente serao todos liberados.
struct Node {
    int value; 
    Node *next; 
    ~Node() { std::cout << "Node " << this->value << " removido" << std::endl; }
};

// Construtor. 
// Como nossa lista simplesmente encadeada possui no cabeca,
// Alcoamos dinamicamente um no cabeca aqui no construtor e 
// inicializamos os valores de seus campos. Nao mexa nesses valores, 
// pois caso contrario, o Moodle nao reconhecera as saidas corretamente.
List::List() {
    head = new Node;
    head->value = -77777777;
    head->next = nullptr;
}

// Destrutor. Limpamos a lista e depois liberamos o no cabeca.
// Antes de sair, imprime mensagem na saida, avisando que a 
// lista foi liberada.
List::~List() {
    clear();
    delete head;
    std::cout << "lista liberada" << std::endl;
}


void List::add(int x){
   
    Node *novo = new Node;
    novo->value = x;
    novo->next = nullptr;

    Node *aux = head;
    while(aux->next != nullptr) {
        aux = aux->next;
    }

    aux->next = novo;
} 

// remove da lista o primeiro no com valor x 
void List::remove(int x){
    
    Node *aux = search(x);

    if(aux != nullptr) {
        Node *aux2 = aux->next;
        aux->next = aux->next->next;
        
        delete aux2;
    }
}   

// retorna true se a lista estiver vazia;
// retorna false caso contrario
bool List::empty(){
    if(head->next == nullptr){
        return true;
    } 
    
    return false;
}

// Retorna numero de elementos contidos na lista
int List::size(){   
    int cont = 0;
    Node *aux = head;

    while(aux->next != nullptr) {
        cont++;
        aux = aux->next;
    }

    return cont;
} 

// deixa a lista vazia, ou seja, com size() == 0
void List::clear(){
    Node *aux = head->next;
    
    while(aux != nullptr) {
        head->next = aux->next;
        delete aux;
        aux = head->next;
    }
      
    head->next = nullptr;
}  

// Imprime elementos da lista
void List::print(){
    
    Node *aux = head->next;
    
    while(aux != nullptr) {
        cout << aux->value << " ";
        aux = aux->next;
    }
    cout << endl;
}

// Retorna a lista como uma string
// Por exemplo, se a lista tiver elementos 4,5,6,7 entao
// a funcao deve retornar a string "[4,5,6,7]"
// Se a lista for vazia, deve retornar a lista "[]"
std::string List::toString(){
    int i = 0;
    string result;
    result = "[";

    Node *aux = head->next;
    
    while(aux != nullptr) {
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

// remove da lista todos os nos com valor x
void List::removeAll(int x){
    Node *aux = head->next;
    
    while(aux != nullptr) {
        if(aux->value == x){
            remove(x);
        }

        aux = aux->next;
    }
} 
    
// remove da lista encadeada o i-esimo no e retorna seu valor.
// Note que deve-se ter 1 <= i <= size();
// Caso contrario retornar o menor inteiro possivel INT_MIN, 
// que esta definido na biblioteca <climits>
int List::removeNodeAt(int i){
    
    if( (i >= 1) && (i <= size()) ){
        int j = 1;

        Node *aux = head->next;
        Node *anterior = head;

        while(aux != nullptr){
            
            if(j == i){
                int valor = aux->value;
                
                anterior->next = aux->next;
                
                aux->next = nullptr;
                delete aux;

                return valor;
            }
            
            j++;
            anterior = aux;
            aux = aux->next;

        }
        
    }
    
    return INT_MIN;
}

// Insere um novo no com valor x apos o i-esimo no da lista.
// Deve-se ter 0 <= i <= size() para que a insercao seja realizada; 
// caso contrario, nao sera realizada.
bool List::insertAfter(int x, int i){
     if(i >= 0 && i <= size()){
        int j = 1;

        Node *aux = head->next;

        //caso nao tenha nenhum elemento na lista
        if(size() == 0){
            add(x);
            return true;
        }

        while(aux != nullptr){
            
            if(j == i){
                Node *novo_no = new Node;
                novo_no->next = aux->next;
                novo_no->value = x;
                
                aux->next = novo_no;

                return true;
            }
            
            j++;
            aux = aux->next;

        }
        
    }
    
    return false;
}

// Retorna um ponteiro para uma copia desta lista.
// Para a implementacao desta funcao, eh permitido o uso de outras funcoes.
// Note que voce deve retornar uma copia e nao um ponteiro para esta lista.
List *List::copy(){
    List *lista = new List();
    
    Node *aux = head->next;
    while (aux != nullptr){
        lista->add(aux->value);
        aux = aux->next;
    }
    

    return lista;
}

// Copia os elementos do array v para esta lista. 
// O array tem n elementos. 
// Todos os elementos anteriores da lista sao apagados.
// Para a implementacao desta funcao, eh permitido o uso de outras funcoes.
void List::copyArray(int v[], int n){
    
    clear();

    for(int i = 0; i < n; i++){
        add(v[i]);
    }
}

// Determina se a lista lst, passada por parametro, 
// eh igual a lista que chama esta funcao. 
// Observacao: duas listas sao iguais se elas tem o
// mesmo tamanho e o valor do k-esimo elemento da primeira lista eh igual
// ao valor do k-esimo elemento da segunda lista.
// Para a implementacao desta funcao esta proibido usar qualquer
// outra funcao. 
// --->> Atencao: Implemente esta funcao sem invocar funcoes auxiliares. <<----
bool List::equal(List *lst){
    int tamList1 = 0;
    int tamList2 = 0;
    
    //tamanho da lista this
    Node *auxListThis = head->next;

    while(auxListThis != nullptr) {
        tamList1++;
        auxListThis = auxListThis->next;
    }
    
    //tamanho da lista vindo pela função
    Node *auxLst = lst->head->next;

    while(auxLst != nullptr) {
        tamList2++;
        auxLst = auxLst->next;
    }

    auxListThis = head->next;
    auxLst = lst->head->next;
    if(tamList1 == tamList2){
        
        while(auxListThis != nullptr && auxLst != nullptr) {    
            

            if(auxListThis->value != auxLst->value){
                return false;
            }

            auxListThis = auxListThis->next;
            auxLst = auxLst->next;
        }

    }else{
        return false;
    }

    return true;
}

// Concatena a lista atual com a lista lst passada 
// por referencia. Apos essa operacao, lst sera uma lista vazia, 
// ou seja, o unico no de lst sera o no cabeca.
// Para a implementacao desta funcao esta proibido usar qualquer
// outra funcao. 
// --->> Atencao: Implemente esta funcao sem invocar funcoes auxiliares. <<----
void List::concat(List *lst){
    Node *aux = head;

    while(aux->next != nullptr){
        aux = aux->next;
    }

    aux->next = lst->head->next;
    
    
    Node *auxLst = lst->head->next;
    
    while(auxLst != nullptr) {
        lst->head->next = auxLst->next;
        
        auxLst = lst->head->next;
    }
      
    lst->head->next = nullptr; 
}
// Esta funcao inverte a ordem dos nos (o primeiro no passa a ser o
// ultimo, o segundo no passa a ser o penultimo, etc.) 
// Essa operacao faz isso sem criar novos nos, apenas altera os ponteiros.
// --->> Atencao: nao eh permitido alocar nos auxiliares. <<----
void List::reverse(){
    
    Node *primeiro;
    Node *anterior;
    Node *aux;
    Node * aux2;
    
    primeiro = head->next;
        
    aux = head->next;
    aux2 = aux->next;
    anterior = head;

    while (aux2 != nullptr){
        
        anterior = aux;
        
        aux = aux2;

        aux2 = aux2->next;
        
        aux->next = anterior;
        
    }

    head->next = aux;
    primeiro->next = nullptr;
}

 // Operacao auxiliar: retorna no antecessor do no 
// com valor x, ou nullptr caso x nao esteja presente 
Node *List::search(int x) {
    
    Node *aux = head;
    while(aux->next != nullptr) {
        if(aux->next->value == x) {
            return aux;
        }
        aux = aux->next;
    }

    return nullptr;
} 