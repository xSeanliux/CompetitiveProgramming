#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326, MOD = 1e9 + 7;

inline int add(int a, int b){
	return (a + b >= MOD ? a + b - MOD : a + b);
}

struct Mat{
	int arr[2][2];
	Mat(){
		arr[0][0] = arr[0][1] = arr[1][0] = arr[1][1] = 0;	
	}
	Mat(int a, int b, int c, int d){
		arr[0][0] = a;
		arr[0][1] = b;
		arr[1][0] = c;
		arr[1][1] = d;
	}
	void disp(){
		for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) cout << arr[i][j] << " ";
		cout << endl;
	}
	
} seg[maxN * 4], tag[maxN * 4];

const Mat I = Mat(1, 0, 0, 1), F = Mat(1, 1, 1, 0);

Mat operator+(const Mat &a, const Mat &b){
	Mat res = Mat();
	for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) res.arr[i][j] = add(a.arr[i][j], b.arr[i][j]);
	return res;
}

Mat operator*(const Mat &a, const Mat &b){
	Mat res = Mat();	
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			for(int k = 0; k < 2; k++)
				res.arr[i][j] = (res.arr[i][j] + a.arr[i][k] * b.arr[k][j]) % MOD;
		}
	}
	return res;
}

Mat operator^(Mat b, int e){
	Mat res = I;
	for(int i = 0; i < 60; i++){
		if((e >> i) & 1) res = res * b;
		b = b * b;
	}
	return res;
}
bool hasTag[maxN * 4];

int N, M, arr[maxN], cmd, l, r, x;

inline void pull(int id){
	seg[id] = seg[(id << 1)] + seg[(id << 1) | 1];
}

inline void push(int id, int l, int r){
	if(!hasTag[id]) return;
	if(r - l > 1){
		hasTag[(id << 1)] = hasTag[(id << 1) | 1] = true;
		tag[(id << 1)] = tag[(id << 1)] * tag[id];
		tag[(id << 1) | 1] = tag[(id << 1) | 1] * tag[id];
	}
	seg[id] = seg[id] * tag[id];
	hasTag[id] = false;
	tag[id] = I;
}

void build(int id = 1, int l = 0, int r = N){
	tag[id] = I;
	hasTag[id] = 0;
	if(l + 1 == r){
		seg[id] = F ^ (arr[l] - 1);
		return;
	}
	int m = (l + r) / 2;
	build((id << 1), l, m);
	build((id << 1) | 1, m, r);
	pull(id);
}

void modify(int id, int l, int r, int ql, int qr, Mat v){
	push(id, l, r);
	if(l >= qr || ql >= r) return;
	if(ql <= l && r <= qr){
		hasTag[id] = true;
		tag[id] = tag[id] * v;
		push(id, l, r);
		return;
	}
	int m = (l + r) / 2;
	modify((id << 1), l, m, ql, qr, v);
	modify((id << 1) | 1, m, r, ql, qr, v);
	pull(id);
}

Mat query(int id, int l, int r, int ql, int qr){
	push(id, l, r);
	if(l >= qr || ql >= r) return Mat();
	if(ql <= l && r <= qr) return seg[id];
	int m = (l + r) / 2;
	return (query((id << 1), l, m, ql, qr) + query((id << 1) | 1, m, r, ql, qr));
}

signed main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> arr[i];
	build();
	while(M--){
		cin >> cmd >> l >> r;
		if(cmd == 1){
			cin >> x;
			Mat v = (F ^ x); 
			modify(1, 0, N, l - 1, r, v);
		} else {
			cout << query(1, 0, N, l - 1, r).arr[0][0] << endl;
		}
	}
}
