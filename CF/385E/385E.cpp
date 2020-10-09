#include <iostream>
#include <vector>
#define vv vector<vector<int>>
#define int long long int
using namespace std;

vv I, turn = {
	{2, 1, 1, 0, 1, 2},
	{1, 2, 0, 1, 1, 2},
	{1, 1, 1, 0, 1, 2},
	{1, 1, 0, 1, 1, 2},
	{0, 0, 0, 0, 1, 1},
	{0, 0, 0, 0, 0, 1}
}; //x, y, dx, dy, t, 1





int N, sx, sy, dx, dy, t; 

inline int add(int a, int b){
	return (a + b >= N ? a + b - N : a + b);
}

vv operator*(vv a, vv b){
	vv r;
	r.resize(a.size());
	for(int i = 0; i < a.size(); i++){
		r[i].resize(b[0].size());
		for(int j = 0; j < b[0].size(); j++){
			for(int k = 0; k < a[0].size(); k++){
				r[i][j] = add(r[i][j], a[i][k] * b[k][j] % N);
			}
		}
	}
	return r;
}

signed main(){
	cin >> N >> sx >> sy >> dx >> dy >> t;
	while(dx < 0) dx += N;
	while(dy < 0) dy += N;
	dx %= N;
	dy %= N;
	I.resize(6);
	for(int i = 0; i < 6; i++){ I[i].resize(6); I[i][i] = 1; }
	for(int i = 0; i < 64; i++){
		if(((t) >> i) & 1){
			I = I * turn;
		}
		turn = turn * turn;
	}
	vv st = {
		{sx - 1},
		{sy - 1},
		{dx},
		{dy},
		{0},
		{1}
	};
	st = I * st;
	cout << st[0][0] + 1 << " " << st[1][0] + 1 << endl;
}
