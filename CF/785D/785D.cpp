#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int maxN = 2e5 + 10, MOD = 1e9 + 7;
int fact[maxN * 2], invfact[maxN * 2];
string s;

inline int modexp(int b, int e){
	int r = 1;
	while(e){
		if(e & 1) r = r * b % MOD;
		b = b * b % MOD;
		e >>= 1;
	}
	return r;
}

inline int inv(int x){
	return modexp(x, MOD - 2);
}

inline int choose(int a, int b){
	if(a < b) return 0;
	return fact[a] * invfact[b] % MOD * invfact[a - b] % MOD; 
}

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

int open[maxN], closed[maxN];

signed main(){
	fact[0] = invfact[0] = 1;
	cin >> s;
	for(int i = 1; i <= s.length() * 2; i++){
		fact[i] = fact[i - 1] * i % MOD;
		invfact[i] = inv(fact[i]);
	}
	open[0] = (s[0] == '(');
	closed[s.length() - 1] = (s[s.length() - 1] == ')');
	for(int i = 1; i < s.length(); i++){
		open[i] = open[i - 1] + (s[i] == '(');
		closed[s.length() - i - 1] = closed[s.length() - i] + (s[s.length() - i - 1] == ')');
	}
	int ans = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == ')') continue;
		ans = add(ans, choose(open[i] + closed[i] - 1, open[i]));
	}
	cout << ans << endl;
}
