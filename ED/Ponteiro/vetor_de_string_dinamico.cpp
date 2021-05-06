#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;



int main(){

    int qnt_palavras, qnt_letras;
    cin >> qnt_palavras;
    

   char **v = new char*[qnt_palavras];


   for (int i = 0; i < qnt_palavras; i++) {
        string palavra; 
        cin >> qnt_letras;
        cin.ignore();
        getline(cin, palavra);
        //alocação dinamica
        v[i] = new char[qnt_letras+1];
        
        for(int j = 0; j <= qnt_letras; j++){
            v[i][j] = palavra[j];
        }
       
   }

    //ordenar
    for(int i = 0; i < qnt_palavras; i++){
        for(int j = 0; j < qnt_palavras; i++){
            if(strcmp(v[i], v[i]) > 0){
                char **aux = &v[i];
                *v[j] = *v[i];
                *v[i] = **aux;
            }
            
        }
    }

    //imprimir
    for(int i = 0; i < qnt_palavras; i++){
        for(int j = 0; j < qnt_palavras; i++){
           cout << v[i][j] << endl;
        }
    }

    for(int i = 0; i < qnt_palavras; i++){
        delete[] v[i];
    }
    
    delete[] v;
   
    return 0;
}