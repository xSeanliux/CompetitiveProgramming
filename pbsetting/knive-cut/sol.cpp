#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int INF = 1e9 + 10;

int dp[25][505], arr[505], n, k;

signed main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int cmin = INF, cmax = -INF;
    for(int i = 0; i < n; i++){
        cmin = min(arr[i], cmin);
        cmax = max(arr[i], cmax);
        dp[1][i] = cmax - cmin;
    }
    for(int t = 2; t <= k; t++){
        for(int i = 0; i < n; i++){
            if(i < t - 1){
                dp[t][i] = INF;
                continue;
            }
            cmin = cmax = arr[i];
            dp[t][i] = dp[t - 1][i - 1];
            for(int j = i - 1; j >= 0; j--){
                cmin = min(arr[j], cmin);
                cmax = max(arr[j], cmax);
                dp[t][i] = min(dp[t][i], cmax - cmin + dp[t - 1][j - 1]);
            }
        }
    }
    cout << dp[k][n - 1] << endl;
}
