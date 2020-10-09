#include <iostream>
#include <vector>
#include <queue>
#include <set>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 226;
set<int> adj[maxN];

int N, u, v, root, to[maxN], c;
bool vis[maxN];
queue<int> que;

int main(){
	ericxiao;
	cin >> N;
	for(int i = 0; i < N - 1; i++){
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	for(int i = 1; i <= N; i++){
		if(adj[i].size() == 1) que.push(i);
		to[i] = i;
	}
	while(que.size()){
		int f = que.front();
		que.pop();
		if(to[f] == f){
			c += 2;
			swap(to[f], to[*adj[f].begin()]);
		}
		adj[*adj[f].begin()].erase(f);
		adj[f].erase(adj[f].begin());
		if(adj[*adj[f].begin()].size() == 1) que.push(f);
	}
	cout << c << endl;
	for(int i = 1; i <= N; i++) cout << to[i] << " \n"[i == N];
}
