#include <queue>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

const int maxN = 2e5 + 226;
int T, N, M, a, b;
vector<int> jizz; 
set<int> ans, in[maxN], out[maxN];
bool visited[maxN];

inline void rem(int &x){
	for(int y : in[x]){
		out[y].erase(x);	
	}
	for(int y : out[x]){
		in[y].erase(x);
	}
	ans.insert(x + 1);
}

void solve(){
	cin >> N >> M;
	ans = set<int>();
	for(int i = 0; i < N; i++){
		in[i] = out[i] = set<int>();
		visited[i] = false;
	}
	for(int i = 0; i < M; i++){
		cin >> a >> b;
		a--, b--;
		in[b].insert(a);
		out[a].insert(b);
	}
	for(int i = 0; i < N; i++){
		if(visited[i]) continue;
		visited[i] = true;
		bool f = true;
		vector<int>().swap(jizz);
		for(int x : out[i]){
			if(!f) break;
			for(int y : out[x]){
				if(!f) break;	
				if(out[i].count(y)){
					f = false;
					for(int u : out[i]){
						jizz.push_back(u);
						visited[u] = true;
					}
					break;
				}
			}
		}
		for(int u : jizz) rem(u);
		if(!f) continue;
		for(int x : out[i]){
			visited[x] = true;
			for(int y : out[x]){
				jizz.push_back(y);
				visited[y] = true;
			}
		}
		for(int x : jizz) rem(x);
	}
	cout << ans.size() << endl;
	for(int t : ans) cout << t << " ";
	cout << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
