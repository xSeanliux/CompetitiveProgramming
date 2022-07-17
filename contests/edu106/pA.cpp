#include <iostream>
using namespace std;

int T, N, k1, k2, w, b;

inline int Abs(int a){
	return a < 0 ? -a : a;
}
inline void solve(){
	cin >> N >> k1 >> k2 >> w >> b;
	if(k1 > k2) swap(k1, k2);
	if(k1 + (k2 - k1) / 2 < w){
		cout << "NO\n";
		return;
	}
	k1 = N - k1;
	k2 = N - k2;
	if(k2 + (k1 - k2) / 2 < b){
		cout << "NO\n";
		return;
	}
	cout << "YES\n";

}
int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
