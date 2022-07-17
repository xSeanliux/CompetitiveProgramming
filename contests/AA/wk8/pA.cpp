#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 326;

int N, p[maxN], ans[maxN], sz[maxN];
vector<int> chi[maxN];

int getSz(int u){
	sz[u] = 1;
	for(int v : chi[u]) sz[u] += getSz(v);
	return sz[u];
}

void dfs(int u){
	if(!chi[u].size()) return;
	sort(chi[u].begin(), chi[u].end(), [](int a, int b){
		return sz[a] > sz[b];
	});
	if(chi[u].size() == 1){
		ans[chi[u][0]] = ans[u];
		dfs(chi[u][0]);
	} else {
		ans[chi[u][0]] = ans[u] + (sz[chi[u][0]] == sz[chi[u][1]]);
		dfs(chi[u][0]);
		for(int i = 1; i < chi[u].size(); i++){
			ans[chi[u][i]] = ans[u] + 1;
			dfs(chi[u][i]);
		}
	}
}

int main(){
	cin >> N;
	for(int i = 2; i <= N; i++){
		cin >> p[i];
		chi[p[i]].push_back(i);	
	}
	getSz(1);
	dfs(1);
	for(int i = 2; i <= N; i++) cout << ans[i] << " \n"[i == N];
}
