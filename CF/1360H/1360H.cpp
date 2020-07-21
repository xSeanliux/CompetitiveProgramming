#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long int
using namespace std;

const int maxN = 100 + 26;
int t, n, m, stuff[maxN];
string s;

inline int toInt(string s){
	int r = 0;
	for(char c : s){
		r = (r << 1) + (c ^ '0');
	}
	return r;
}

inline string toStr(int x){
	string res = "";
	while(x){
		res = (char)((x & 1) + '0') + res;
		x /= 2;
	}
	while(res.length() < m) res = '0' + res;	
	return res;
}

inline int solve(){	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> s;
		stuff[i] = toInt(s);
	}
	sort(stuff, stuff + n);
	for(int i = max(0LL, (1LL << (m - 1)) - 100); ; i++){
		if(*lower_bound(stuff, stuff + n, i) == i) continue;
		if((i + 1 - (lower_bound(stuff, stuff + n, i) - stuff + 1)) == ((1LL << m) - n - 1) / 2){
			return i;
		}
	}
}	

signed main(){
	cin >> t;
	while(t--){
		cout << toStr(solve()) << endl;
	}
}
