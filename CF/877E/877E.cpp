#include <iostream>
#include <string.h>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define end; '\n'
using namespace std;

const int maxN = 2e5 + 326;

int N, Q, val[maxN], id[maxN], tag[4 * maxN], seg[4 * maxN][2], l[maxN], r[maxN], p, cnt, x, ord[maxN];
vector<int> chi[maxN];
string com;

void dfs(int u = 1){
	ord[cnt] = u;
	id[u] = l[u] = cnt++;
	for(int v : chi[u]){
		dfs(v);
	}
	r[u] = cnt;
}

void pull(int id){
	seg[id][0] = seg[2 * id + 1][0] + seg[2 * id + 2][0];
	seg[id][1] = seg[2 * id + 1][1] + seg[2 * id + 2][1];
}

void push(int id, int l, int r){
	if(!tag[id]) return;
	swap(seg[id][0], seg[id][1]);
	if(r - l > 1){
		tag[2 * id + 1] ^= 1;
		tag[2 * id + 2] ^= 1;
	}
	tag[id] = 0;
}

void build(int id = 0, int l = 0, int r = N + 1){
	if(l + 1 == r){
		seg[id][val[ord[l]]] = 1;	
		return;
	}
	int m = (l + r) / 2;
	build(2 * id + 1, l, m);
	build(2 * id + 2, m, r);
	pull(id);
}

void modify(int id, int ql, int qr, int l, int r){
	//cout << "modifying " << id << ", " << ql << ", " << qr << ", " << l << ", " << r << endl;
	push(id, l, r);
	if(ql <= l && r <= qr){
		tag[id] ^= 1;	
		push(id, l, r);
		return;
	}
	if(ql >= r || l >= qr) return;
	int m = (l + r) / 2;
	modify(2 * id + 1, ql, qr, l, m);
	modify(2 * id + 2, ql, qr, m, r);
	pull(id);
}

int query(int id, int ql, int qr, int l, int r){
	push(id, l, r);
	if(ql <= l && r <= qr){
		return seg[id][1];
	}
	if(ql >= r || l >= qr) return 0;
	int m = (l + r) / 2;
	return query(2 * id + 1, ql, qr, l, m) + query(2 * id + 2, ql, qr, m, r);
}

int main(){
	ericxiao;
	cin >> N;
	for(int i = 2; i <= N; i++){
		cin >> p;
		chi[p].push_back(i);
	}
	for(int i = 1; i <= N; i++){
		cin >> val[i];
	}
	dfs();
	build();
	cin >> Q;
	while(Q--){
		cin >> com >> x;
		if(com[0] == 'g'){
			cout << query(0, l[x], r[x], 0, N + 1) << endl;
		} else {
			modify(0, l[x], r[x], 0, N + 1);
		}
	}
}


