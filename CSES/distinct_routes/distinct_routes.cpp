#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


vector<vector<int>> ans;

const int maxN = 510;
int N, M, u, v, adj[maxN][maxN];
queue<int> id[maxN][maxN];

struct Flow{
	int cap[maxN][maxN], from[maxN], lv[maxN];
	bool vis[maxN];
	vector<int> ord;
	queue<int> que;
	void addEdge(int u, int v){
		cap[u][v] = 1;
	}
	bool BFS(){
		//cout << "running bfs" << endl;
		fill(vis, vis + N + 1, 0);	
		que = queue<int>();
		lv[1] = vis[1] = 1;
		que.push(1);
		while(que.size()){
			int u = que.front(); que.pop();
			//cout << "u = " << u << endl;
			for(int i = 1; i <= N; i++){
				if(cap[u][i] > 0 && !vis[i]){
					//cout << "i = " << i << endl;
					que.push(i);
					lv[i] = lv[u] + 1;
					from[i] = u;
					vis[i] = 1;
				}
			}
		}
		return vis[N];
	}
	void dfs(){
		vector<int>().swap(ord);
		//cout << "NEW ROUTE" << endl;
		int minV = 1e9;

		for(int i = N; i != 1; i = from[i]) minV = min(minV, cap[from[i]][i]);
		for(int i = N; i != 1; i = from[i]){
			//cout << i << "-" << from[i] << endl;
			ord.push_back(i);
			id[from[i]][i].push(ans.size());
			cap[from[i]][i] -= minV;
			cap[i][from[i]] += minV;
		}
		ord.push_back(1);
		reverse(ord.begin(), ord.end());
	}
	void run(){
		while(BFS()){
			vector<int>().swap(ord);
			dfs();
			ans.push_back(ord);
			//update thing	
		};
	}
} flow;

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		adj[u][v] = 1;
		flow.addEdge(u, v);
	}
	flow.run();
	cout << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		for(int j = 1; j < ans[i].size(); j++){
			if(!adj[ans[i][j - 1]][ans[i][j]]){ //oh jizz
				//cout << ans[i][j - 1] << " - " << ans[i][j] << " bad " << endl;
				int nid = id[ans[i][j]][ans[i][j - 1]].front();
				//cout << "nid = " << nid << endl;
				id[ans[i][j]][ans[i][j - 1]].pop();
				vector<int> A, B, C, D;
				A = vector<int>();
				B = vector<int>();
				C = vector<int>();
				D = vector<int>();
				for(int k = 0; k < ans[i].size(); k++){
					if(ans[i][k] == ans[i][j - 1]){
						k += 2;
						for(; k < ans[i].size(); k++) C.push_back(ans[i][k]);
						break;
					}
					A.push_back(ans[i][k]);
				}
				for(int k = 0; k < ans[nid].size(); k++){
					if(ans[nid][k] == ans[i][j]){
						k += 2;
						for(; k < ans[nid].size(); k++) D.push_back(ans[nid][k]);
						break;
					} 
					B.push_back(ans[nid][k]);
				}
				A.push_back(ans[i][j - 1]);
				B.push_back(ans[i][j]);
				vector<int>().swap(ans[i]);
				vector<int>().swap(ans[nid]);
				for(int x : A) ans[i].push_back(x);
				for(int x : B) ans[nid].push_back(x);
				for(int x : C) ans[nid].push_back(x);
				for(int x : D) ans[i].push_back(x);
				//cout << "A = "; for(int x : A) cout << x << " "; cout << endl;
				//cout << "B = "; for(int x : B) cout << x << " "; cout << endl;
				//cout << "C = "; for(int x : C) cout << x << " "; cout << endl;
				//cout << "D = "; for(int x : D) cout << x << " "; cout << endl;
			}
		}
	}
	for(auto v : ans){
		cout << v.size() << endl;
		for(int x : v) cout << x << " "; cout << endl;
	}
}
