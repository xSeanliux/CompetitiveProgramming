#include <iostream>
using namespace std;

const int maxN = 5000, MOD = 1e9 + 7;
long long int dp[maxN + 50][maxN + 5], vals[maxN];

int N, k;


int main(){
    cin >> N >> k;
    for(int i = 0; i < N; i++){
        cin >> vals[i];
    }
    dp[1][0] = vals[0];
    for(int i = 1; i < N; i++){
        dp[1][i] = dp[1][i - 1] + vals[i];
    }
    for(int i = 2; i <= k; i++){
        for(int j = i - 1; j < N; j++){
            dp[i][j] = ((dp[i - 1][j - 1] * vals[j]) % MOD + dp[i][j - 1]) % MOD;
        }
    }
    cout << dp[k][N - 1] << endl;
}

