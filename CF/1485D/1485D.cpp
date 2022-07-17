#include <iostream>
using namespace std;

const int maxN = 500 + 326;
int x, N, M;

int main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++){
		cin >> x;
		cout << 720720 + ((i + j) & 1) * (x * x * x * x) << " \n"[j == M - 1];
	}
}
