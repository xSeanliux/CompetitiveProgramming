#include <iostream>
#define int long long int
using namespace std;

const int maxN = 2e5 + 326, INF = 1e18;
int N, arr[maxN], ans = INF; 

inline int Abs(int x){
	return x < 0 ? -x : x;
}
signed main(){
	cin >> N;
	for(int i = 1; i <= N; i++){
		cin >> arr[i];	
		arr[i] += arr[i - 1];
	}
	for(int i = 1; i < N; i++){
		ans = min(ans, Abs(arr[N] - 2 * arr[i]));
	}
	cout << ans << endl;
}
