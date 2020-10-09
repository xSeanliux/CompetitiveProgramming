#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;

int N, M, sz, x, a[maxN], b[maxN], allval, mst;

struct Edge{
	int u, v, w;
	Edge(int u, int v, int w): u(u), v(v), w(w){}
	bool operator<(const Edge &e) const {
		return w > e.w; 
	}
};

vector<Edge> edges;

struct DSU{
	int arr[maxN];
	void Flat(int x){
		if(x == arr[x]) return;
		Flat(arr[x]);
		arr[x] = arr[arr[x]];
	}
	int Merge(int a, int b){
		Flat(a);
		Flat(b);
		if(arr[a] == arr[b]) return 0;
		arr[arr[a]] = arr[b];
		return 1;
	}
	void init(int N){
		iota(arr, arr + N + 1, 0);	
	}
} dsu;


signed main(){
	cin >> M >> N;
	dsu.init(M + N);
	for(int i = 1; i <= M; i++) cin >> a[i];
	for(int i = 1; i <= N; i++) cin >> b[i];
	for(int i = 1; i <= M; i++){
		cin >> sz;
		for(int j = 0; j < sz; j++){
			cin >> x;
			edges.emplace_back(i, x + M, a[i] + b[x]);
			allval += a[i] + b[x];
		}
	}
	sort(edges.begin(), edges.end());
	for(auto e : edges){
		mst += dsu.Merge(e.u, e.v) * e.w;
	}
	//cout << "mst = " << mst << endl;
	cout << allval - mst << endl;
}
