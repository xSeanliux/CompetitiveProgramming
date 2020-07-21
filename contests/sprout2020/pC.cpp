#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long int
using namespace std;

int T, mods[3];
string s;

inline int mod(int a){
	return (a % 11 + 121) % 11;
}

inline int add(int a, int b){
	return (a % 11 + b % 11 + 12100) % 11;
}

void solve(){
	cin >> s;
	reverse(s.begin(), s.end());
	int ind = 0, numat = 0, pos = 0;
	mods[0] = mods[1] = mods[2] = 0LL;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'X' || s[i] == '='){
			ind++;
			numat = 0;
			continue;
		}
		numat ^= 1;
		if(s[i] == '?'){
			pos = i;
			continue;
		}
		mods[ind] = add(mods[ind], (numat ? 1 : -1) * (s[i] - '0'));
	}
	int res = add(mods[1] * mods[2], -mods[0]);
	if(pos % 2 == 0){
		cout << res % 11 << endl;
	} else {
		cout << (11 - res) % 11 << endl;
	}
}

signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
