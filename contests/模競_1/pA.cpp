#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int t, N, G, K, dp[21][1005], vals[1005];
const int mod = 998244353;

signed main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> N >> G >> K; //k bags which add to G
        for(int i = 0; i < N; i++){
            cin >> vals[i];
        }
        for(int i = 0; i <= K; i++){
            for(int j = 0; j <= G; j++){
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for(int i = 0; i < N; i++){
            for(int t = K; t >= 1; t--){
                for(int j = G; j >= vals[i]; j--){
                    dp[t][j] += dp[t - 1][j - vals[i]];
                    dp[t][j] %= mod;
                }
            }
        }
        cout << dp[K][G] << endl;
    }
}

