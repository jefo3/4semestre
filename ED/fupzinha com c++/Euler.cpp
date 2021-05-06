#include <iostream>
#include <iomanip>

using namespace std;



double fatorial(int n){
    double fat = 1;

    for(int i = 1; i <= n; i++){
        fat *= i;
    }

    return fat;
}

double euler(int n){
    double eul;

    for(int i = 1; i <= n; i++){
        eul += 1/fatorial(i);
    }

    return eul + 1;

}
int main(){

    int n;
    double eul;

    cin >> n;
    
    eul = euler(n);

    cout <<std::fixed<< setprecision(6) << eul<< endl ;

    return 0;
}