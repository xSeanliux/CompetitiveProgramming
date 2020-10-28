#include <iostream>
#include <vector>
#include <utility>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e5 + 326; 

int N, vals[maxN], ans;
vector<int> adj[maxN], pos[maxN];
bool vis[maxN];

inline int oppo(int x){
	return x < N ? x + N : x - N;
}

pii dfs(int now){
	//cout << "running: " << now << endl;
	if(vis[now] || vis[oppo(now)]) return {0, 0};
	vis[now] = true;
	int X = 0, Y = 0;
	if(now < N){
		Y = 1;
	} else {
		X = 1;
	}
	for(auto x : adj[now]){
		if(vis[x]) continue;
		auto [a, b] = dfs(x);
		X += a;
		Y += b;
	}
	for(auto x : adj[oppo(now)]){
		if(vis[x]) continue;
		auto [a, b] = dfs(x);
		Y += a;
		X += b;
	}
	//cout << "Ans: " << X << ", " << Y << endl;
	return {X, Y};
}

int main(){
	cin >> N;
	for(int i = 0; i < 2 * N; i++){
		cin >> vals[i];
		pos[vals[i]].push_back(i);
	}
	for(int i = 1; i < maxN; i++){
		if(pos[i].size() == 2){
			int a = pos[i][0], b = pos[i][1];
			adj[a].push_back(oppo(b));
			adj[b].push_back(oppo(a));
		}
	}
	for(int i = 0; i < N; i++){
		if(vis[i]) continue;
		auto [a, b] = dfs(i);
		ans += min(a, b);
	}
	cout << ans << endl;
}
