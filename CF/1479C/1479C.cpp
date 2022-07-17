#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 26;
int L, R, len[maxN];
vector<pii> adj[maxN];

int main(){
	cin >> L >> R;
	len[1] = len[2] = 1;
	adj[1].emplace_back(2, 1);
	for(int i = 3; i < maxN && (1 << (i - 2)) <= R; i++){
		adj[1].emplace_back(i, 1);
		for(int j = 2; j < i; j++) adj[j].emplace_back(i, (1 << (j - 2)));
	}
	if(L == 1){
		adj[1].emplace_back(maxN, 1);
		L++;
	}
	int s = 0;
	for(int i = maxN - 1; i >= 2; i--){ //ith has len i - 2
		if(((R - L + 1) >> (i - 2)) & 1){
			adj[i].emplace_back(maxN, L - 1 + s);
			s += (1 << (i - 2));
		}
	}
	cout << "YES\n";
	int m = 0; 
	for(int i = 1; i < maxN; i++) m += adj[i].size();
	cout << maxN << " "  << m << endl;
	for(int i = 1; i < maxN; i++) for(auto [u, w] : adj[i]) cout << i << " " << u << " " << w << endl;
}
