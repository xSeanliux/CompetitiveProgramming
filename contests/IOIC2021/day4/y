#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

const int maxN = 1e4 + 326;
int T, N, x, arr[maxN], can[35];

int main(){
	cin >> T;
	while(T--){
		cin >> N;
		int s = 0;
		bool allO = true;
		for(int i = 0; i <N; i++){
			cin >> x;
			s ^= x;
			if(x != 1) allO = false;
		}
		if(s){
			cout << "Yes\n";
		} else {
			if(!allO){
				cout << "Yes\n";
			} else if(N & 1){
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
}
