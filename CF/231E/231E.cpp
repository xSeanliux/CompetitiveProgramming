#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 10, MOD = 1e9 + 7;

vector<int> adj[maxN], children[maxN], dfsadj[2 * maxN];
int N, M, Q, u, v, belong[maxN], counter = maxN, anc[2 * maxN][21], ddep[maxN], dep[2 * maxN], cnt[maxN * 2];
bool hasOut[maxN], hasIn[maxN], vis[maxN];

void dfs(int p = 1, int u = 1){
	vis[u] = true;	
	ddep[u] = ddep[p] + 1;
	for(int x : adj[u]){
		if(x == p) continue;
		if(vis[x]){
			if(ddep[x] < ddep[u]){
				hasIn[x] = true;
				hasOut[u] = true;
			}
		} else {
			children[u].push_back(x);
			dfs(u, x);
		}
	}
}

void DFS(int u = 1){
	//cout << "Running DFS(" << u << ")" << endl;
	for(int v : children[u]) DFS(v);

	if(hasOut[u]) belong[u] = counter++;
	else {
		belong[u] = u;
		for(int v : children[u]){
			if(belong[v] != v && !hasIn[v]) belong[u] = belong[v];
		}
	}
}

void getAnc(int p = belong[1], int u = belong[1]){
	dep[u] = dep[p] + 1;
	cnt[u] = cnt[p] + (u >= maxN);
	anc[u][0] = p;
	for(int i = 1; i < 20; i++) anc[u][i] = anc[anc[u][i - 1]][i - 1];
	for(int v : dfsadj[u]){
		if(v != p) getAnc(u, v);
	}
}

inline int kthAnces(int u, int k){
	for(int i = 0; i < 20; i++){
		if((k >> i) & 1) u = anc[u][i];
	}
	return u;
}

inline int LCA(int a, int b){
	if(dep[a] >= dep[b]) swap(a, b);
	b = kthAnces(b, dep[b] - dep[a]);
	if(a == b) return a;
	for(int i = 20; i >= 0; i--){
		if(anc[a][i] != anc[b][i]){
			a = anc[a][i];
			b = anc[b][i];
		}
	}
	return anc[a][0];
}

inline int modexp(int b, int e){
	int r = 1;
	for(int i = 0; i < 30; i++){
		if((e >> i) & 1) r = r * b % MOD;
		b = b * b % MOD;
	}
	return r;
}

void solve(int a, int b){
	int lca = LCA(a, b);
	//cout << "LCA(" << a << ", " << b << ") = " << lca << endl;
	int e = cnt[a] + cnt[b] - 2 * cnt[lca] + (lca >= maxN);
	cout << modexp(2, e) << endl;
}

signed main(){
	ericxiao;
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	DFS();
	for(int u = 1; u <= N; u++){
		//cout << "belong[" << u << "] = " << belong[u] << endl;
		for(int v : adj[u]){
			if(belong[u] != belong[v]){
				dfsadj[belong[u]].push_back(belong[v]);
			}
		}
	}
	getAnc();
	cin >> Q;
	while(Q--){
		cin >> u >> v;
		solve(belong[u], belong[v]);
	}
}
