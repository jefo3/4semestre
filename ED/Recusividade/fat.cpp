#include <iostream>

using namespace std;

int fat(int n){
	if(n <= 1) return 1;
    return fat(n-1)*n;
}

int main(){

	int a;
	cin >> a;
	int r = fat(a);
	cout << r;	

	return 0;
}