#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 1, maxM = 2e6 + 10;

int N, M, u, v, ans, t, last[maxN], nxt[maxN], prv[maxN], cnt, vis[maxN], dsu[maxN], sz[maxN];

void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	dsu[x] = dsu[dsu[x]];
}

void Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]) return;
	sz[dsu[a]] += sz[dsu[b]];
	dsu[dsu[b]] = dsu[a];
}

struct Edge{
	int v, to;
} edges[maxM << 1];

queue<int> que;

void addEdge(int u, int v){
	edges[cnt] = {v, last[u]};
	last[u] = cnt++;
}

void del(int x){	
	int _p = prv[x];
	nxt[_p] = nxt[x];
	prv[nxt[x]] = _p;
}

void bfs(int src){
	que.push(src);
	int t;
	while(que.size()){
		t = que.front();
		que.pop();
		for(int cur = last[t]; ~cur; cur = edges[cur].to) vis[edges[cur].v]++;
		for(int i = nxt[0]; i; i = nxt[i]) if(!vis[i]){
			del(i);
			Merge(t, i);
			que.push(i);
		}
		for(int cur = last[t]; ~cur; cur = edges[cur].to) vis[edges[cur].v]--;
	}

}

vector<int> szs;

int main(){
	ericxiao;
	cin >> N >> M;
	iota(dsu, dsu + N + 1, 0);
	fill(sz, sz + N + 1, 1);
	fill(last + 1, last + 1 + N, -1);
	for(int i = 0; i <= N; i++){
		prv[i] = i - 1;
		nxt[i] = i + 1;
	}
	prv[0] = nxt[N] = 0;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		addEdge(u, v);
		addEdge(v, u);
	}
	for(int i = nxt[0]; i; i = nxt[0]){
		del(i);
		ans++;
		//cout << "Running bfs(" << nxt[0] << ")" << endl;
		bfs(i);
	}
	for(int i = 1; i <= N; i++){
		Flat(i);
		if(i == dsu[i]) szs.push_back(sz[i]);
	}
	sort(szs.begin(), szs.end());
	cout << ans << endl;
	for(int x : szs) cout << x << " ";
	cout << endl;
}
