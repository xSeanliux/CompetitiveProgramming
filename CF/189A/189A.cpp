#include <iostream>
using namespace std;

int dp[4005], n, a, b, c;

int main(){
    cin >> n >> a >> b >> c;
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        if(i >= a && dp[i - a]){
            dp[i] = max(dp[i], dp[i - a] + 1);
        }
        if(i >= b && dp[i - b]){
            dp[i] = max(dp[i], dp[i - b] + 1);
        }
        if(i >= c && dp[i - c]){
            dp[i] = max(dp[i], dp[i - c] + 1);
        }
        //cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    cout << dp[n] - 1 << endl;
}
