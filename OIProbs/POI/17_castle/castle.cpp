#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <queue>
#include <tuple>
#include <set>
#include <cassert>
#define pii pair<int,int>
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 326;
int l[maxN], r[maxN], d[maxN], u[maxN], N, M, W, H, dist[maxN], xsz, ysz, block[maxN], x[maxN], y[maxN];
bool marked[maxN];

vector<int> bottomSide[maxN], topSide[maxN], leftSide[maxN], rightSide[maxN];
vector<int> xlis, ylis;
vector<int> adj[maxN];
vector<pii> xvals[maxN], toDel[maxN], toAdd[maxN];

inline void addEdge(int u, int v){
	//cout << "Adding edge between " << u << " and " << v << endl;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(){
	ericxiao
	cin >> W >> H >> N >> M;
	cin >> x[0] >> y[0] >> x[1] >> y[1];
	for(int i = 0; i < N; i++){
		cin >> l[i] >> u[i] >> r[i] >> d[i];
		xlis.emplace_back(l[i]);
		xlis.emplace_back(r[i]);
		ylis.emplace_back(u[i]);
		ylis.emplace_back(d[i]);
		if(l[i] > r[i]) swap(l[i], r[i]);
		if(d[i] > u[i]) swap(d[i], u[i]);
	}
	for(int i = 2; i < M + 2; i++){
		cin >> x[i] >> y[i];
	}
	sort(ALL(xlis));
	sort(ALL(ylis));
	xsz = unique(ALL(xlis)) - xlis.begin();
	ysz = unique(ALL(ylis)) - ylis.begin();
	for(int i = 0; i < M + 2; i++){
		x[i] = lower_bound(xlis.begin(), xlis.begin() + xsz, x[i]) - xlis.begin();
		y[i] = lower_bound(ylis.begin(), ylis.begin() + ysz, y[i]) - ylis.begin();
		xvals[y[i]].emplace_back(x[i], i);
	}
	for(int i = 0; i < N; i++){
		l[i] = lower_bound(xlis.begin(), xlis.begin() + xsz, l[i]) - xlis.begin();
		r[i] = lower_bound(xlis.begin(), xlis.begin() + xsz, r[i]) - xlis.begin();
		d[i] = lower_bound(ylis.begin(), ylis.begin() + ysz, d[i]) - ylis.begin();
		u[i] = lower_bound(ylis.begin(), ylis.begin() + ysz, u[i]) - ylis.begin();
		toAdd[d[i]].emplace_back(r[i], i);
		toDel[u[i]].emplace_back(r[i], i);
		bottomSide[u[i]].push_back(i);
		topSide[d[i]].push_back(i);
		leftSide[r[i]].push_back(i);
		rightSide[l[i]].push_back(i);
	}
	set<pii> st;
	for(int i = 0; i < ysz; i++){
		for(auto [X, id] : xvals[i]){
			block[id] = st.lower_bound({X, -1})->S;
			//cout << "block of " << id << " is " << block[id] << endl;
		}
		for(auto p : toAdd[i]){
			st.insert(p);
			//cout << "y = " << i << ", adding " << p.F << ", " << p.S << endl;
		}

		for(auto p : toDel[i]){
			st.erase(p);
			//cout << "y = " << i << ", deleting " << p.F << ", " << p.S << endl;
		}

	}
	for(int i = 2; i < M + 2; i++) marked[block[i]] = true;
	for(int i = 0; i < xsz; i++){
		sort(ALL(leftSide[i]), [&](int &a, int &b){
			return u[a] < u[b];
		});
		sort(ALL(rightSide[i]), [&](int &a, int &b){
			return u[a] < u[b];
		});
	}
	for(int i = 0; i < ysz; i++){
		sort(ALL(topSide[i]), [&](int &a, int &b){
			return r[a] < r[b];
		});
		sort(ALL(bottomSide[i]), [&](int &a, int &b){
			return r[a] < r[b];
		});
	}
	int L, R;
	for(int i = 1; i < xsz - 1; i++){
		if(!leftSide[i].size() || !rightSide[i].size()) continue;
		//cout << "i = " << i << endl;
		//cout << "|L|: " << leftSide[i].size() << ", |R|: " << rightSide[i].size() << endl;
		L = 0, R = 0;
		addEdge(leftSide[i][0], rightSide[i][0]);
		while(L < leftSide[i].size() - 1 || R < rightSide[i].size() - 1){
			//cout << "L = " << L << ", R = " << R << endl;
			if(R == rightSide[i].size() - 1 || (L < leftSide[i].size() - 1 && u[leftSide[i][L]] <= u[rightSide[i][R]])){
				L++;
				if(u[rightSide[i][R]] > d[leftSide[i][L]]){
					addEdge(rightSide[i][R], leftSide[i][L]);
				}
			} else {
				R++;
				if(u[leftSide[i][L]] > d[rightSide[i][R]]){
					addEdge(rightSide[i][R], leftSide[i][L]);
				}
			}
		}
	}
	for(int i = 1; i < ysz - 1; i++){
		if(!topSide[i].size() || !bottomSide[i].size()) continue;
		L = 0, R = 0;
		addEdge(topSide[i][0], bottomSide[i][0]);
		while(L < topSide[i].size() - 1 || R < bottomSide[i].size() - 1){
			if(R == bottomSide[i].size() - 1 || r[topSide[i][L]] <= r[bottomSide[i][R]]){
				L++;
				if(r[bottomSide[i][R]] > l[topSide[i][L]]){
					addEdge(bottomSide[i][R], topSide[i][L]);
				}
			} else {
				R++;
				if(r[topSide[i][L]] > l[bottomSide[i][R]]){
					addEdge(bottomSide[i][R], topSide[i][L]);
				}
			}
		}
	}
	fill(dist, dist + N + 1, maxN);
	dist[block[0]] = 1;
	queue<int> que;
	que.push(block[0]);
	assert(!marked[block[1]]);
	while(que.size()){
		int t = que.front();
		//cout << "t = " << t << endl;
		que.pop();
		for(int x : adj[t]){
			if(marked[x] || dist[x] < maxN) continue;
			dist[x] = dist[t] + 1;
			que.push(x);
		}
	}
	cout << dist[block[1]] << endl;
}
