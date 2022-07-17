#include <iostream>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int MAXC = 1e6 + 326, INF = 1e17 + 326;

struct node{
	int mx, mxcnt, smx, lazy, lazyAdd, len, sum;
	node(int k = 0): sum(k), mx(k), mxcnt(1), smx(-INF), lazy(-1), lazyAdd(0), len(1)
	{}
	node operator+(const node &a) const {
		node rt;
		rt.sum = sum + a.sum;
		rt.mx = max(mx, a.mx);
		rt.len = len + a.len;
		if(mx == a.mx){
			rt.mxcnt = mxcnt + a.mxcnt;
			rt.smx = max(smx, a.smx);
		} else if(mx > a.mx){
			rt.mxcnt = mxcnt;
			rt.smx = max(smx, a.mx);
		} else {
			rt.mxcnt = a.mxcnt;
			rt.smx = max(mx, a.smx);
		}
		rt.lazy = -1;
		rt.lazyAdd = 0;
		return rt;
	}
} seg[MAXC << 2];

int a[MAXC];

void give_tag(int rt, int A, int M){
	seg[rt].lazyAdd += A;
	seg[rt].sum += seg[rt].len * A;
	seg[rt].mx += A;
	seg[rt].smx += A;	
}

void give_tag(int rt, int t){ //rt is id
	if(t >= seg[rt].mx) return;
	seg[rt].lazy = t;
	seg[rt].sum -= seg[rt].mxcnt * (seg[rt].mx - t);
	seg[rt].mx = t;
}

void give_add_tag(int rt, int t){
	seg[rt].lazyAdd += t;
	seg[rt].sum += seg[rt].len * t;
	seg[rt].mx += t;
	seg[rt].smx += t;
}

void tag_down(int rt){
	give_add_tag(rt << 1, seg[rt].lazyAdd);
	if(~seg[rt].lazy) give_tag(rt << 1, seg[rt].lazy);
	give_add_tag(rt << 1 | 1, seg[rt].lazyAdd);
	if(~seg[rt].lazy) give_tag(rt << 1 | 1, seg[rt].lazy);
	seg[rt].lazy = -1;
	seg[rt].lazyAdd = 0;
}

void build(int l, int r, int rt){
	if(l == r) return seg[rt] = node(a[l]), void();
	int mid = (l + r) >> 1;
	build(l, mid, rt << 1);
	build(mid + 1, r, rt << 1 | 1);
	seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void modifymin(int L, int R, int l, int r, int rt, int t){
	if(L <= l && r <= R && t > seg[rt].smx)
		return give_tag(rt, t);
	if(l != r) tag_down(rt);
	int mid = (l + r) >> 1;
	if(L <= mid) modifymin(L, R, l, mid, rt << 1, t);
	if(R > mid) modifymin(L, R, mid + 1, r, rt << 1 | 1, t);
	seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

void modifyadd(int L, int R, int l, int r, int rt, int t){
	if(L <= l && r <= R)
		return give_add_tag(rt, t);
	if(l != r) tag_down(rt);
	int mid = (l + r) >> 1;
	if(L <= mid) modifyadd(L, R, l, mid, rt << 1, t);
	if(R > mid) modifyadd(L, R, mid + 1, r, rt << 1 | 1, t);
	seg[rt] = seg[rt << 1] + seg[rt << 1 | 1];
}

node query(int L, int R, int l, int r, int rt){
	if(L <= l && r <= R) return seg[rt];
	if(l != r) tag_down(rt);
	int mid = (l + r) >> 1;
	if(R <= mid) return query(L, R, l, mid, rt << 1); //not the same as line 62?
	if(L > mid) return query(L, R, mid + 1, r, rt << 1 | 1); //not the same as line 62?
	return query(L, R, l, mid, rt << 1) + query(L, R, mid + 1, r, rt << 1 | 1);
}

signed main(){
	//ericxiao;
	int N, Q;
	cin >> N >> Q;
	for(int i = 1; i <= N; i++) cin >> a[i];
	build(1, N, 1);
	while(Q--){
		int t, l, r, x;
		cin >> t >> l >> r;
		if(t == 1){ //min= x
			cin >> x;	
			modifymin(l, r, 1, N, 1, x);
		} else if(t == 2){// += x
			cin >> x;
			modifyadd(l, r, 1, N, 1, x);
		} else if(t == 3){ //sum
			cout << query(l, r, 1, N, 1).sum << endl;
		} else { //max
			cout << query(l, r, 1, N, 1).mx << endl;
		}
	}
}

