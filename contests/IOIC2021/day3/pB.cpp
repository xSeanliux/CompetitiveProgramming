#include <iostream>
#include <vector>
using namespace std;

vector<int> primes;

const int maxN = 1e4 + 326, MOD = 998244353;

bool isPrime[maxN];
int mu[maxN], dp[maxN][maxN];

inline void sieve(){
	fill(isPrime, isPrime + maxN, true);
	for(int i = 2; i < maxN; i++){
		if(isPrime[i]){
			primes.push_back(i);
			mu[i] = -1;
		}
		for(int p : primes){
			if(p * i >= maxN) break;
			isPrime[i * p] = false;
			if(!(i % p)){
				mu[i] = 0;
				break;
			}
			mu[i * p] = -mu[p];
		}
	}
}

signed main(){
	sieve();
	for(int i = 1; i < maxN; i++) dp[i][1] = 1;	
	for(int m = 2; m < maxN; m++){
		for(int s = m; s < maxN; s++) dp[s][m] = (dp[s - m][m] + dp[s][m - 1]) % MOD;
	}
	long long int ans = 0, N, K;
	cin >> N >> K;
	N /= K;
	for(int i = 1; i < N; i++){
		ans = (ans + mu[i] * dp[N / i][maxN - 1]) % MOD;
	}
	cout << (MOD - ans) % MOD << endl;
}

