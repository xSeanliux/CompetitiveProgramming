#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int maxN = 1e6 + 10, MOD = 1e9 + 7, B = 101;
string s;
int N, T, hsh[maxN], revHsh[maxN];
int pw[maxN];

int mpow(int b, int e){
	int r = 1, c = b;
	for(int i = 0; i < 30; i++){
		if((e >> i) & 1) r = r * c % MOD;
		c = c * c % MOD;
	}
	return r;
}

bool isPalindrome(int l, int r){
	//cout << "Running " << l << ", " << r << endl;
	if(l == r) return true;
	int rad = (r - l + 1) / 2;
	//cout << "Rad = " << rad << endl;
	int a, b;
	a = ((hsh[l + rad - 1] - (l ? hsh[l - 1] : 0) * pw[rad]) % MOD + MOD) % MOD;
	b = (revHsh[r - rad + 1] - (revHsh[r + 1] * pw[rad] % MOD) + MOD) % MOD;
	//cout << "a = " << a << ", b = " << b << ", lr = " << l << ", " << r <<  endl;
	return a == b;
}


string solve(){
	N = s.length();
	hsh[0] = s[0];
	revHsh[N - 1] = s[N - 1];
	revHsh[N] = 0;
	for(int i = 1; i < N - 1; i++){
		hsh[i] = (hsh[i - 1] * B % MOD + s[i]) % MOD;
		revHsh[N - 1 - i] = (revHsh[N - i] * B % MOD + s[N - 1 - i]) % MOD;
		//cout << "revhsh[" << N - 1 - i << "] = " << revHsh[N - 1 - i] << endl;
	}
	int maxL = 0;
	for(int i = 1; i - 1 < N - i; i++){
		if(hsh[i - 1] == revHsh[N - i]) maxL = i;	
	}
	//cout << "maxL = " << maxL << endl;
	//left: N - maxL * 2 chars
	int mxL = 0, mxR = 0;
	for(int len = 1; len + maxL * 2 <= N; len++){
		if(isPalindrome(maxL, maxL + len - 1)){
			mxL = len;
			//cout << maxL << " ~ " << maxL + len - 1 << " is pal " << endl;
		}	
	}
	for(int len = 1; len + 2 * maxL <= N; len++){
		if(isPalindrome(N - maxL - len, N - maxL - 1)){
			mxR = len;
			//cout << N - maxL - len << ", " << N - maxL - 1 << " is pal " << endl;
		}
	}
	string ans = "";
	//cout << maxL << ", " << mxL << ", mxR " << mxR << endl;
	if(mxL > mxR){
		for(int i = 0; i < maxL + mxL; i++) ans += s[i];
		for(int i = N - maxL; i < N; i++) ans += s[i];
	} else {
		for(int i = 0; i < maxL; i++) ans += s[i];
		for(int i = N - maxL - mxR; i < N; i++) ans += s[i];
	}
	return ans;
}

signed main(){
	cin >> T;
	pw[0] = 1;
	for(int i = 1; i < maxN; i++) pw[i] = pw[i - 1] * B % MOD;
	while(T--){
		cin >> s;
		cout << solve() << endl;
	}
}
