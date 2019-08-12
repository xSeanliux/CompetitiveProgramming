#include <iostream>
using namespace std;

unsigned long long int T, n, vals[100005], dp[5][100005], MOD = 1e9 + 7;
bool flag = false;
int main(){
    while(cin >> n){
        for(int i = 0; i < 5; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = 0;
            }
        }

        if(!n){
            cout << 0 << endl;
            continue;
            //return 0;
        }
        cin >> vals[0];

        dp[1][0] = vals[0];
        for(int i = 1; i < n; i++){
            cin >> vals[i];
            dp[1][i] = (dp[1][i-1] + vals[i]) % MOD;
        }
        if(n < 4){
            cout << 0 << endl;
            continue;
        }
        for(int i = 2; i <= 4; i++){
            for(int j = i-1; j < n; j++){
                dp[i][j] = (dp[i][j-1]%MOD + (dp[i-1][j-1]%MOD)*vals[j]%MOD) % MOD;
                //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
            }
        }
        printf("%llu\n", dp[4][n-1]);
    }

}
