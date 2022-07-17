#include <iostream>
using namespace std;


int N = 1000, x, y;

inline int Rand(){
	static int seed = 2003;
	return seed = (seed * 3 + 1) % 0xdefaced;
}

int main(){
	cout << N << endl;	
	for(int i = 0; i < N; i++){
		cout << Rand() % (int)(2e4) - (int)(1e4) << " " << Rand() % (int)(2e4) - (int)(1e4) << endl;
	}
}
