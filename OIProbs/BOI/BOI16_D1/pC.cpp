#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
int res[2005][2005], N, Q, l, r, u, d;
int dirs[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

inline void build(){
	int X = N, Y = N, cdir = 0;
	int time = 0;
	int stpsleft = 1, curStp = 1;
	for(int i = 1; i <= (2 * N + 1) * (2 * N + 1); i++){
		res[X][Y] = i;
		X += dirs[cdir][0];
		Y += dirs[cdir][1];
		stpsleft--;
		if(!stpsleft){
			cdir = (cdir + 1) % 4;
			if(time){
				curStp++;
				time = 0;
			} else {
				time = 1;
			}
			stpsleft = curStp;
		}
	}
	for(int i = 0; i < (2 * N + 1); i++){
		for(int j = 0; j < (2 * N + 1); j++){
			res[i][j] = (res[i][j] + (i ? res[i - 1][j] : 0) + (j ? res[i][j - 1] : 0) - (i && j ? res[i - 1][j - 1] : 0)) % MOD;
		}
	}
}

inline int Abs(int x){
	return ( x < 0 ? -x : x);
}

signed main(){
	cin >> N >> Q;
	if(N <= 1000){
		build();
		while(Q--){
			cin >> l >> u >> r >> d;	
			l += N;
			u += N;
			r += N;
			d += N;
			cout << (res[r][d] - (l ? res[l - 1][d] : 0) - (u ? res[r][u - 1] : 0) + (l && u ? res[l - 1][u - 1] : 0) + 2 * MOD) % MOD << endl;
		}
		return 0;
	}
	while(Q--){
		int x, y;
		cin >> x >> y;
		cin >> x >> y;
		if(!x && !y){
			cout << 1 << endl;
			continue;
		}
		int res;
		if(Abs(x) >= Abs(y)){
			if(x > 0){
				res = ((1 + (4 * x - 2) * x % MOD) % MOD - Abs(y - x) % MOD + MOD) % MOD;
			} else {
				res = ((1 + (4 * Abs(x) + 2) * Abs(x)) % MOD - Abs(y - x) % MOD + MOD) % MOD; 
			}
		} else {
			if(y > 0){
				res = ((1 + (4 * y - 2) * y) % MOD + Abs(y - x)) % MOD;
			} else {
				res = ((1 + (-4 * y + 2) * (-1 * y)) % MOD + Abs(y - x)) % MOD;
			}
		}
		cout << res << endl;

	}
}
