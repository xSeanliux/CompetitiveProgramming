#include <iostream>
#include <vector>
#include <fstream>
#define cin infile
#define cout outfile
#define int long long int
using namespace std;

const int maxN = 1e6 + 326, MOD = 1e9 + 7;
int N;
bool isPrime[maxN];
vector<int> primes;
/*
void dfs(int now = 0){
	if(now == N){
		fill(narr, narr + N + 1, 0);
		int mx = -1, mn = maxN;
		for(int i = 0; i < N; i++){
			narr[i]++;
			if(i + arr[i] > N){
				narr[N]--;
				narr[0]++;
				narr[i + arr[i] - N]--;
			} else {
				narr[i + arr[i]]--;
			}
		}
		for(int i = 1; i < N; i++) narr[i] += narr[i - 1];
	
		bool f = true;
		for(int i = 0; i < N; i++){
			f &= (arr[i] == narr[i]);
			mx = max(mx, arr[i]);
			mn = min(mn, arr[i]);
		}
		if(f){
			for(int i = 0; i < N; i++) cout << arr[i] << " \n"[i == N - 1];
			cnt++;
			//cout << "m/M: " << mn << ", " << mx << endl;
		}
		return;
	} 
	if(!now){
		for(int i = 1; i <= N; i++){
			arr[now] = i;
			dfs(now + 1);
		}
	} else {
		if(arr[now - 1] > 1){
			arr[now] = arr[now - 1] - 1;
			dfs(now + 1);
		}
		arr[now] = arr[now - 1];
		dfs(now + 1);
		if(arr[now - 1] < N){
			arr[now] = arr[now - 1] + 1;
			dfs(now + 1);
		}
	}
}
*/

ifstream infile;
ofstream outfile;

inline void IO(){
	infile.open("gymnasts.in");
	outfile.open("gymnasts.out");
}

inline void sieve(){
	for(int i = 2; i < maxN; i++){
		if(!isPrime[i]){
			primes.push_back(i);
		}
		for(int p : primes){
			if(i * p >= maxN) break;
			isPrime[i * p] = true;
			if(!(i % p)){
				break;
			} 
		}
	}
}

inline int phi(int x){
	int r = x, n = x;
	for(int p : primes){
		if(p * p > n) break;
		if(!(n % p)){
			n /= p;
			r /= p;
			r *= p - 1;
			while(!(n % p)){
				n /= p;
			}
		}
	}
	if(n > 1){
		r /= n;
		r *= n - 1;
	}
	//cout << "phi(" << x << ") = " << r << endl;
	return r % MOD;
}

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

inline int modpow(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

signed main(){
	IO();
	cin >> N;	
	sieve();
	int ans = 1 + phi(N), roll = 2;
	for(int d = 2; d * d <= N; d++){
		if(!(N % d)){
			ans = add(ans, (modpow(2, d) - 1 + MOD) * phi(N / d) % MOD);
			if(d != N / d) ans = add(ans, ((modpow(2, N / d) - 1 + MOD) % MOD) * phi(d) % MOD);
		}
	}
	cout << ans << endl;
}
