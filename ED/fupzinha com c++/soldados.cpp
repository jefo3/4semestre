#include <iostream>

using namespace std;

int main(){

    int m = 3, n = 3, cont = 0;
    int v[m][n];
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

     for(int i = 0; i < m; i++){
        for(int j = 0; j < n-1; j++){
            
            if(v[j][i] > v[j+1][i]){
                cont++;
            }
        }
    }

    cout << cont << endl;

    return 0;
}