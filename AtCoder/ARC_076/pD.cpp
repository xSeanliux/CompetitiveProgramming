#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

const int maxN = 1e5 + 326;

int N, dsu[maxN * 2], ans;
vector<int> x, y, xl, yl;

void Flat(int x){
	if(x == dsu[x]) return;
	Flat(dsu[x]);
	dsu[x] = dsu[dsu[x]];
}

bool Merge(int a, int b){
	Flat(a);
	Flat(b);
	if(dsu[a] == dsu[b]) return false;
	dsu[dsu[a]] = dsu[b];
	return true;
}

struct Edge{
	int u, v, w;
	Edge(){}
	Edge(int u, int v, int w): u(u), v(v), w(w){}
	bool operator<(const Edge &e) const {
		return w < e.w;
	}
};

vector<Edge> edges;

int main(){
	cin >> N;
	x.resize(N);
	y.resize(N);
	iota(dsu, dsu + maxN * 2, 0);
	for(int i = 0; i < N; i++){
		cin >> x[i] >> y[i];
		xl.push_back(x[i]);
		yl.push_back(y[i]);
	}
	sort(xl.begin(), xl.end());
	sort(yl.begin(), yl.end());
	int xs = unique(xl.begin(), xl.end()) - xl.begin();
	int ys = unique(yl.begin(), yl.end()) - yl.begin();
	for(int &v : x) v = lower_bound(xl.begin(), xl.begin() + xs, v) - xl.begin();
	for(int &v : y) v = lower_bound(yl.begin(), yl.begin() + ys, v) - yl.begin();
	for(int i = 0; i < N; i++){
		Merge(x[i], y[i] + N);
	}
	for(int i = 1; i < xs; i++){
		edges.emplace_back(i - 1, i, xl[i] - xl[i - 1]); 
	}
	for(int i = 1; i < ys; i++){
		edges.emplace_back(i - 1 + N, i + N, yl[i] - yl[i - 1]);
	}
	sort(edges.begin(), edges.end());
	for(auto &e : edges){
		ans += Merge(e.u, e.v) * e.w;
	}
	cout << ans << endl;
}

