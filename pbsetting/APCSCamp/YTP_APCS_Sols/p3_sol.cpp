#include <iostream>
using namespace std;
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define max(a,b) (a)>(b)?a:b
const int maxN = 1e3 + 326;

 

int N, M, X[maxN][maxN], Y[maxN][maxN], cnt[maxN][maxN], ans = 0, mx;

int main() {
    ericxiao;
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) cin >> X[i][j] >> Y[i][j];
   	
   	for(int j = 0; j < M; j++){
   		mx = -2e9;
   		for(int i = 0; i < N; i++) mx = max(mx, X[i][j]);
   		for(int i = 0; i < N; i++) if(X[i][j] == mx) cnt[i][j]++;
   	}

   	for(int i = 0; i < N; i++){
   		mx = -2e9;
   		for(int j = 0; j < M; j++) mx = max(mx, Y[i][j]);
   		for(int j = 0; j < M; j++) if(Y[i][j] == mx) cnt[i][j]++;
   	}
   	
    for(int i = 0; i < N; i++) for(int j = 0; j < M; j++) if(cnt[i][j] == 2) ans++;
   	cout << ans << endl;
}

