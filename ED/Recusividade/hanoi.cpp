#include <iostream>
#include <stdio.h>

using namespace std;

void hanoi(int n, char ori, char dest, char temp){    

    if(n > 0){
        hanoi(n-1, ori, temp, dest);
        cout << ori << " -> "<<dest<<endl;
        hanoi(n-1, temp, dest, ori);
    }

}

int main(){

    int i = 1, n;
    
    cin >> n;
    hanoi(n, 'A', 'C', 'B');

    return 0;
}