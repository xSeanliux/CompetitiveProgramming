#include <iostream>
using namespace std;

const int maxN = 1226;
int T, N, M, a[maxN], b[maxN];

inline void solve(){
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> a[i];
	for(int j = 0; j < M; j++) cin >> b[j];
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(a[i] == b[j]){
				cout << "YES\n1 " << a[i] << endl;
				return;
			}
		}
	}
	cout << "NO\n";
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
