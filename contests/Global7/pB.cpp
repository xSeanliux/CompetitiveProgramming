	#include <iostream>
using namespace std;

const int maxN = 2e5 + 10;

int N, b[maxN], a[maxN];

int main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> b[i];
	a[0] = b[0];
	int cm = a[0];
	for(int i = 1; i < N; i++){
		a[i] += cm + b[i];
		cm += max(b[i], 0);
	}
	for(int i = 0; i < N; i++) cout << a[i] << " \n"[i == N - 1];
}
