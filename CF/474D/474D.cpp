#include <iostream>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;
int T, k, a, b;

signed main(){
    cin >> T >> k;
    int dp[(int)1e5 + 10][2], pre[(int)1e5 + 10];
    int currentSum = 0;
    for(int i = 0; i < k; i++){
        dp[i][0] = 1;
        dp[i][1] = 0;
    }
    for(int i = k; i <= (int)(1e5); i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - k][0] + dp[i - k][1]) % MOD;
    }
    pre[0] = dp[0][0] + dp[0][1];
    for(int i = 1; i <= (int)(1e5); i++){
        pre[i] = (pre[i-1] + dp[i][0] + dp[i][1]) % MOD;
    }
    while(T--){
        cin >> a >> b;

        cout << (pre[b] - pre[a-1] >= 0 ? pre[b] - pre[a-1] : pre[b] - pre[a-1] + MOD) << endl;
    }
}
