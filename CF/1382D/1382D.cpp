#include <iostream>
using namespace std;

const int maxN = 5226;
int T, N, x, cm, cnt;
bool can[maxN];

inline void solve(){
	cin >> N;
	cm = -1, cnt = 0;
	fill(can, can + 2 * N + 1, 0);
	can[0] = true;
	for(int i = 0; i < 2 * N; i++){
		cin >> x;
		if(cm == -1){
			cm = x;
		} else if(cm < x){
			//cout << "backback on " << cnt << endl;
			cm = x;
			for(int v = 2 * N; v >= cnt; v--) can[v] |= can[v - cnt];
			cnt = 0;
		}
		cnt++;
	}
	for(int v = 2 * N; v >= cnt; v--) can[v] |= can[v - cnt];
	cout << (can[N] ? "YES" : "NO") << endl;
}

int main(){
	cin >> T;
	while(T--){
		solve();
	}
}
