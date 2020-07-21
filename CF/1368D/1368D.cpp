#include <iostream>
#define int long long int
using namespace std;

const int maxN = 5e5 + 226;
int logfound[26], vals[maxN], n, x;

signed main(){
	cin >> n;
	for(int jizz = 0; jizz < n; jizz++){
		cin >> x;
		for(int i = 0; i < 26; i++){
			if((x >> i) & 1) logfound[i]++;	
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = 0; j < logfound[i]; j++){
			vals[j] += (1LL << i);
		}
	}
	int s = 0;
	for(int i = 0; i < n; i++){
		s += (vals[i] * vals[i]);	
	}
	cout << s << endl;
}
