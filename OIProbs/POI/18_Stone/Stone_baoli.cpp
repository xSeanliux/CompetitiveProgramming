#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 20;
int N, x, y, ans;
pii points[maxN];

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> points[i].F >> points[i].S;
	for(int i = 0; i < (1 << N); i++){
		int X = 0, Y = 0;
		for(int j = 0; j < N; j++){
			if((i >> j) & 1){
				X += points[j].F;
				Y += points[j].S;
			}
		}
		ans = max(ans, X * X + Y * Y);
	}
	cout << ans << endl;
}
