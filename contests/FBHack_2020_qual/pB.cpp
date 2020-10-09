#include <iostream>
#include <string.h>
using namespace std;

int T, N, a, b, c;
string s;

inline void solve(){
	cin >> N >> s;
	a = b = 0;
	for(char ch : s){
		(ch == 'A' ? a : b)++;
	}
	if(a + 1 == b || b + 1 == a){ 
		cout << "Case #" << ++c << ": Y\n";
	} else {
		cout << "Case #" << ++c << ": N\n";
	}
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
