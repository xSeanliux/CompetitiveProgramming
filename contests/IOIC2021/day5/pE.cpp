#include <iostream>
using namespace std;

int N, base[35], x;

inline bool ins(int x){
	for(int i = 31; i >= 0; i--){
		if(!((x >> i) & 1)) continue;
		if(base[i]) x ^= base[i];
		else {
			base[i] = x;
			return true;
		}
	}
	return false;
}
int main(){
	cin >> N;
	int base = 0;
	for(int i = 0; i < N; i++){
		cin >> x;
		if(ins(x)) base++;
	}
	cout << (1 << (N - base)) << endl;
	//how many is 0: 2^(N - base)
}
