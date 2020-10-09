#include <iostream>
#include <vector>
using namespace std;

const int maxN = 2e5 + 10;
vector<int> adj[maxN], ord;
bool vis[maxN];

int N, M, K, u, v;

void dfs(int u = 1){
	ord.push_back(u);
	vis[u] = true;
	for(int v : adj[u]){
		if(!vis[v]){
			dfs(v);
			ord.push_back(u);
		}
	}
}

int ceil(int a, int b){
	return (a + b - 1) / b;
}

int main(){
	cin >> N >> M >> K;
	while(M--){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	int cnt = 0, bs = ceil(2 * N, K);
	for(int i = 0; i < K; i++){
		if(cnt == ord.size()){
			cout << "1 1\n";
			continue;
		} else {
			cout << min(bs, (int)ord.size() - i * bs) << " ";
			for(int j = 0; j < bs && cnt < ord.size(); j++, cnt++){
				cout << ord[cnt] << " ";	
			}
			cout << endl;
		}
	}
}
