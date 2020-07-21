#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5 + 10, LIM = 1e4;
bool isPrime[LIM];
int n, x, ans[maxN][2];
vector<int> primes;

int gcd(int a, int b){
	return !b ? a : gcd(b, a % b);
}

void init(){
	fill(isPrime, isPrime + LIM, true);
	for(int i = 2; i < LIM; i++){
		if(isPrime[i]) primes.push_back(i);
		for(int p : primes){
			if(i * p >= LIM) break;
			isPrime[i * p] = false;
			if(!(i % p)) break;
		}
	}
}

int main(){
	ericxiao;
	cin >> n;
	init();
	for(int i = 0; i < n; i++){
		cin >> x;
		for(int p : primes){
			if(p * p > x) break;
			if(!(x % p)){
				int o = x;
				while(!(x % p)){
					x /= p;
				}
				if(x != 1){
					ans[i][0] = x;
					ans[i][1] = p;
				}
				break;
			}
		}
		
		if(!ans[i][0]) ans[i][0] = ans[i][1] = -1;
	}
	for(int i = 0; i < n; i++) cout << ans[i][0] << " \n"[i == n - 1];
	for(int i = 0; i < n; i++) cout << ans[i][1] << " \n"[i == n - 1];
}
