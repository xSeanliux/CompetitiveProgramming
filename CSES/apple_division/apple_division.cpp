#include <iostream>
#define int long long int
using namespace std;

const int maxN = 20, INF = 1e18;
int N, arr[maxN], sum, ans = INF;

inline int Abs(int x){
	return x < 0 ? -x : x;
}

signed main(){
	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	for(int i = 0; i < (1 << (N - 1)); i++){
		int a = arr[N - 1];
		for(int j = 0; j < N - 1; j++) a += ((i >> j) & 1) * arr[j]; 
		ans = min(ans, Abs(sum - 2 * a));
	}
	cout << ans << endl;
}
