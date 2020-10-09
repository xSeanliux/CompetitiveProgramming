#include <iostream>
#define int long long int
using namespace std;

int k;
const string cf = "codeforces";

inline int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = r * b;
		if((e >> i) == 0) return r;
		b = b * b;
	}
	return r;
}

signed main(){
	cin >> k;	
	int x;
	for(x = 1;; x++){
		if(exp(x + 1, 10) > k) break;
	}
	//cout << x << endl;
	for(int i = 0; i <= 10; i++){
		if(exp(x + 1, i) * exp(x, 10 - i) >= k){
			//cout << "i = " << i << endl;
			for(int j = 0; j < 10; j++){
				for(int l = 0; l < x; l++){
					cout << cf[j];
				}
				if(j < i) cout << cf[j];
			}
			return 0;
		}
	}
}
