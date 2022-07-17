#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 1e6 + 326;
vector<int> primes;
int table[maxN], minPri[maxN];

inline void sieve(){
	bool isPrime[maxN];
	fill(isPrime, isPrime + maxN, true);
	for(int i = 2; i < maxN; i++){
		if(isPrime[i]){
			primes.push_back(i);
			minPri[i] = i;
		}
		for(int p : primes){
			if(p * i >= maxN) break;
			isPrime[i * p] = false;
			minPri[i * p] = p;
			if(!(i % p)){
				break;
			} 	
		}
	}
	for(int i = 2; i < maxN; i++){
		//if(i < 100) cout << "mp[" << i << "] = " << minPri[i] << endl;
		if(isPrime[i]) table[i] = 1;
		else {
			if((i / minPri[i]) % minPri[i] == 0) table[i] = table[i / minPri[i]];
			else table[i] = table[i / minPri[i]] + 1;
		}
		//if(i < 100) cout << "tab[" << i << "] = " << table[i] << endl;
	}
}

inline int func(int x){
	if(x == 1) return 1;
	if(x < maxN) return (1LL << table[x]);
	int cnt = 0;
	for(int p : primes){
		if(p * p > x) break;
		if(!(x % p)){
			cnt++;
			while(!(x % p)) x /= p;
		}
	}
	if(x > 1) cnt++;
	return (1LL << cnt);
}

inline void solve(){
	int c, d, x, ans = 0;
	cin >> c >> d >> x;	
	for(int g = 1; g * g <= x; g++){
		if(!(x % g)){
			if((g * d + x) % (c * g) == 0){
				ans += func((g * d + x) / (c * g));
			} 
			if(g * g != x){
				if(((x / g) * d + x) % (c * (x / g)) == 0){
					ans += func(((x / g) * d + x) / (c * (x / g)));
				}
			}
		}
	}
	cout << ans << endl;
}

signed main(){
	sieve();	
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}
