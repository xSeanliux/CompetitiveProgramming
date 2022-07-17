#include <iostream>
#include <utility>
#include <stack>
#include <algorithm>
#include <fstream>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define cin infile
#define cout outfile
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 326, MOD = 1e9 + 7;

pii points[maxN];
int N, u[maxN], d[maxN];

ifstream infile;
ofstream outfile;

inline void IO(){
	infile.open("sprinklers.in");
	outfile.open("sprinklers.out");
}

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

inline int sub(int a, int b){
	return (a >= b ? a - b : a - b + MOD);
}

const pii operator+(const pii &a, const pii &b) {
	return {add(a.F, b.F), add(a.S, b.S)};
}

struct Seg{
	pii seg[maxN << 2];
	int tag[maxN << 2];
	Seg(){
		fill(seg, seg + maxN * 4, pii{0, 0});
		fill(tag, tag + maxN * 4, 0);
	}
	inline void push(int id, int l, int r){
		if(!tag[id]) return;
		seg[id].F = add(seg[id].F, ((l + r - 1) * (r - l) / 2 % MOD) * tag[id] % MOD);
		seg[id].S = add(seg[id].S, tag[id] * (r - l));
		if(r - l > 1){
			tag[2 * id + 1] = add(tag[2 * id + 1], tag[id]);
			tag[2 * id + 2] = add(tag[2 * id + 2], tag[id]);
		}
		tag[id] = 0;
		return;
	}
	inline void pull(int id){
		seg[id] = seg[2 * id + 1] + seg[2 * id + 2];
	}
	pii query(int id, int ql, int qr, int l, int r){
		push(id, l, r);
		if(l >= qr || ql >= r) return {0, 0};
		if(ql <= l && r <= qr) return seg[id];
		int m = (l + r) / 2;
		return query(2 * id + 1, ql, qr, l, m) + query(2 * id + 2, ql, qr, m, r);
	}
	void modify(int id, int ql, int qr, int l, int r, int v){
		push(id, l, r);
		if(l >= qr || ql >= r) return;
		if(ql <= l && r <= qr){
			tag[id] += v;
			push(id, l, r);
			return;
		}
		int m = (l + r) / 2;
		modify(2 * id + 1, ql, qr, l, m, v);
		modify(2 * id + 2, ql, qr, m, r, v);
		pull(id);
	}
} seg;

inline void getUD(){
	d[0] = points[0].S;
	for(int i = 1; i < N; i++) d[i] = min(d[i - 1], points[i].S);
	u[N - 1] = points[N - 1].S;
	for(int i = N - 2; i >= 0; i--) u[i] = max(u[i + 1], points[i].S);
}

signed main(){
	ericxiao
	IO();
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> points[i].F >> points[i].S;
	}
	sort(points, points + N);
	getUD();	
	int ans = 0;
	for(int i = 0; i <= N; i++){
		auto [sum, cnt] = seg.query(0, d[i], u[i] + 1, 0, N + 1);
		int _ans = sub(cnt * (u[i]) % MOD, sum);
		ans = add(ans, _ans);	
		seg.modify(0, d[i], u[i] + 1, 0, N + 1, 1);
	}
	cout << ans << endl;
}
