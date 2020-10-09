#include <iostream>
using namespace std;

const int maxN = 2e3 + 326;
int N, arr[maxN], x, Q, l, r;

int main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		for(int j = 0; j < i; j++){
			x ^= (arr[i] < arr[j]);
		}
	}
	cin >> Q;
	while(Q--){
		cin >> l >> r;
		x ^= (r - l) * (r - l + 1) / 2;
		cout << (x & 1 ? "odd" : "even") << endl;
	}
}
