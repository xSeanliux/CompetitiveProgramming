#include <iostream>
#include <set>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<set<int> > adj;
const int maxN = 1e5 + 10, INF = 1e7;
int N, M, a, b, x;

struct CentroidDecomp{
	vector<set<int> > adj;
	vector<int> ances, vals, cdep, dist[20];
	int N, sts[maxN];
	CentroidDecomp(){}
	CentroidDecomp(int N): N(N){
		adj.resize(N + 1);
		ances.resize(N + 1);
		cdep.resize(N + 1);
		vals.resize(N + 1);
		fill(vals.begin(), vals.end(), INF);
		for(int i = 0; i < 20; i++) dist[i].resize(N + 1);
	}
	void addEdge(int u, int v){
		adj[u].insert(v);
		adj[v].insert(u);
	}
	void decompose(int u, int p, int dpth){
		//cout << "Running decompose(" << u << ", " << p << ") " << endl;
		getSts(u, p);
		int centroid = getCentroid(u, p, sts[u]);
		//cout << "Centroid = " << centroid << endl;
		if(p == -1) p = centroid;
		ances[centroid] = p;
		cdep[centroid] = dpth;
		dist[dpth][centroid] = 0;
		getDist(-1, centroid, dpth);
		vector<int> out;
		for(int v : adj[centroid]){
			adj[v].erase(centroid);
			out.push_back(v);
			decompose(v, centroid, dpth + 1);
		}
		for(int v : out) adj[centroid].erase(v);
	}

    void getDist(int p, int u, int d){
        for(int x : adj[u]){
            if(x == p) continue;
            dist[d][x] = dist[d][u] + 1;
            getDist(u, x, d);
        }
    }

	void show(){
		cout << "SHOWING" << endl;
		for(int i = 1; i <= N; i++) cout << "Anc(" << i << ") = " << ances[i] << endl;
	}
	void getSts(int u, int p){
		sts[u] = 1;
		for(int v : adj[u]){
			if(v == p) continue;
			getSts(v, u);
			sts[u] += sts[v];
		}
	}
	int getCentroid(int u, int p, int sz){
		for(int v : adj[u]){
			if(v == p) continue;
			if(sts[v] > sz / 2) return getCentroid(v, u, sz);
		}
		return u;
	}
	void modify(int node){
		//cout << "Modifying node " << node << endl;
		int x = node, d = cdep[node];
		do{
			//cout << "At node " << node << endl;
			vals[x] = min(vals[x], dist[d][node]);
			x = ances[x];
			d--;
		} while(ances[x] != x);
		vals[x] = min(vals[x], dist[d][node]);
	}
	int query(int node){
		//cout << "Query node " << node << endl;
		int x = node, minval = INF, d = cdep[node];
		do{
			//cout << "At node " << x << endl;
			minval = min(minval, dist[d][node] + vals[x]);
			x = ances[x];
			d--;
		} while(ances[x] != x);
		//cout << "At node " << x << endl;
		minval = min(minval, dist[d][node] + vals[x]);
		return minval;
	}
} cd;


int main(){
	ericxiao;
	cin >> N >> M;
	cd = CentroidDecomp(N);
	for(int i = 0; i < N - 1; i++){
		cin >> a >> b;
		cd.addEdge(a, b);
	}
	//cout << "Finished Decomposing" << endl;
	//cd.show();
	cd.decompose(1, -1, 1);
	//cout << "Finished Sparse" << endl;
	cd.modify(1);
	while(M--){
		cin >> a >> b;
		if(a == 1){ //Modify
			cd.modify(b);
		} else if(a == 2){ //Query
			cout << cd.query(b) << '\n';
		}
	}
}
