#include <iostream>
#include <numeric>
#include <vector>
#include <utility>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
#define vv vector<vector<int>>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 5e4 + 10, INF = 1e9 + 10;

int N, M, K, O, a, b, t, indeg[maxN], outdeg[maxN], dsu[maxN], toll[maxN], minDist[maxN];
bool visited[maxN];
vector<pii> adj[maxN];
vv seg[maxN * 4];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void build(int id = 0, int l = 0, int r = (N + K - 1) / K){
	//cout << "build id = " << id << ", l = " << l << ", r = " << r << endl;
	if(l + 1 == r){
		for(int i = 0; i < K; i++){
			for(int j = 0; j < K; j++){
				seg[id][i][j] = INF;
			}
			seg[id][i][i] = 0;
		}
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	for(int i = 0; i < K; i++){
		for(int j = 0; j < K; j++){
			seg[id][i][j] = INF;
		}
	}
	m--;
	//cout << "id = " << id << "m = " << m << endl;
	for(int i = 0; i < K; i++){
		//cout << "Node " << m * K + i << endl;
		for(auto [v, w] : adj[m * K + i]){
			//cout << "Looking at " << m * K + i << " and " << v << endl;
			//cout << " w = " << w << endl;
			//id: v % K	
			for(int j = 0; j < K; j++){
				for(int k = 0; k < K; k++){
					seg[id][j][k] = min(seg[id][j][k], seg[2 * id + 1][j][i] + w + seg[2 * id + 2][v % K][k]); 
				}
			}
		}
	}
}

vv query(int id, int ql, int qr, int l = 0, int r = (N + K - 1) / K){
	//cout << "Running id = " << id << ", ql = " << ql << ", qr = " << qr << ", l = " << l << ", r = " << r << endl;
	vv res;
	res.resize(K);
	for(int i = 0; i < K; i++) res[i].resize(K);
	if(ql >= r || l >= qr){
		for(int i = 0; i < K; i++){
			for(int j = 0; j < K; j++){
				res[i][j] = INF;
			}
			res[i][i] = 0;
		}
		return res;
	}
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	if(qr <= m) return query(2 * id + 1, ql, qr, l, m);
	if(ql >= m) return query(2 * id + 2, ql, qr, m, r);

	vv L = query(2 * id + 1, ql, qr, l, m), R = query(2 * id + 2, ql, qr, m, r);
	for(int i = 0; i < K; i++) for(int j = 0; j < K; j++) res[i][j] = INF;
	m--;
	for(int i = 0; i < K; i++){
		for(auto [v, w] : adj[m * K + i]){
			for(int j = 0; j < K; j++){
				for(int k = 0; k < K; k++)
					res[j][k] = min(res[j][k], L[j][i] + w + R[v % K][k]);	
			}
		}
	}
	return res;
}


int main(){
	//ericxiao;
	cin >> K >> N >> M >> O;
	for(int i = 0; i < maxN * 4; i++){
		seg[i].resize(K);
		for(int j = 0; j < K; j++){
			seg[i][j].resize(K);	
		}
	}
	for(int i = 0; i < M; i++){
		cin >> a >> b >> t;	
		adj[a].emplace_back(b, t);
	}
	build();	
	while(O--){
		cin >> a >> b;
		if(a / K == b / K){
			cout << -1 << endl;
			continue;
		}
		vv res = query(0, a / K, b / K + 1);
		cout << (res[a % K][b % K] == INF ? -1 : res[a % K][b % K]) << endl;
	}
}
