#include <iostream>
using namespace std;

const int maxN = 1e5;
int T, N, K, vals[maxN + 10], dp[maxN + 10];

int main(){
    cin >> T;
    while(T--){
        cin >> N >> K;
        for(int i = 0; i < N; i++){
            cin >> vals[i];
            dp[i] = 0;
        }
        int cM = 0, ans = 0;
        for(int i = 0; i < K; i++){
            cM = max(vals[i], cM);
            dp[i] = cM;
            ans = max(ans, dp[i]);
        }
        int currentMax = vals[0];
        for(int i = K; i < N; i++){
            dp[i] = vals[i] + currentMax;
            currentMax = max(currentMax, dp[i - K + 1]);
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
    }
}
