#include <iostream>
#include <numeric>
#include <unordered_set>
#include <fstream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 326;
int N, K, a, b, dsu[maxN], perm[maxN];
bool vis[maxN];
unordered_set<int> has[maxN];


void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	dsu[x] = dsu[dsu[x]];
}

inline void Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]) return;
	if(has[dsu[a]].size() > has[dsu[b]].size()) swap(a, b);
	for(int x : has[dsu[a]]) has[dsu[b]].insert(x);
	has[dsu[a]] = unordered_set<int>();
	dsu[dsu[a]] = dsu[b];
}

int main(){
	ericxiao
	cin >> N >> K;
	iota(perm, perm + N + 1, 0);
	iota(dsu, dsu + N + 1, 0);
	for(int i = 1; i <= N; i++) has[i].insert(i);
	while(K--){
		cin >> a >> b;
		has[perm[a]].insert(b);
		has[perm[b]].insert(a);
		swap(perm[a], perm[b]);
	}
	for(int i = 1; i <= N; i++){
		if(!vis[i]){
			int k = i;
			while(!vis[k]){
				Merge(k, perm[k]);
				vis[k] = true;
				k = perm[k];
			}
		}
	}
	for(int i = 1; i <= N; i++){
		Flat(i);
		cout << has[dsu[i]].size() << '\n';
	}
}
