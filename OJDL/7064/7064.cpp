#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <utility>
#define int long long int
using namespace std;

const int maxN = 1e5 + 10;

int N, K, nxtbig[maxN], rightmost[maxN], queryAns[maxN], ans;
stack<int> stk;
vector<int> vec, lis;

struct Query{
	int id, l, lim; //person id asks from l, who is the first with less than lim
	Query(int i, int l, int L): id(i), l(l), lim(L){}
	const bool operator<(const Query &q) const {
		return l > q.l;
	}
};

vector<Query> queries;

struct LeafSeg{
	int seg[maxN << 2];
	void pull(int id){
		seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
	}
	void modify(int id, int l, int r, int pos){
		if(l + 1 == r){
			seg[id] = 1;
			return;
		}
		int m = (l + r) / 2;
		if(pos < m)
			modify(2 * id + 1, l, m, pos);
		else 
			modify(2 * id + 2, m, r, pos);
		pull(id);
	}
	int query(int id, int l, int r, int k){
		if(l + 1 == r) return l;
		int m = (l + r) / 2;
		if(seg[2 * id + 1] >= k) return query(2 * id + 1, l, m, k);
		return query(2 * id + 2, m, r, k - seg[2 * id + 1]);
	}
	int getItem(int id, int l, int r, int pos){
		if(l + 1 == r) return seg[id];
		int m = (l + r) / 2;
		if(pos < m) return getItem(2 * id + 1, l, m, pos);
		return getItem(2 * id + 2, m, r, pos);
	}
	void disp(){
		for(int i = 0; i < N + 1; i++) cout << getItem(0, 0, N + 1, i) << " ";
		cout << endl;
	}
} leafseg;

struct PlaceSeg{
	int seg[maxN << 2];
	PlaceSeg(){
		fill(seg, seg + maxN * 4, maxN);
	}
	void pull(int id){
		seg[id] = min(seg[2 * id + 1], seg[2 * id + 2]);
	}
	void modify(int id, int l, int r, int pos, int v){
		if(l + 1 == r){
			seg[id] = v;
			return;
		}
		int m = (l + r) / 2;
		if(pos < m){
			modify(2 * id + 1, l, m, pos, v);
		} else {
			modify(2 * id + 2, m, r, pos, v);
		}
		pull(id);
	}
	int query(int id, int ql, int qr, int l, int r){
		if(l >= qr || ql >= r) return N;
		if(ql <= l && r <= qr) return seg[id];
		int m = (l + r) / 2;
		return min(query(2 * id + 1, ql, qr, l, m), query(2 * id + 2, ql, qr, m, r));
	}
} placeseg;

signed main(){
	placeseg = PlaceSeg();
	cin >> N >> K;	
	vec.resize(N + 1);
	lis.resize(N + 1);
	for(int i = 0; i < N; i++){
		cin >> vec[i];
		lis[i] = vec[i];
	}
	sort(lis.begin(), lis.end());
	int sz = unique(lis.begin(), lis.end()) - lis.begin();
	for(int &x : vec) x = lower_bound(lis.begin(), lis.begin() + sz, x) - lis.begin();
	vec[N] = N + 1;
	stk.push(N);
	for(int i = N - 1; i >= 0; i--){
		while(vec[stk.top()] < vec[i]) stk.pop();	
		nxtbig[i] = stk.top();
		stk.push(i);
		queries.emplace_back(i, nxtbig[i], vec[i]);  
	}
	sort(queries.begin(), queries.end());
	for(Query q : queries){
		cout << "Person " << q.id << " asks " << q.l << " with lim " << q.lim << endl;
	}
	int qcnt = 0;
	for(int i = N; i >= 0; i--){
		while(qcnt < queries.size() && queries[qcnt].l == i){
			queryAns[queries[qcnt].id] = placeseg.query(0, 0, queries[qcnt].lim, 0, N);
			cout << "queryAns[" << queries[qcnt].id << "] = " << queryAns[queries[qcnt].id] << endl;
			qcnt++;	
		}
		placeseg.modify(0, 0, N, vec[i], i);
	}
	for(int i = 0; i < N; i++){
		cout << queryAns[i] << endl;	
	}
	rightmost[N - 1] = N - 1;	
	ans = (K == 1);
	for(int i = N - 2; i >= 0; i--){
		cout << "i = " << i << endl;
		rightmost[i] = min(rightmost[i + 1], nxtbig[i] - 1);
		cout << "First step: rm[" << i << "] = " << rightmost[i] << endl;
		if(rightmost[i] < N - 1 && rightmost[i] == nxtbig[i] - 1){
			rightmost[i] = min(rightmost[nxtbig[i]], queryAns[i] - 1);
		}
		cout << "Rightmost[" << i << "] = " << rightmost[i] << endl;
		cout << "Que " << K << " = " << leafseg.query(0, 0, N, K) << endl;
		cout << "Que " << K - 1 << " = " << leafseg.query(0, 0, N, K - 1) << endl;
		ans += max(0LL, leafseg.query(0, 0, N, K) - leafseg.query(0, 0, N, K - 1)); 
		if(nxtbig[i] > i + 1 && nxtbig[i] != N) leafseg.modify(0, 0, N + 1, nxtbig[i]);
		cout << "Modifying " << nxtbig[i] << endl;
		leafseg.disp();
	}
	cout << ans << endl;
}
