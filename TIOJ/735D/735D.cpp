#include <iostream>
using namespace std;

int N;

bool isPrime(int x){
	if(x == 2) return true;
	for(int i = 2; i * i <= x; i++){
		if(!(x % i)) return false;
	}
	return true;
}

int main(){
	cin >> N;
	if(N <= 3){
		cout << 1 << endl;
		return 0;
	}
	if(isPrime(N)){
		cout << 1 << endl;
	} else cout << (2 + ((N & 1) && !(isPrime(N - 2)))) << endl;
}
