#include <iostream>
using namespace std;

const int INF = 2147483647;
int dp[(int)1e4 + 100];
int T, N, M, v, w;

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 0; i <= 100*N; i++){
            dp[i] = INF;
        }
        dp[0] = 0;
        for(int i = 0; i < N; i++){
            cin >> w >> v;
            for(int j = 100 * N; j >= v; j--){
                if(dp[j-v] == INF) continue;
                dp[j] = min(dp[j - v] + w, dp[j]);
                //cout << "MIN WEIGHT FOR VAL " << j << " = " << dp[j] << endl;
            }
        }
        for(int i = 100 * N; i >= 0; i--){
            if(dp[i] <= M){
                cout << i << endl;
                break;
            }
        }
    }
}
