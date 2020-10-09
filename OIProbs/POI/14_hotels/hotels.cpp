#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int maxN = 5e3 + 326;
int N, u, v, ans;
vector<int> adj[maxN], deps, curd[maxN];

void dfs(int p, int u, int dep){
	if(deps.size() == dep) deps.push_back(0);
	deps[dep]++;
	for(int v : adj[u]) if(v != p){
		dfs(u, v, dep + 1);
	}
}

inline void solve(int r){
	for(int i = 0; i < N; i++) vector<int>().swap(curd[i]);
	for(int x : adj[r]){
		vector<int>().swap(deps);
		dfs(r, x, 0);
		for(int i = 0; i < deps.size(); i++){
			curd[i].push_back(deps[i]);
		}
	}
	for(int i = 0; i < N; i++){
		if(curd[i].size() < 3) break;
		int sum = 0, ta = 0;
		for(int x : curd[i]){
			sum += x;
		}
		ta += (sum * (sum - 1) * (sum - 2)) / 6;
		for(int x : curd[i]){
			ta -= x * (x - 1) * (x - 2) / 6;
			ta -= x * (x - 1) / 2 * (sum - x);
		}
		ans += ta;
	}
}

signed main(){
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= N; i++) solve(i);
	cout << ans << endl;
}
