#include <iostream>
#include <unordered_map>
#include <set>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

int N;

unordered_map<int, int> mp;

int get(int x){
	if(mp.count(x)) return mp[x];
	if(x & 1) mp[x] = get(x / 2);
	else mp[x] = (get(x / 2) + get(x / 2 - 1)) % MOD;
	return mp[x];
}

int baoli_get(int x){
	set<int> st = set<int>();
	for(int i = 0; i <= (x + 1) / 2; i++){
		st.insert(i ^ (x - i));
	}
	return st.size();
}

inline int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}


signed main(){
	mp[0] = 1;
	while(cin >> N){
		cout << get(N) << " " << baoli_get(N) << endl;
	}
	cin >> N;	
	int ans = get(N) % MOD;
	for(int i = 0; i < 64; i++){
		if((N >> i) & 1){
			ans = (ans + exp(3, i) * get(N >> (i + 1)) % MOD) % MOD;
		}
	}	
	cout << ans << endl;
}
