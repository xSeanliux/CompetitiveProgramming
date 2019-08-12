#include <iostream>
using namespace std;

const int MOD = 1000007, maxN = 100000;
int T, N, dp[maxN + 10], pre;

int main(){
    dp[0] = 1;
    dp[2] = 3;
    pre = 1;
    for(int i = 4; i <= maxN; i += 2){
        dp[i] = (3*dp[i-2] + 2*pre) % MOD;
        pre = (pre + dp[i-2]) % MOD;
    }
    cin >> T;
    while(T--){
        cin >> N;
        cout << dp[N] << endl;
    }
}
