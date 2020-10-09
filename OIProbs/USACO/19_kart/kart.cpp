#include <iostream>
#include <vector>
#include <map>
using namespace std;


const int maxN = 1500 + 326;
int N, M, X, Y, u, v, belong[maxN], cnt;
vector<int> adj[maxN];
map<int, int> lens[maxN];

int main(){
	cin >> N >> M;
	for(int i = 0; i < M; i++){
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for(int i = 1; i <= N; i++){
		if(!belong[i]){
			belong[i] = cnt++;
		}
	}
}
