#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#define pii pair<int,int>
#define int long long int
using namespace std;

vector<int> topval, botval;
set<pii> topmon,botmon;
vector<int> dp[2];

int n, ans = 0;

signed main(){
    cin >> n;
    dp[0].resize(n);
    dp[1].resize(n);
    topval.resize(n);
    botval.resize(n);
    for(int i = 0; i < n; i++) cin >> topval[i];
    for(int i = 0; i < n; i++) cin >> botval[i];
    dp[0][0] = topval[0];
    dp[1][0] = botval[0];
    ans = max(dp[0][0], dp[0][1]);
    topmon.insert({0, 0});
    botmon.insert({0, 0});
    topmon.insert({topval[0], dp[0][0]});
    botmon.insert({botval[0], dp[1][0]});
    int ind;
    for(int i = 1; i < n; i++){
        dp[0][i] = (botmon.lower_bound({topval[i], -1})--)->second + topval[i];
        dp[1][i] = (topmon.lower_bound({botval[i], -1})--)->second + botval[i];
        cout << "dp[0][" << i << "] = " << dp[0][i] << endl;
        cout << "dp[1][" << i << "] = " << dp[1][i] << endl;
        pii p = {topval[i], dp[0][i]};
        auto it = topmon.lower_bound({topval[i], -1});
        if(it->second < dp[0][i]){
            it++;
            while(it != topmon.end() && it->second <= dp[0][i]){
                topmon.erase(it++);
            }
            topmon.insert(p);
        }
        p = {botval[i], dp[1][i]};
        it = botmon.lower_bound({botval[i], -1});
        if(it->second < dp[1][i]){
            it++;
            while(it != botmon.end() && it->second <= dp[1][i]){
                topmon.erase(it++);
            }
            botmon.insert(p);
        }
        ans = max(ans, max(dp[0][i], dp[1][i]));
    }
    cout << ans << endl;
}
