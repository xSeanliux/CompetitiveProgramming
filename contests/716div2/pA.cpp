#include <iostream>
#include <set>
using namespace std;


const int maxN = 1e5 + 326;
int T, N;
bool f[maxN];

inline void solve(){
	cin >> N;
	int x;
	bool flg = false;
	for(int i = 0; i < N; i++){
		cin >> x;
		if(!f[x]){
			flg = true;
		}
	}
	cout << (flg ? "YES" : "NO") << endl;
}


int main(){
	for(int i = 1; i <= 100; i++) f[i * i] = 1;
	cin >> T;
	while(T--){
		solve();
	}
}
