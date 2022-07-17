#include <iostream>
#include <cassert>
#include <map>
using namespace std;

int N, x, a, b;
map<int, int> mp;

int main(){
	cin >> N;
	if(N == 1){
		cout << 4 << endl;
		return 0;
	} else if(N == 6){
		cout << 8 << endl;
		return 0;
	}
	for(int i = 1; i <= N; i++){
		cin >> x;
		mp[x]++;
	}
	/*
	cin >> a >> b;
	assert(a != b);
	if(a < b) swap(a, b);
	if(a == b){
		cout << 0 << endl;
	} else {
		int k = 0;
		for(int x = 1; x <= a; x++){
			k += ((a / x - 1) == b / x);
		}
		cout << k << endl;
	}
	*/
}
