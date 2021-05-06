#include <iostream>

using namespace std;

int main(){

    int qnt_dominos, cont = 0;
    
    cin >> qnt_dominos;

    int v[qnt_dominos];
    for(int i = 0; i < qnt_dominos; i++){
        cin >> v[i];
    }
    
    
    for(int i = 0; i < qnt_dominos-1; i++){
        if(v[i] <= v[i+1]){
            cont++;
        }else{
            cont = cont;
        }
    }
    
    if(cont == qnt_dominos - 1){
        cout << "ok" << endl;
    }else{
        cout << "precisa de ajuste" << endl;
    } 
    
    return 0;
}