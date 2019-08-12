#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int N, topans, botans;
vector<int> topval, botval;
vector<vector<int> > dp;

signed main(){
    cin >> N;
    topval.resize(N);
    botval.resize(N);
    dp.resize(2);
    dp[0].resize(N);
    dp[1].resize(N);
    for(int i = 0; i < N; i++) cin >> topval[i];
    for(int i = 0; i < N; i++) cin >> botval[i];

    dp[0][0] = topval[0];
    dp[1][0] = botval[0];
    topans = topval[0];
    botans = botval[0];
    int ans = max(topans, botans);
    for(int i = 1; i < N; i++){
        dp[0][i] = topval[i] + botans;
        dp[1][i] = botval[i] + topans;
        topans = max(dp[0][i], topans);
        botans = max(dp[1][i], botans);
        ans = max(ans, max(botans, topans));
    }
    cout << ans << endl;
}
