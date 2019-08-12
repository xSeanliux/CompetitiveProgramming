#include <iostream>
using namespace std;

int T, n, m, k, v, w, dp[10005][105];

int main(){
    cin >> T;
    while(T--){
        cin >> n >> m >> k;
        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            cin >> w >> v;
            for(int i = m; i >= w; i--){
                for(int j = k; j >= 1; j--){
                    dp[i][j] = max(dp[i][j], dp[i - w][j - 1] + v);
                    ans = max(dp[i][j], ans);
                }
            }
        }
        cout << ans << endl;
    }
}
