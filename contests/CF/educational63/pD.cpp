#include <iostream>
#include <vector>
using namespace std;

long long int N, x, mP, mN;
const int INF = 0x3f3f3f;

int main(){
    cin >> N >> x;
    long long int dp[N][3], vals[N]; //0: *, no *, already flipped
    cin >> vals[0];
    dp[0][0] = max(x * vals[0], 0LL);
    dp[0][1] = max(vals[0], 0LL);
    dp[0][2] = max(vals[0], 0LL);
    long long int ans = 0LL;
    for(int i = 1; i < N; i++){
        cin >> vals[i];
        dp[i][0] = max(vals[i] * x + max(dp[i-1][1], dp[i-1][0]), 0LL);
        dp[i][1] = max(vals[i] + dp[i-1][1], 0LL);
        dp[i][2] = max(vals[i] + max(dp[i-1][2], dp[i-1][0]), 0LL);
        ans = max(ans, max(dp[i][0], max(dp[i][1], dp[i][2])));
    }
    cout << max(ans, max(dp[0][0], max(dp[0][1], dp[0][2]))) << endl;
}
