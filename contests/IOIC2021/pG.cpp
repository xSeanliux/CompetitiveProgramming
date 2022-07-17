#include <iostream>
#include <utility>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 326;
int N, M, l, r, a[maxN], ans[maxN];

int seg[maxN << 2];
vector<pii> queries[maxN];

void build(int id = 0, int l = 0, int r = maxN){
	seg[id] = -maxN;
	if(l + 1 == r){
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
}

void modify(int id, int l, int r, int p, int v){
	//cout << "modifying " << id << ", " << l << ", " << r << ", " << p << ", " << v << endl;
	if(l + 1 == r){
		seg[id] = v;
		return;
	}
	int m = (l + r) / 2;
	if(p < m) modify(2 * id + 1, l, m, p, v);
	else modify(2 * id + 2, m, r, p, v);
	seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
}

int query(int id, int l, int r, int v){ //returns first value smaller than v
	//cout << "query(" << id << ", " << l << ", " << r << ", " << v << endl;
	if(l + 1 == r) return l;
	int m = (l + r) / 2;
	//cout << "leftside: " << seg[2 * id + 1] << endl;
	if(seg[2 * id + 1] < v) return query(2 * id + 1, l, m, v);
	return query(2 * id + 2, m, r, v);
}

void disp(int id = 0, int l = 0, int r = maxN){
	if(r < 16){
		//cout << "id = " << id << ", l = " << l << ", r = " << r << ", val = " << seg[id] << endl;
	}
	if(l + 1 == r){
		if(r < 10) cout << seg[id] << " ";	
		return;
	}
	int m = (l + r) / 2;
	disp(2 * id + 1, l, m);
	disp(2 * id + 2, m, r);
}


int main(){
	ericxiao;
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> a[i];
	build();
	for(int i = 0; i < M; i++){
		cin >> l >> r;
		--l, --r;
		queries[r].emplace_back(l, i);
	}
	for(int r = 0; r < N; r++){
		modify(0, 0, maxN, a[r], r);
		//cout << "r = " << r << endl;
		//disp();
		//cout << endl;
		for(auto [l, id] : queries[r]){
			//cout << "querying l = " << l << endl;
			ans[id] = query(0, 0, maxN, l);
			//cout << "ans = " << query(0, 0, maxN, l) << endl;
		}
	}
	for(int i = 0; i < M; i++) cout << ans[i] << '\n';
}
