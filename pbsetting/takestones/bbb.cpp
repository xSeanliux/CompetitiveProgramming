#include <bits/stdc++.h>
#define vi vector<long long>
#define int long long
int MOD = 1e9+7;
using namespace std;

signed main()
{

    int n,k,x;
    cin >> n >> k;
    int ans[n+1];
    fill(ans,ans+n+1, 0);
    ans[0] = 1;
    for(int i = 0; i < n; i++){
        cin >> x;
        for(int j = n; j > 0; j--){
            ans[j] = ans[j-1];
        }
        ans[0] = 0;
        for(int j = 1; j <= n; j++){
            ans[j-1] -= ans[j] * x;
        }
        for(int j = 0; j <= n; j++){
            ans[j] %= MOD;
        }
    }

    if(k % 2){
        cout << -1 * ans[n-k];
    }else{
        cout << ans[n-k];
    }

}
