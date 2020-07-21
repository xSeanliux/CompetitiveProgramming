#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 226, MOD = 1e9 + 7;

vector<int> v;
int N;

int exp(int b, int e){
	int r = 1;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) r = (r * b) % MOD;
		b = b * b % MOD;
	}
	return r;
}

int solve(vector<int> v){
	//cout << "Solving: ";
	//for(int x : v) cout << x << " ";
	//cout << endl;
	for(int x : v) if(x <= 0) return -1;
	if(v.size() == 3 && v[0] > v[1] && v[2] > v[1]){
		int k = min(v[0], v[2]) / v[1];	
		vector<int> newv;
		newv.push_back(v[0] % v[1]);
		newv.push_back(v[1]);
		newv.push_back(v[2] % v[1]);
		int r = solve(newv);
		if(r == -1) return -1;
		return (exp(2, k) * (r + 2) % MOD - 2 + MOD) % MOD; 
	}
	if(v.size() <= 2){
		if(v[0] == 1 && v[1] == 1) return 0;
		if((v[0] == v[1])) return -1;
		if(v[0] == 1){
			int k = v[1] - 1;	
			return (exp(2, k) * (0 + 1) % MOD - 1 + MOD) % MOD; 
		} else if(v[1] == 1){
			int k = v[0] - 1;
			return (exp(2, k) * (0 + 2) % MOD - 2 + MOD) % MOD; 
		} 
		vector<int> newv;
		if(v[0] > v[1]){
			int k = v[0] / v[1];	
			newv.push_back(v[0] % v[1]);
			newv.push_back(v[1]);
			int r = solve(newv);
			if(r == -1) return -1;
			return (exp(2, k) * (r + 2) % MOD - 2 + MOD) % MOD; 
		} else {
			int k = v[1] / v[0];	
			newv.push_back(v[0]);
			newv.push_back(v[1] % v[0]);
			int r = solve(newv);
			if(r == -1) return -1;
			return (exp(2, k) * (r + 1) % MOD - 1 + MOD) % MOD; 
		}
	} 
	bool inc = (v[0] < v[1]);
	if(inc){
		for(int i = 0; i < v.size() - 2; i += 2){
			if(v[i] + v[i + 2] != v[i + 1]) return -1;
		}
	} else {
		for(int i = 1; i < v.size() - 3; i += 2){
			if(v[i] + v[i + 2] != v[i + 1]) return -1;
		}
	}
	for(int i = 0; i < v.size() - 1; i++){
		if(inc){
			if((i % 2) && v[i] <= v[i + 1]) return -1;
			if(!(i % 2) && v[i] >= v[i +1]) return -1;
		} else {
			if((i % 2) && v[i] >= v[i + 1]) return -1;
			if(!(i % 2) && v[i] <= v[i + 1]) return -1;
		}
	}
	vector<int> newv;
	if(!inc){
		newv.push_back(v[0] - v[1]);
	}
	for(int i = 1 - inc; i < v.size(); i += 2){
		newv.push_back(v[i]);
	}
	if((inc && v.size() % 2 == 0) || (!inc && v.size() % 2 == 1)) newv.push_back(v[v.size() - 1] - v[v.size() - 2]);	
	int res = solve(newv);
	if(res == -1) return -1;
	else if(inc){
		return (2 * res + 1) % MOD;	
	} else {
		return (2 * res + 2) % MOD;	
	}
}

signed main(){
	ericxiao;
	cin >> N;
	v.resize(N);
	for(int i = 0; i < N; i++) cin >> v[i];	
	cout << solve(v);
}


