#include <iostream>
#include <vector>
#include <string.h>
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

string dir = "/Users/liusean/Desktop/Projects/Coding/CompetitiveProgramming/pbsetting/turtlechain/tc";
ofstream outfile;
ifstream infile;
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
	//cout << "id = " << id << ", l = " << l << ", r = " << r << endl;
	if(l + 1 == r){
		//cout << "a = " << a << ", b = " << b << ", type = " << type << endl;
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

void solve(int tc, int num){
	infile.open(dir + to_string(tc) + "/" + to_string(num) + ".in");
	outfile.open(dir + to_string(tc) + "/" + to_string(num) + ".out");
	infile >> N >> K >> M >> Q;
	I.resize(K);
	Z.resize(K);	
	for(int i = 0; i < K; i++){
		I[i].resize(K);
		Z[i].resize(K);
		I[i][i] = 1;
	}
	C = Z;
	for(int i = 0; i <= 4 * N; i++) seg[i] = Z;
	while(M--){
		infile >> a >> b >> c;
		modify(0, 0, N, a, b, c);
	}
	while(Q--){
		infile >> com;
		if(com == 'B'){
			infile >> k >> a >> b >> c >> d;
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
			outfile << res[b][d] << endl;
		} else {
			infile >> a >> b >> c;
			//cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
			modify(0, 0, N, a, b, c, false);	
		}
	}
	infile.close();
	outfile.close();
	cout << "Done: TC #" << tc << "/" << num << endl;
}
signed main(){
	ericxiao;
	for(int i = 1; i <= 10; i++){
		solve(1, i);
	}
	for(int i = 11; i <= 20; i++){
		solve(2, i);
	}
	for(int i = 21; i <= 30; i++){
		solve(3, i);
	}
	for(int i = 31; i <= 40; i++){
		solve(4, i);
	}
	for(int i = 41; i <= 50; i++){
		solve(5, i);
	}
}
