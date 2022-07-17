#include <iostream>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326;

int N, Q, c, a, b, arr[maxN];

struct Seg{
	int seg[maxN << 2], tag[maxN << 2][2];	
	inline void pull(int id){
		seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
	}
	inline void push(int id, int l, int r){
		if(!tag[id][0] && !tag[id][1]) return;
		seg[id] += (r - l) * (tag[id][0] * 2 + (r - l - 1) * tag[id][1]) / 2;
		if(r - l > 1){
			tag[2 * id + 1][1] += tag[id][1];
			tag[2 * id + 2][1] += tag[id][1];
			tag[2 * id + 1][0] += tag[id][0];
			tag[2 * id + 2][0] += tag[id][0] + ((l + r) / 2 - l) * tag[id][1];
		}
		tag[id][0] = tag[id][1] = 0;
	}
	void build(int id = 0, int l = 0, int r = N){
		tag[id][0] = tag[id][1] = 0;
		if(l + 1 == r){
			seg[id] = arr[l];
			return;
		}
		int m = (l + r) / 2;
		build(2 * id + 1, l, m);
		build(2 * id + 2, m, r);
		pull(id);
	}
	void modify(int id, int l, int r, int ql, int qr){
		push(id, l, r);
		if(l >= qr || ql >= r) return;
		if(ql <= l && r <= qr){
			tag[id][0] += l - ql + 1;
			tag[id][1]++;
			push(id, l, r);
			return;
		}
		int m = (l + r) / 2;
		modify(2 * id + 1, l, m, ql, qr);
		modify(2 * id + 2, m, r, ql, qr);
		pull(id);
	}
	int query(int id, int l, int r, int ql, int qr){
		push(id, l, r);
		if(l >= qr || ql >= r) return 0;
		if(ql <= l && r <= qr) return seg[id];
		int m = (l + r) / 2;
		return query(2 * id + 1, l, m, ql, qr) + query(2 * id + 2, m, r, ql, qr);
	}
} seg;

signed main(){
	cin >> N >> Q;
	for(int i = 0; i < N; i++) cin >> arr[i];
	seg.build();
	while(Q--){
		cin >> c >> a >> b;
		if(c == 1){
			seg.modify(0, 0, N, a - 1, b); 
		} else {
			cout << seg.query(0, 0, N, a - 1, b) << endl;	
		}
	}
}
