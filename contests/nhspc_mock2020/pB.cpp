#include <iostream>
#define int long long int
using namespace std;

const int maxN = 2e3 + 326;
int N, M, arr[maxN][maxN];

signed main(){
	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> arr[i][j];
	for(int i = 0; i < N - 1; i++) for(int j = 0; j < M - 1; j++){
		int t = arr[i][j];
		arr[i][j] -= t;
		arr[i + 1][j + 1] -= t;
		arr[i + 1][j] += t;
		arr[i][j + 1] += t;
	}
	bool x = true;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(arr[i][j] != 0) x = false;
	if(x) cout << "Yes\n";
	else cout << "No\n";
}
