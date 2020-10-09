#include <iostream>
#include <stack>
#define int long long int
using namespace std;

const int maxN = 1e6 + 10;
int T, N, x, arr[maxN];

inline void solve(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	for(int i = 0; i < N; i++){
		if(arr[i] != arr[0]){
			cout << 1 << endl;
			return;
		}
	}
	cout << N << endl;

}


signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
