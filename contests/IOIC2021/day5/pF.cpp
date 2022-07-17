#include <iostream>
#include <vector>
#include <unordered_set>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 326;
int T, N, arr[maxN], mf[maxN];
bool isPrime[maxN];
unordered_set<int> st[maxN];

inline void sieve(){
	fill(isPrime, isPrime + maxN, 1);
	fill(mf, mf + maxN, maxN);
	for(long long int i = 2; i < maxN; i++){
		if(isPrime[i]){
			mf[i] = i;
		}
		for(long long int j = i * i; j < maxN; j += i){
			isPrime[j] = false;
			if(isPrime[i]) mf[j] = min(mf[j], (int)i);
		}
	}
}

inline void solve(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
		st[i] = unordered_set<int>();
	}
	vector<int> upd;
	int ans = 0;
	for(int i = 1; i <= N; i++){
		//cout << "i = " << i << endl;
		bool can = 0;
		if(arr[i] == 1){
			can = true;
		} else {
			for(int k = i; k > 1; k /= mf[k]){
				//cout << "looking at " << k << ", " << mf[k] << endl;
				if(st[arr[i] - 1].count(mf[k])){
					can = 1;
					break;
				}
			}
		}
		if(can){
			ans = max(ans, arr[i]);
			for(int k = i; k > 1; k /= mf[k]) st[arr[i]].insert(mf[k]);
		}

	}
	cout << ans << '\n';
}

signed main(){
	ericxiao
	sieve();
	cin >> T;
	while(T--){
		solve();
	}
}
