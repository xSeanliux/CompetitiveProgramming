#include <iostream>
#define m ((l+r)/2)
#define int long long int
using namespace std;

const int maxN = (1LL << 18);
int tag, seg[maxN * 4], N, Q, arr[maxN], com, a, b; 

void pull(int id){
	seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

void build(int id = 0, int l = 0, int r = (1 << N)){
	if(l + 1 == r){
		seg[id] = arr[l];
		return;
	}
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void modify(int id, int l, int r, int pos, int val){
	if(l + 1 == r){
		seg[id] = val;
		return;
	}
	if(tag & (r - l)){
		pos = r - (pos - l + 1);
	}
	if(pos < m) modify(2 * id + 1, l, m, pos, val);
	else modify(2 * id + 2, m, r, pos, val);
	pull(id);
}

int query(int id, int l, int r, int ql, int qr){
	if(ql <= l && r <= qr) return seg[id];
	if(ql >= r || l >= qr) return 0;
	if(tag & (r - l)){
		//cout << "len = " << r - l << ", ql = " << ql << ", qr = " << qr << " rev ";
		qr--;
		ql = r - (ql - l + 1);
		qr = r - (qr - l + 1);
		if(ql > qr) swap(ql, qr);
		qr++;
		//cout << "now: ql = " << ql << ", qr = " << qr << endl;
	}
	return query(2 * id + 1, l, m, ql, qr) + query(2 * id + 2, m, r, ql, qr);
}

signed main(){
	cin >> N >> Q;
	for(int i = 0; i < (1 << N); i++) cin >> arr[i];
	build();
	while(Q--){
		cin >> com;
		if(com == 1){
			cin >> a >> b;
			modify(0, 0, (1 << N), a - 1, b);
		} else if(com == 2){
			cin >> a;
			tag ^= (1 << a);
		} else if(com == 3){
			cin >> a;
			tag ^= (1LL << a) + (1LL << (a + 1));
		} else {
			cin >> a >> b;
			cout << query(0, 0, (1 << N), a - 1, b) << endl;
		}
	}
}
