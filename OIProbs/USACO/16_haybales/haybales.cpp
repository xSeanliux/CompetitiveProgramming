#include <iostream>
#include <utility>
#include <fstream>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define cin infile
#define cout outfile
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 326;

int tag[maxN * 4], arr[maxN], N, Q, a, b, c;
char com;
pii seg[maxN * 4];

ifstream infile;
ofstream outfile;

inline void pull(int id){
	seg[id].F = seg[2 * id + 1].F + seg[2 * id + 2].F;
	seg[id].S = min(seg[2 * id + 1].S, seg[2 * id + 2].S);
}

inline void push(int id, int l, int r){
	if(!tag[id]) return;	
	seg[id].F += (r - l) * tag[id];
	seg[id].S += tag[id];
	if(r - l > 1){
		tag[2 * id + 1] += tag[id];
		tag[2 * id + 2] += tag[id];
	}
	tag[id] = 0;
}

void build(int id = 0, int l = 0, int r = N){
	if(l + 1 == r){
		seg[id] = {arr[l], arr[l]};
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void modify(int id, int ql, int qr, int l, int r, int v){
	push(id, l, r);
	if(ql >= r || l >= qr) return;
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

pii query(int id, int ql, int qr, int l, int r){
	push(id, l, r);
	if(ql >= r || l >= qr) return {0, 1e12};
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	pii a = query(2 * id + 1, ql, qr, l, m), b = query(2 * id + 2, ql, qr, m, r);
	return {a.F + b.F, min(a.S, b.S)};
}

signed main(){
	infile.open("haybales.in");
	outfile.open("haybales.out");
	ericxiao;
	cin >> N >> Q;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	build();
	while(Q--){
		cin >> com;
		if(com == 'M'){
			cin >> a >> b;
			--a;
			cout << query(0, a, b, 0, N).S << endl;
		} else if(com == 'P'){
			cin >> a >> b >> c;
			--a;
			modify(0, a, b, 0, N, c);
		} else if(com == 'S'){
			cin >> a >> b;
			--a;
			cout << query(0, a, b, 0, N).F << endl;
		}
	}
	infile.close();
	outfile.close();
}
