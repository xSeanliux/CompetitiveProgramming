#include <iostream>
#include <map>
#include <set>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 326;
set<pii> doubleEdge, sameEdge;
map<int, char> adj[maxN];

int N, M, u, v, k;
char c, com;

int main(){
	ericxiao
	cin >> N >> M;
	while(M--){
		cin >> com;
		if(com == '+'){
			cin >> u >> v >> c; 
			adj[u][v] = c;
			if(adj[v].count(u)){
				doubleEdge.insert({u, v});
				doubleEdge.insert({v, u});
				if(adj[u][v] == adj[v][u]){
					sameEdge.insert({u, v});
					sameEdge.insert({v, u});
				}
			} 
		} else if(com == '-'){
			cin >> u >> v;
			if(adj[v].count(u)){
				doubleEdge.erase(doubleEdge.find({u, v}));
				doubleEdge.erase(doubleEdge.find({v, u}));
				if(adj[u][v] == adj[v][u]){
					sameEdge.erase(sameEdge.find({u, v}));
					sameEdge.erase(sameEdge.find({v, u}));
				}
			}
			adj[u].erase(v);
		} else {
			cin >> k;
			--k;
			if(!k){
				cout << "YES\n";
			} else if(k & 1){
				if(sameEdge.size()) cout << "YES\n";
				else cout << "NO\n";
			} else {
				if(doubleEdge.size()) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}
}
