#include <iostream>
#define int long long int
using namespace std;

const int INF = 2147483647;
int T, N, x, dp[105][105], vals[105], pre[105];

signed main(){
    cin >> T;
    while(T--){
        cin >> N;
        for(int i = 0; i < N; i++){
            cin >> vals[i];
            if(!i) pre[i] = vals[i];
            else pre[i] = vals[i] + pre[i-1];
        }
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= N; j++){
                if(i + 1 == j)
                    dp[i][j] = 0;
                else
                    dp[i][j] = INF;
                //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            }
        }
        for(int i = 1; i <= N; i++){//len is i
            for(int j = 0; j <= N - i; j++){ //len is i, from i
                for(int k = j + 1; k < i + j; k++){
                    dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k][j + i] +  pre[j + i - 1] - (j ? pre[j-1] : 0));
                    //cout << "Checking dp[" << j << "][" << k << "] to " << "dp[" << k <<"][" << j + i << "], val = " << dp[j][k] + dp[k][j + i] +  pre[j + i - 1] - (j ? pre[j-1] : 0) << endl;
                }
                //cout << "dp[" << j << "][" << j + i << "] = " << dp[j][j + i] << endl;
            }
        }

        cout << dp[0][N] << endl;
    }
}
