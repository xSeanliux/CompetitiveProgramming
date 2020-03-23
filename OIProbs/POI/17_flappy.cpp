#include <iostream>
#include <vector>
#define int long long int 
using namespace std;

const int maxN = 5e5 + 10, INF = 1e18;

struct Obj{
	int x, pos[4];
	Obj(){}
	Obj(int X, int U, int D): x(X){
		pos[0] = U;
		pos[1]  = max(U - 1, D);
		pos[2] = min(D + 1, U);
		pos[3] = D;
	}
}

inline int getPress(int fx, int fy, int tx, int ty){
	//total of tx - fx operations 
	//A presses
	//B not presses
	//A + B = tx - fx
	//A - B = ty - fy
	//A = (tx - fx + ty - fy) / 2
	//B = (tx - fx + fy - ty) / 2
	//A >= 0, B >= 0
	if((tx - fx < ty - fy) |(tx - fx + ty - fy) & 1 || (tx - fx + fy - ty) & 1 ||
}

int N, x, a, b, dp[maxN][4];
vector<Obj> objs;

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> x >> a >> b;
		if(a + 1 == b){
			cout << "NIE\n";
			return 0;
		}
		objs.emplace_back(x, b - 1, a + 1);
	}
}
