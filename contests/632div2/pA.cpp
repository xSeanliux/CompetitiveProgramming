#include <iostream>
using namespace std;

int N, M, T;
char ans[200][200];
inline void solve(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			ans[i][j] = 'B';
		}
	}
	ans[0][0] = 'W';
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cout << ans[i][j];
		}
		cout << endl;
	}
}
int main(){
	cin >> T;
	while(T--){
		cin >> N >> M;
		solve();
	}
}
