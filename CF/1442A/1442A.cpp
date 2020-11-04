#include <iostream>
using namespace std;

const int maxN = 3e5 + 326;

int T, N, arr[maxN], a[maxN], b[maxN];

inline void solve(){
	cin >> N;
	for(int i = 0; i < N; i++) cin >> arr[i];
	a[0] = arr[0];
	b[0] = 0;
	for(int i = 1; i < N; i++){
		a[i] = min(a[i - 1], arr[i] - b[i - 1]);
		b[i] = arr[i] - a[i];
	}
	if(a[N - 1] < 0){
		cout << "NO\n";
		return;
	}
	for(int i = 1; i < N; i++){
		if(b[i] < b[i - 1]){
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
