#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int maxN = 2e3 + 326, maxC = 2e5 + 326;

int N, arr[maxN], mat[maxN];
bool sel[maxN], vis[maxN], isPrime[maxC], isIn[maxN];
vector<int> ans, adj[maxN];

void sieve(){
	fill(isPrime, isPrime + maxC, 1);
	for(int i = 2; i < maxC; i++){
		for(int j = 2 * i; j < maxC; j += i) isPrime[j] = false;
	}
}

bool dfs(int now){
	vis[now] = 1;
	for(int v : adj[now]){
		if(!mat[v] || (!vis[mat[v]] && dfs(mat[v]))){
			mat[v] = now;
			mat[now] = v;
			return true;
		}
	}
	return false;
}

void alt(int now){
	vis[now] = true;
	for(int v : adj[now]){
		if(!vis[v]){
			vis[v] = true;
			alt(mat[v]);
		}
	}
}

int main(){
	sieve();
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];
	}
	for(int i = 1; i <= N; i++) for(int j = i + 1; j <= N; j++) if(isPrime[arr[i] + arr[j]]){
		adj[i].push_back(j);
		adj[j].push_back(i);
	}
	//cout << "fl = " << fl << endl;
	//get solution
	for(int i = 1; i <= N; i++) if((arr[i] & 1) && !mat[i]){
		fill(vis, vis + N + 1, 0);
		dfs(i);
	}
	fill(vis, vis + N + 1, 0);
	for(int i = 1; i <= N; i++) if((arr[i] & 1) && !mat[i]) alt(i);
	for(int i = 1; i <= N; i++) if((arr[i] & 1) & (vis[i])) ans.push_back(arr[i]);
	cout << ans.size() << endl;
	for(int x : ans) cout << x << " ";
}
