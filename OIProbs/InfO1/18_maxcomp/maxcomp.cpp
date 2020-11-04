#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
 
const int maxN = 1e3 + 326, INF = 2e15;
 
int N, M, arr[maxN][maxN], dp[maxN], nxt[maxN], mx[maxN], nxtmx[maxN], r = -1, narr[maxN][maxN]; 
 
int solve(){
	for(int i = 0; i < M; i++) dp[i] = nxt[i] = mx[i] = nxtmx[i] = -INF;
	int ans = -INF;
	for(int i = 0; i < M; i++){
		dp[i] = -arr[0][i] + i - 1;
		mx[i] = dp[i];
		if(i){
			mx[i] = max(mx[i], mx[i - 1]);
			ans = max(ans, arr[0][i] - i + mx[i - 1]);
		}
	}
	for(int i = 1; i < N; i++){
		for(int j = 0; j < M; j++){
			dp[j] = -arr[i][j] + i + j - 1;	
			nxtmx[j] = max(mx[j], dp[j]);
			ans = max(ans, arr[i][j] - i - j + mx[j]);
			if(j){
				nxtmx[j] = max(nxtmx[j], nxtmx[j - 1]);
				ans = max(ans, arr[i][j] - i - j + nxtmx[j - 1]);
			}
			//cout << "Pre for " << i << ", " << j << " = " << nxtmx[j] << endl;
		}
		for(int j = 0; j < M; j++) mx[j] = nxtmx[j];
	}
	return ans;
}
 
void rot(){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			narr[j][N - i - 1] = arr[i][j];	
			//cout << "narr[" << j << "][" << N - i - 1 << "] = " << arr[i][j] << endl;
		}
	}
	swap(N, M);
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) arr[i][j] = narr[i][j];
}
 
signed main(){
	ericxiao
	cin >> N >> M;
	for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> arr[i][j];
	for(int i = 0; i < 5; i++){
		r = max(r, solve());
		/*
		for(int j = 0; j < N; j++){
			for(int k = 0; k < M; k++){
				cout << arr[j][k] << " ";
			}
			cout << endl;
		}
		*/
		rot();
	}
	cout << r << endl;
}
