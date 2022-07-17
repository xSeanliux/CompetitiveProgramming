#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 326, M = 1e9 + 7, INV2 = 5e8 + 4;

int N, Q, m[maxN], v[maxN];

inline int madd(int a, int b){
   return (a + b >= M ? a + b - M : a + b); 
}

inline int add(int a = 0, int b = 0, int c = 0, int d = 0, int e = 0, int f = 0){
    return madd(madd(a, madd(b, c)), madd(d, madd(e, f)));
}

inline int mult(int a = 1, int b = 1, int c = 1, int d = 1){
    return (a * b % M) * (c * d % M) % M;
}

struct Node{
	int m, v, mv, v2, mv2, tm, tv;
	Node *lef, *rig;
	Node(): tm(0), tv(0), lef(NULL), rig(NULL){}
	Node(int m, int v): m(m), v(v), mv(mult(m, v)), v2(mult(v, v)), mv2(mult(m, v, v)), tm(0), tv(0), lef(NULL), rig(NULL){}
	inline void pull(){
		m = add(lef->m, rig->m);
		v = add(lef->v, rig->v);
        v2 = add(lef->v2, rig->v2);
		mv = add(lef->mv, rig->mv);
		mv2 = add(lef->mv2, rig->mv2);
	}
	inline void push(int l, int r){
		//(m + dm)(v^2 + 2vdv + dv^2)
		//= mv^2 + 2v * dv * m + m(dv)^2 + dm * v^2 + 2 * v * dm * dv + dv^2 * dm
		mv2 = add(mv2, mult(2, tv, mv), mult(m, tv, tv), mult(tm, v2), mult(2, v, tm, tv), mult(r - l, tv, tv, tm)); 
		v2 = add(v2, mult(2, tv, v), mult((r - l), tv, tv));
		mv = add(mv, mult(tv, m), mult(tm, v), mult((r - l), tm, tv));
		v = add(v, mult((r - l), tv));
		m = add(m, mult((r - l), tm));
		if(r - l > 1){
            lef->tm = add(lef->tm, tm);
            lef->tv = add(lef->tv, tv);
            rig->tm = add(rig->tm, tm);
            rig->tv = add(rig->tv, tv);
		}
		tm = tv = 0;
	}
} *root = new Node();

void build(Node *&cur = root, int l = 0, int r = N){
	if(r - l == 1){
		cur = new Node(m[l], v[l]);
		return;
	}
	cur->lef = new Node();
	cur->rig = new Node();
	int mid = (l + r) / 2;
	build(cur->lef, l, mid);
	build(cur->rig, mid, r);
	cur->pull();
}

int query(Node *& cur, int l, int r, int ql, int qr){
    cur->push(l, r);
    if(l >= qr || r <= ql) return 0;
	if(ql <= l && r <= qr) return mult(cur->mv2, INV2);
	int mid = (l + r) / 2;
	return add(query(cur->lef, l, mid, ql, qr), query(cur->rig, mid, r, ql, qr));
}

void modify(Node *& cur, int l, int r, int ql, int qr, int dm, int dv){
    cur->push(l, r);
    if(l >= qr || r <= ql) return;
	if(ql <= l && r <= qr){
		cur->tm = add(cur->tm, dm);
		cur->tv = add(cur->tv, dv);
		cur->push(l, r);
        return;
	}
    int mid = (l + r) / 2;
    modify(cur->lef, l, mid, ql, qr, dm, dv);
    modify(cur->rig, mid, r, ql, qr, dm, dv);
    cur->pull();
}

signed main() {
	ericxiao
    cin >> N >> Q; 
    for(int i = 0; i < N; i++) cin >> m[i];
    for(int i = 0; i < N; i++) cin >> v[i];
    build();
    int c, l, r, x;
    while(Q--){
        cin >> c >> l >> r;
        l--;
        if(c == 1){
            cin >> x;
            modify(root, 0, N, l, r, x, 0);
        } else if(c == 2){
            cin >> x;
            modify(root, 0, N, l, r, 0, x);
        } else {
            cout << query(root, 0, N, l, r) << endl;
        }
    }
}
