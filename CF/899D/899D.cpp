#include <iostream>
#define int long long int
using namespace std;

int N;

signed main(){
	cin >> N;
	if(N <= 4){
		cout << N * (N - 1) / 2 << endl;
		return 0;
	}
	int k;
	for(k = 9; k; k = k * 10 + 9){
		if(k * 10 + 9 > N + N - 1) break;
	}
	//cout << "can: " << k << endl;
	int over = k + 1, ans = 0;
	for(int sum = k; sum - 1 <= 2 * N - 1; sum += over){
		//cout << "su = " << sum << endl;
		int high = min(sum - 1, N);
		int low = sum - high;
		//cout << "low = " << low << endl;
		ans += (high - low + 1) / 2;
	}
	cout << ans << endl;
}
