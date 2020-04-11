#include <iostream>
#define int long long int
using namespace std;

const int maxN = 226;
int T, N, M, ans, c;
int arr[maxN][maxN];
bool standing[maxN][maxN], nxtStanding[maxN][maxN];

inline bool runround(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(standing[i][j]) ans += arr[i][j];
			nxtStanding[i][j] = standing[i][j];
		}
	}
	bool r = false;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(!standing[i][j]) continue;
			int nei = 0, neisum = 0;
			for(int p = i - 1; p; p--){
				if(standing[p][j]){
					nei++;
					neisum += arr[p][j];
					break;
				}
			}
			for(int p = i + 1; p <= N; p++){
				if(standing[p][j]){
					nei++;
					neisum += arr[p][j];
					break;
				}
			}
			for(int p = j - 1; p; p--){
				if(standing[i][p]){
					nei++;
					neisum += arr[i][p];
					break;
				}
			}
			for(int p = j + 1; p <= M; p++){
				if(standing[i][p]){
					nei++;
					neisum += arr[i][p];
					break;
				}
			}
			//cout << "for i = " << i << " j = " << j << ", nei = " << nei << ", sum = " << neisum << endl;
			if(!nei) continue;
			if(nei * arr[i][j] < neisum){
				r = true;	
				nxtStanding[i][j] = false;
			}
		}
	}
	for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) standing[i][j] = nxtStanding[i][j];
	return r;
}

inline void solve(){
	cin >> N >> M;
	ans = 0;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			cin >> arr[i][j];	
			standing[i][j] = true;
		}
	}
	bool f = true;
	while(f){
		f &= runround();
		/*
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= M; j++){
				if(standing[i][j]) cout << arr[i][j];
				else cout << '.';
				cout << " ";
			}
			cout << endl;
		}
		*/
	}
	cout << "Case #" << ++c << ": " << ans << endl; 
}
signed main(){
	cin >> T;
	while(T--){
		solve();
	}
}
