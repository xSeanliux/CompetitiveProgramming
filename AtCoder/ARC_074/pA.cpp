#include <iostream>
#define int long long int
using namespace std;

const int INF = 1e16;

int H, W;

inline int solve(int W, int H){
	int ans = INF, a, b, c;
	for(int i = 1; i <= W; i++){
		a = H * i;
		b = ((W - i) / 2) * H;
		c = ((W - i + 1) / 2) * H;
		ans = min(ans, max(max(a, b) , c) - min(min(a, b), c)); 
		b = (W - i) * (H / 2);
		c = (W - i) * ((H + 1) / 2);
		ans = min(ans, max(max(a, b) , c) - min(min(a, b), c)); 
	}
	return ans;
}

signed main(){
	cin >> H >> W;
	cout << min(solve(W, H), solve(H, W));
}
