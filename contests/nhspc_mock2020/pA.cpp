#include <iostream>
#define int long long int
using namespace std;

const int maxN = 1e5 + 326;
int N, a[maxN], b[maxN], jizz[4];
signed main(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> a[i] >> b[i];
	for(int i = 0; i < N; i++){
		jizz[(a[i] & 1) * 2 + (b[i] & 1)]++;
	}
	int ans = 0;
	for(int i = 0; i < 4; i++){
		ans += (jizz[i] * (jizz[i] - 1)) / 2;
	}
	cout << ans << endl;
}
