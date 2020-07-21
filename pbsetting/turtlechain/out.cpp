#include <iostream>
#include <vector>
#include <fstream>
#define vv vector<vector<int> >
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e5 + 226, MOD = 1e9 + 7;

int N, K, M, Q, k, a, b, c, d;
char com;
vv I, Z, seg[maxN * 4], C, res;

inline vv operator*(vv A, vv B){
	for(int i = 0; i < K; i++){
		for(int j = 0; j < K; j++){
			C[i][j] = 0;
			for(int k = 0; k < K; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
		}
	}
	return C;
}

inline void pull(int id){
	seg[id] = seg[2 * id + 1] * seg[2 * id + 2];		
}

void modify(int id, int l, int r, int pos, int a, int b, bool type = true){ //true: 1, false: toggle
	if(l + 1 == r){
		seg[id][a][b] = (type ? 1 : seg[id][a][b] ^ 1);
		return;
	}
	int m = (l + r) / 2;
	if(pos < m){
		modify(2 * id + 1, l, m, pos, a, b, type);
	} else{
		modify(2 * id + 2, m, r, pos, a, b, type);
	}
	pull(id);
	return;
}

vv query(int id, int l, int r, int ql, int qr){
	if(l >= qr || ql >= r) return I;
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	return query(2 * id + 1, l, m, ql, qr) * query(2 * id + 2, m, r, ql, qr);
}

signed main(){
	ericxiao;
	cin >> N >> K >> M >> Q;
	I.resize(K);
	Z.resize(K);
	for(int i = 0; i < K; i++){
		I[i].resize(K);
		Z[i].resize(K);
		I[i][i] = 1;
	}
	C = Z;
	fill(seg, seg + N * 4, Z);
	while(M--){
		cin >> a >> b >> c;
		modify(0, 0, N, a, b, c);
	}
	while(Q--){
		cin >> com;
		if(com == 'B'){
			cin >> k >> a >> b >> c >> d;
			bool swp = false;
			if(a > c){
				swap(a, c);
				swap(b, d);
				swp = true;
			}
			if(a <= k && k < c){
				vv A = query(0, 0, N, 0, a), B = query(0, 0, N, c, N);	
				res = B * A;
			} else {
				res = query(0, 0, N, a, c);
			}
			cout << res[b][d] << endl;
		} else {
			cin >> a >> b >> c;
			modify(0, 0, N, a, b, c, false);	
		}
	}
}
