#include <iostream>
#include <cstring>
using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 's' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.
int conta_char_rec(char s[], int n, char c, int cont){
    if(s[n] == c){
        cont++;
    }

    if(n == 0){
        return cont;
    }else{
        return conta_char_rec(s, n-1, c, cont);
    }

}

int main(){
   char s[102], c, cont = 0;
   
   cin.get(s, 102);
   cin.ignore();
   cin >> c;
   
   int n = strlen(s); // pega número de caracteres de s
   
   // Chame a função aqui para imprimir na tela o número de ocorrências
   int res = conta_char_rec(s, n, c, cont);
   cout << res << endl;
   
   return 0;
}