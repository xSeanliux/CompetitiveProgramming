#pragma gcc optimize ("O3")
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int lim = 200, lim2 = 200, maxN = 4e4 + 326;


int N, Q, arr[maxN], ans[maxN], l, r, k;

class Seg {
private:
    int seg[maxN << 2], M;
	inline void pull(int id){
		seg[id] = max(seg[2 * id + 1], seg[2 * id + 2]);
	}
public:
	void build(int id = 0, int l = 0, int r = N){
		if(l + 1 == r){
			seg[id] = arr[l] % M;
			return;
		}
		int m = (l + r) / 2;
		build(2 * id + 1, l, m);
		build(2 * id + 2, m, r);
		pull(id);
	}
	int query(int id, int l, int r, int ql, int qr){
		if(ql >= r || l >= qr) return -1;
		if(ql <= l && r <= qr) return seg[id];
		int m = (l + r) / 2;
		return max(query(2 * id + 1, l, m, ql, qr), query(2 * id + 2, m, r, ql, qr));
	}
	Seg(int M = maxN): M(M){}
} small[lim];

struct Query{
	int l, r, id, k;
	Query(int l = 0, int r = 0, int id = 0, int k = 0): l(l), r(r), id(id), k(k){}
	const bool operator<(const Query &q) const {
	    if(l / lim2 != q.l / lim2) return l / lim2 < q.l / lim2;
	    if((l / lim2) & 1) return r < q.r;
	    else return r > q.r;
	}
};

vector<Query> que;

multiset<int> st;

int main() {
	ericxiao
	cin >> N >> Q;
	for(int i = 0; i < N; i++) cin >> arr[i];
	for(int i = 1; i < lim; i++){
	    small[i] = Seg(i);
	    small[i].build();
	}
	for(int i = 0; i < Q; i++){
		cin >> l >> r >> k;
		--l;
		if(k < lim){
			ans[i] = small[k].query(0, 0, N, l, r);
		} else que.emplace_back(l, r, i, k);
	}
	sort(que.begin(), que.end());
	int L = 0, R = 1;
	st.insert(arr[0]);
	for(auto q : que){
		while(L > q.l) st.insert(arr[--L]);
		while(R < q.r) st.insert(arr[R++]);
		while(L < q.l) st.erase(st.find(arr[L++]));
		while(R > q.r) st.erase(st.find(arr[--R]));
		int a = -1;
		for(int u = q.k; u < maxN + q.k; u += q.k){
			auto it = st.lower_bound(u);
			if(it == st.begin()){
				continue;
			}
			--it;
 			if(*it >= u - q.k && *it < u) a = max(a, *it - u + q.k);
		}
		ans[q.id] = a;
	}
	for(int i = 0; i < Q; i++) cout << ans[i] << " \n"[i == Q - 1];
} 

