#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 2e5 + 10;
int n, m, u, v, t, a[maxN], b[maxN], c[maxN], indeg[maxN], ord[maxN];
vector<int> adj[maxN];
queue<int> que;

inline void solve(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) vector<int>().swap(adj[i]);
	fill(indeg, indeg + n + 1, 0);
	fill(ord, ord + n + 1, -1);
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i] >> c[i];
		if(a[i]){
			indeg[c[i]]++;
			adj[b[i]].push_back(c[i]);
		}
	}
	que = queue<int>();
	for(int i = 1; i <= n; i++){
		if(!indeg[i]) que.push(i);	
	}
	int cnt = 0;
	while(que.size()){
		int t = que.front();
		que.pop();
		ord[t] = cnt++;
		for(int x : adj[t]){
			indeg[x]--;
			if(!indeg[x]) que.push(x);
		}
	}
	for(int i = 1; i <= n; i++){
		if(ord[i] == -1){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < m; i++){
		if(a[i]) cout << b[i] << " " << c[i] << endl;
		else if(ord[b[i]] < or[c[i]]) cout << b[i] << " " << c[i] << endl;
		else cout << c[i] << " " << b[i] << endl;
	}
}

int main(){
	cin >> t;
	while(t--){
		solve();
	}
}
