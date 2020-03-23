#include <iostream>
#include <vector>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e3 + 10, INF = 1e9;
vector<int> adj[maxN], treeAdj[maxN];
int N, k, x, sts[maxN], ans = INF;
bool visited[maxN];
queue<int> que;

void dfs(int p, int u){
	sts[u] = 1;
	for(int v : treeAdj[u]){
		dfs(u, v);
		sts[u] += sts[v];
	}
}

int main(){
	ericxiao;
	cin >> N;	
	for(int i = 1; i <= N; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> x;
			adj[x].push_back(i);
		}
	}
	for(int root = 1; root <= N; root++){
		//cout << "root = " << root << endl;
		//que = queue<int>();		
		for(int i = 1; i <= N; i++) {
			treeAdj[i].clear();
			visited[i] = false;
		}
		que.push(root);
		visited[root] = true;
		int ec = 0; // <3
		while(que.size()){
			int t = que.front();
			que.pop();
			for(int v : adj[t]){
				if(!visited[v]){
					treeAdj[t].push_back(v);
					ec++;
					visited[v] = true;
					que.push(v);
				}
			}
		}
		if(ec != N - 1) continue;
		dfs(root, root);
		int s = 0;
		for(int i = 1; i <= N; i++) s += sts[i];
		ans = min(s, ans);
	}
	cout << ans << endl;
}
