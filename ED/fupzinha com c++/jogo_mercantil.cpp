#include <iostream>

using namespace std;

int main(){

    int qnt_prondutos;
    cin >> qnt_prondutos;

    double preco[qnt_prondutos];
    double jogador1[qnt_prondutos];
    string jogador2[qnt_prondutos];

    int ponto_jogador1 = 0;
    int ponto_jogador2 = 0;

    for(int i = 0; i < qnt_prondutos; i++){
        cin >> preco[i];
    }

    for(int i = 0; i < qnt_prondutos; i++){
        cin >> jogador1[i];
    }

    for(int i = 0; i < qnt_prondutos; i++){
        cin >> jogador2[i];
    }

    for(int i = 0; i < qnt_prondutos; i++){
        if(jogador1[i] == preco[i]){
            ponto_jogador1++;
        }else if(jogador1[i] > preco[i] && jogador2[i] == "M" ){
            ponto_jogador1++;
        }else if(jogador1[i] > preco[i] && jogador2[i] == "m"){
            ponto_jogador2++;
        }if(jogador1[i] < preco[i] && jogador2[i] == "m" ){
            ponto_jogador1++;
        }else if(jogador1[i] < preco[i] && jogador2[i] == "M"){
            ponto_jogador2++;
        }
    }

    if(ponto_jogador1 == ponto_jogador2){
        cout << "empate";
    }else if(ponto_jogador1 > ponto_jogador2){
        cout << "primeiro";
    }else{
        cout << "segundo";
    }

    cout << endl;
    
    return 0;
}