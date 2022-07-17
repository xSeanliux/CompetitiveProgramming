#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ll __int128
using namespace std;

const int maxN = 1e6 + 326;
int T, n, x;
bool isPrime[maxN];
vector<int> primes, pf;

inline void sieve(){
	fill(isPrime, isPrime + maxN, true);
	for(int i = 2; i < maxN; i++){
		if(isPrime[i]) primes.push_back(i);
		for(int p : primes){
			if(p * i >= maxN) break;
			isPrime[i * p] = false;
			if(!(i % p)) break;
		}
	}
}


void gcd(int a, int b, ll &x, ll &y){
	if(!b){
		x = (a > 0 ? 1 : -1);
		y = 0;
		return;
	}
	gcd(b, a % b, x, y);
	ll nx = y, ny = (x - (a / b) * y); 
	x = nx, y = ny;
}

void disp(ll x){
	string s = "";
	while(x){
		s += (char)(x % 10 + '0');
		x /= 10;
	}
	reverse(s.begin(), s.end());
	if(s == "") s = "0";
	cout << s << endl;
}
void solve(){
	cin >> n >> x;
	vector<int>().swap(pf);
	int t = 2 * x;
	for(int p : primes){
		if(p > t) break;
		if(!(t % p)){
			int k = 1;
			while(!(t % p)){
				k *= p;
				t /= p;
			}
			pf.push_back(k);
		}
	}
	if(t > 1) pf.push_back(t);
	__int128 ans = 0;
	for(int i = 0; i < (1 << (pf.size())); i++){
		ll p = 1, q = 1;
		for(int j = 0; j < pf.size(); j++){
			(((i >> j) & 1) ? p : q) *= pf[j];
		}
		//cout << "p = " << p << ", q = " << q << endl;
		ll a, b;
		gcd(p, -q, a, b);
		//cout << p << "*" <<  a << " - " << q << "*" << b << endl;
		b %= p;
		if(b < 0) b += p;
		//cout << "starting with k = " << q * b << " with jumps of " << q * p << endl;
		if(q * b > n) continue;
		ans += max((ll)0, (n - q * b) / (q * p) + 1);
	}
	//for(int x : st) cout << x << endl;
	disp(ans - 1);
}

signed main(){
	sieve();
	cin >> T;
	while(T--){
		solve();
	}
}
