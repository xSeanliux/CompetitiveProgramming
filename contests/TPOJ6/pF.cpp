#include <iostream>
#include <vector>
#include <string.h>
#include "grader.h"
using namespace std;

const int maxN = 2e3 + 326;
int N, xjizz, Mjizz;
long long int M, x;
vector<int> v;
string ans;

/*
void Init(int *N,int *X,int *MOD){
	cout << "N, x, M = " << endl;
	int a, b, c;
	cin >> a >> b >> c;
	*N = a;
	*X = b;
	*MOD = c;
	cout << "ans = " << endl;
	cin >> ans;
}
*/

long long int modpow(long long int b, long long int e){
	long long int r = 1;
	for(int i = 0; i < 40; i++){
		if((e >> i) & 1){
			r = r * b % M;
		}
		b = b * b % M;
	}
	return r;
}

long long int getinv(long long int x){
	return modpow(x, M - 2);
}

long long int add(long long int a, long long int b){
	return (a + b) % M;
}

long long int sub(long long int a, long long int b){
	return (a % M - b % M + M) % M;
}

long long int pres[maxN], inv;

string s;
/*
int Hash(int mod,int x,string s) {
	cout << "hashing: " << s << ", x = " << x << ", m = " << mod << endl;
	int ret = 0, len=s.length();
	for (int i=0;i<len;++i) {
	ret = (ret * 1LL * x + s[i]) % mod;
	}
	return ret;
}

int GetHash(vector<int> v){
	cout << "Getting hash of ";
	for(int x : v) cout << x << " ";
	cout << endl;
	int r = 0;	
	string c = "";
	int cnt = 0;
	for(int i = 0; i < ans.length(); i++){
		if(cnt < v.size() && i == v[cnt] - 1){
			r = add(r, Hash(M, x, c));
			cnt++;
			c = "";
		}
		c += ans[i];  
	}
	r = add(r, Hash(M, x, c));
	cout << "r = " << r << endl;
	return r;
}
*/
signed main(){
	Init(&N, &xjizz, &Mjizz);
	x = xjizz;
	M = Mjizz;
	vector<int> jizz;
	vector<int>().swap(jizz);
	jizz.push_back(1);
	pres[0] = 0;
	long long int alls = GetHash(jizz), inv = getinv(x);
	for(int i = 1; i < N; i++){
		vector<int> v;
		vector<int>().swap(v);
		v.push_back(1);
		v.push_back(i + 1);
		long long int q = GetHash(v);
		q = sub(alls, q);
		q = q * getinv( sub(modpow(x, N - i), 1LL) ) % M;
		q = q * modpow(inv, i) % M;
		pres[i] = q;
	}
	string s = "";
	for(int i = 1; i < N; i++){
		s += (char)((sub(pres[i], pres[i - 1]) * modpow(x, i) % M));
	}
	long long int hsh = 0;
	for(char c : s) hsh = (hsh * x + (int)c) % M;
	s += (char)((sub(alls, hsh * x % M)));
	Submit(s);
}

