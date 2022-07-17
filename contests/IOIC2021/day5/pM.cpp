#pragma gcc optimize("Ofast")
#include <iostream>
#include <math.h>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 326, INF = 1e17;

int N, arr[maxN]; 

inline char readchar(){
	static const size_t bufsize = 65536;
	static char buf[bufsize];
	static char *p = buf, *end = buf;
	if(p == end) end = buf + fread(buf, 1, bufsize, stdin), p = buf;
	return *p++;
}

inline void const Read(int &p){
	p = 0;
	int tmp = 0;
	char c = readchar();
	tmp = !(c^'-');
	while(c < '0' || c > '9'){
		c = readchar();
	}
	while(c >= '0' && c <= '9') p = (p << 3) + (p << 1) + (c ^ 48), c = readchar();
	p = tmp ? -p : p;
}

struct Node{
	int minv, maxv, sum, tag;
	Node(){
		minv = INF;
		maxv = -INF;
		sum = tag = 0;
	}
	Node(int x): minv(x), maxv(x), sum(x), tag(0){}
	const Node operator+(const Node &n) const {
		Node ret;
		ret.minv = min(minv, n.minv);
		ret.maxv = max(maxv, n.maxv);
		ret.sum = sum + n.sum;
		return ret;
	}
} seg[maxN << 2];

inline int f(int p, int y){ //hopefully no floating point errors
	//cout << "f_" << p << "(" << y << ") = ";
	if(y >= p){
		//cout << p + (int)sqrt(y - p + 0.001) << endl; 
		return p + (int)sqrt(y - p + 0.1);
	}
	//cout << p - (int)(sqrt(p - y) + 0.001) << endl;
	return p - (int)(sqrt(p - y) + 0.1);
}


inline void pull(int id){
	seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
}

inline void push(int id, int l, int r){
	seg[id].minv += seg[id].tag;
	seg[id].maxv += seg[id].tag;
	seg[id].sum += (r - l) * seg[id].tag;
	if(r - l > 1){
		seg[2 * id + 1].tag += seg[id].tag;
		seg[2 * id + 2].tag += seg[id].tag;
	}
	seg[id].tag = 0;
}

void build(int id = 0, int l = 0, int r = N){
	if(l + 1 == r){
		seg[id] = Node(arr[l]);
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void shift(int id, int l, int r, int ql, int qr, int v){
	push(id, l, r);
	if(ql <= l && r <= qr){
		seg[id].tag += v;
		push(id, l, r);
		return;
	}
	if(l >= qr || ql >= r) return;
	int m = (l + r) / 2;
	shift(2 * id + 1, l, m, ql, qr, v);
	shift(2 * id + 2, m, r, ql, qr, v);
	pull(id);
}

void change(int id, int l, int r, int v){
	push(id, l, r);
	if(seg[id].maxv == seg[id].minv){
		seg[id].tag += v - seg[id].maxv;	
		push(id, l, r);
		return;
	}
	if(l + 1 == r){
		seg[id] = Node(v);
		return;
	}
	int m = (l + r) / 2;
	change(2 * id + 1, l, m, v);
	change(2 * id + 2, m, r, v);
	pull(id);
}

void disp(int id, int l, int r){
	push(id, l, r);
	if(l + 1 == r){
		cout << seg[id].maxv << " ";
		return;
	}
	int m = (l + r) / 2;
	disp(2 * id + 1, l, m);
	disp(2 * id + 2, m, r);
}

void blackhole(int id, int l, int r, int ql, int qr, int p){
	//cout << "blackhole(" << id << ", " << l << ", " << r << ", " << ql << ", " << qr << ", " << p << ")\n";
	push(id, l, r);
	if(l >= qr || ql >= r) return;
	if(ql <= l && r <= qr){
		if(seg[id].maxv - seg[id].minv == 0){
			seg[id].tag += f(p, seg[id].maxv) - seg[id].maxv;
			push(id, l, r);
			return;
		} else if(seg[id].maxv - seg[id].minv == 1){
			int nmax = f(p, seg[id].maxv), nmin = f(p, seg[id].minv);
			if(nmax == nmin){ //baoli
				change(id, l, r, nmax);
			} else {
				seg[id].tag += f(p, seg[id].maxv) - seg[id].maxv;
				push(id, l, r);
			}
			return;
		}
	}
	int m = (l + r) / 2;
	blackhole(2 * id + 1, l, m, ql, qr, p);
	blackhole(2 * id + 2, m, r, ql, qr, p);
	pull(id);
}

Node query(int id, int l, int r, int ql, int qr){
	push(id, l, r);
	if(l >= qr || ql >= r) return Node();
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	return query(2 * id + 1, l, m, ql, qr) + query(2 * id + 2, m, r, ql, qr);
}

int Q, com, l, r, x, k, p;

signed main(){
	//ericxiao;
	Read(N);
	Read(Q);
	for(int i = 0; i < N; i++) cin >> arr[i];
	build();
	while(Q--){
		Read(com);
		Read(l);
		Read(r);
		l--;
		if(com == 1){
			Read(p);
			blackhole(0, 0, N, l, r, p);
			//disp(0, 0, N);
		} else if(com == 2){
			Read(x);
			shift(0, 0, N, l, r, x);
			//disp(0, 0, N);
		} else {
			Node res = query(0, 0, N, l, r); 
			if(com == 3) cout << res.sum << '\n';
			else if(com == 4) cout << res.maxv << '\n';
			else cout << res.minv << '\n';
		}
	}
}

