#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7, maxN = 2260;

vector<int> divs[maxN];

int dp[maxN][maxN], N, K;

int main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j += i) divs[j].push_back(i);
    }
    for(int i = 1; i <= N; i++){
        dp[1][i] = 1;
    }
    for(int l = 2; l <= K; l++){
        for(int i = 1; i <= N; i++){
            for(int d : divs[i]) dp[l][i] = (dp[l][i] + dp[l - 1][d]) % MOD;
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) ans = (ans + dp[K][i]) % MOD;
    cout << ans << endl;
}
