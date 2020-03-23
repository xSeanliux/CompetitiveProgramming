#include <iostream>
using namespace std;

int N, T;

int main(){
	cin >> T;
	while(T--){
		cin >> N;
		if(N == 1){
			cout << -1 << endl;
			continue;
		} 
		cout << 2;
		for(int i = 0; i < N - 1; i++) cout << 3;
		cout << endl;
	}
}
