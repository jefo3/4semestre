#include <iostream>

using namespace std;

int main(){

    int m = 3, n = 3;
    int v[m][n];
    bool igual = false;

    int somaColuna = 0, somaLinha = 0, somaDiag = 0, somaDiag2 = 0;
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            somaColuna += v[j][i];
            somaLinha += v[i][j];

            if(i == j){
                somaDiag += v[i][j];
            }

            if(i+j == m-1){
                somaDiag2 += v[i][j];
            }
        }

        //uma pre avaliação das linhas e colunas
        if(somaColuna == somaLinha){
            igual = true;
        }else{
            igual = false;
            break;
        }    

        somaColuna = 0;
        somaLinha = 0;
    }

    if( igual == true && somaDiag == somaDiag2){
        cout << "sim";
    }else{
        cout << "nao";
    }

    cout << endl;

    return 0;
}