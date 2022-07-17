#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 326;
vector<int> primes;

void sieve(){
	bool isPrime[maxN];
	fill(isPrime, isPrime + maxN, 1);
	for(int i = 2; i < maxN; i++){
		if(isPrime[i]) primes.push_back(i);
		for(int p : primes){
			if(i * p >= maxN) break;
			isPrime[i * p] = false;
			if(!(i % p)) break;
		}
	}
}

inline void solve(){
	int N;
	cin >> N;
	if(N == 1){
		cout << "(1)" << endl;
		return;
	}
	vector<pii> ans = vector<pii>();
	for(int p : primes){
		if(p > N) break;
		int k = N, cnt = 0;
		while(k){
			cnt += k / p;
			k /= p;
		}
		if(cnt) ans.emplace_back(p, cnt);
	}
	for(int i = 0; i < ans.size(); i++){
		cout << "(" << ans[i].F;
		if(ans[i].S > 1) cout << "^" << ans[i].S;
		cout << ")";
		cout << "*\n"[i == ans.size() - 1];
	}
}

int main(){
	sieve();
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}


