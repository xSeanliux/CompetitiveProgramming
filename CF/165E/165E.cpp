#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxLog = 22, maxN = 1e6 + 5;

int dp[(1 << maxLog)], N, vals[maxN];

int main(){
    ericxiao;
    cin >> N;
    fill(dp, dp + (1 << maxLog), -1);
    for(int i = 0; i < N; i++){
        cin >> vals[i];
        dp[vals[i]] = vals[i];
    }
    for(int i = 0; i < (1LL << maxLog); i++){
        if(dp[i] != -1) continue;
        for(int j = 0; j < maxLog; j++){
            if((i & (1 << j)) > 0){
                if(dp[i ^ (1 << j)] != -1){
                    dp[i] = dp[i ^ (1 << j)];
                    break;
                }
            }
        }
    }
    for(int i = 0; i < N; i++){
        cout << dp[ ((1LL << maxLog) - 1) ^ vals[i]] << " \n"[i == N - 1];
    }
}
