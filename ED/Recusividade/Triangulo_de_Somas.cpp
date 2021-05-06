#include <iostream>

using namespace std;

void triSoma(int tam, int v[]){    
   int v_aux[tam]; 
   triSoma(tam-1, v_aux);
    for(int i = 0; i < tam; i++){
        cout << v[i] << " ";
    }

    // for(int i = 0; i < tam-2; i++){
    //     v[i] = v[i] + v[i+1];
    // }
   

}

int main(){

    int n;
    
    cin >> n;
   
    int v[n];

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    triSoma(n, v);

    return 0;
}