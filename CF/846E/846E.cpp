#include <iostream>
#include <vector>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;
int pa[maxN], wei[maxN], has[maxN], need[maxN], N, isLeaf[maxN], stillneed[maxN];
bool isViable[maxN];
vector<int> chi[maxN];

void dfs(int u = 0){
	for(int v : chi[u]){
		dfs(v);
		if(!isViable[v]){
			isViable[u] = false;
			return;
		}
		if(stillneed[v]){
			//cout << "YES: " << v << endl;
			if(stillneed[v] >= ((int)1e17 + has[u] - need[u] + wei[v] - 1) / wei[v]){
				isViable[u] = false;
				//cout << u << " not viable " << endl;
				return;
			}
			has[u] -= stillneed[v] * wei[v];
			has[v] += stillneed[v];
		}
	}
	//cout << "has[" << u << "] = " << has[u] << endl;
	if(has[u] >= need[u]){
		stillneed[u] = 0;
		if(pa[u] != u)
			has[pa[u]] += has[u] - need[u];
		has[u] = need[u];
	} else {
		stillneed[u] = need[u] - has[u];
	}
}

signed main(){
	ericxiao;
	cin >> N;
	fill(isViable, isViable + N, true);
	fill(isLeaf, isLeaf + N, true);
	for(int i = 0; i < N; i++) cin >> has[i];
	for(int i = 0; i < N; i++) cin >> need[i];
	for(int i = 1; i < N; i++){
		cin >> pa[i] >> wei[i];
		pa[i]--;
		chi[pa[i]].push_back(i);	
		isLeaf[pa[i]] = false;
	}
	dfs();
	cout << (has[0] >= need[0] && isViable[0] ? "YES" : "NO") << endl;
}
