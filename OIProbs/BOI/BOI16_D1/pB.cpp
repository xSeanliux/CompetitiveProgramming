#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <numeric>
#include <deque>
#include <math.h>
#define pii pair<int, int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;
 
 
const int maxN = 2e3 + 326, maxM = 2e5 + 326;
int N, M, W, H, x, y, r;
string rea[4], ans[maxM];
deque<pii> ord[maxN];
 
struct Circ{
	int x, y, r;
	Circ(){}
	Circ(int _x, int _y, int _r): x(_x), y(_y), r(_r){}
} circs[maxN];
 
struct Que{
	int e, r, id;
	Que(int e = 0, int r = 0, int id = 0): e(e), r(r), id(id){}
	bool operator<(const Que &q) const {
		return r < q.r;
	}
} ques[maxM];
 
inline int Sqrt(int x){
	if(!x) return 0;
	int l = 0, r = 2e9, m;
	while(r - l > 1){
		m = (l + r) / 2;
		if(m * m <= x) l = m;
		else r = m;
	}
	return l;
}
 
inline int f(int i, int j){
	int D = (circs[i].x - circs[j].x) * (circs[i].x - circs[j].x) + (circs[i].y - circs[j].y) * (circs[i].y - circs[j].y);
	int res = Sqrt(D), K = res - circs[i].r - circs[j].r;
	return K / 2 + 1;
}
 
struct DSU{
	int dsu[maxN];
	DSU(){
		iota(dsu, dsu + maxN, 0);
	}
	void Flat(int x){
		if(x == dsu[x]) return;
		Flat(dsu[x]);
		dsu[x] = dsu[dsu[x]];
	}
	void Merge(int a, int b){
		Flat(a);
		Flat(b);
		if(dsu[a] == dsu[b]){
			if(a >= N || b >= N){
				cerr << "already: " << b << " " << a << endl;
			}
			return;
		}
		dsu[dsu[a]] = dsu[b];
	}
	inline bool same(int a, int b){
		Flat(a);
		Flat(b);
		return dsu[a] == dsu[b];
	}
} dsu;
 
inline void update(){
	rea[0] = "1";
	rea[1] = "2";
	rea[2] = "3";
	rea[3] = "4";
	if(!dsu.same(N + 1, N + 2) && !dsu.same(N + 2, N + 3) && !dsu.same(N, N + 2)){
		rea[0] += "2";
		rea[1] += "1";
	}
	if(!dsu.same(N + 1, N + 2) && !dsu.same(N, N + 3) && !dsu.same(N, N + 2) && !dsu.same(N + 1, N + 3)){
		rea[0] += "3";
		rea[2] += "1";
	}
	if(!dsu.same(N + 1, N + 2) && !dsu.same(N, N + 1) && !dsu.same(N + 1, N + 3)){
		rea[0] += "4";
		rea[3] += "1";
	}
	if(!dsu.same(N + 2, N + 3) && !dsu.same(N, N + 3) && !dsu.same(N + 1, N + 3)){
		rea[1] += "3";
		rea[2] += "2";
	}
	if(!dsu.same(N + 2, N + 3) && !dsu.same(N, N + 1) && !dsu.same(N, N + 2) && !dsu.same(N + 1, N + 3)){
		rea[1] += "4";
		rea[3] += "2";
	}
	if(!dsu.same(N, N + 3) && !dsu.same(N, N + 1) && !dsu.same(N, N + 2)){
		rea[2] += "4";
		rea[3] += "3";
	}
	for(int i = 0; i < 4; i++) sort(rea[i].begin(), rea[i].end());
}
 
signed main(){
	ericxiao
	dsu = DSU();
	cin >> N >> M >> W >> H;
	for(int i = 0; i < N; i++){
		cin >> x >> y >> r;
		circs[i] = Circ(x, y, r);
	}
	for(int i = 0; i < M; i++){
		cin >> r >> x;	
		--x;
		ques[i] = Que(x, r, i);
	}
	sort(ques, ques + M);
	
	for(int i = 0; i < N; i++){
		ord[i].emplace_back((H - circs[i].y - circs[i].r) / 2 + 1, N);
		ord[i].emplace_back((circs[i].x - circs[i].r) / 2 + 1, N + 1);
		ord[i].emplace_back((circs[i].y - circs[i].r) / 2 + 1, N + 2);
		ord[i].emplace_back((W - circs[i].x - circs[i].r) / 2 + 1, N + 3);
		for(int j = 0; j < N; j++){
			if(i == j) continue;
			ord[i].emplace_back((f(i, j)), j);
			//cerr << "for i = " << i << ", j = " << j << ": " << f(i, j) << endl;
		}
		sort(ord[i].begin(), ord[i].end());
	}
	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			while(ord[j].size() && ord[j].front().F <= ques[i].r){
				dsu.Merge(j, ord[j].front().S);
				ord[j].pop_front();
			}
		}
		update();
		ans[ques[i].id] = rea[ques[i].e];
	}
	for(int i = 0; i < M; i++) cout << ans[i] << "\n";
}
