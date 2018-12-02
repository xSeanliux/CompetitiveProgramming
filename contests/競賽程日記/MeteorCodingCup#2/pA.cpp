#include <iostream>
#include <string>
#include <set>
using namespace std;

string s;
set <string> arr;

int n, q;

int main(){
    cin >> n >> q;
    int dp[n][q];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < q; j++)
            dp[i][j] = 0;
    dp[0][0] = dp[0][1] = 1;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < q; j++){
            dp[i+1][0] += dp[i][j];
            if(j < q-1) dp[i+1][j+1] += dp[i][j];
        }
    }
    long long int ans = 0;
    for(int i = 0; i < q; i++)
        ans += dp[n-1][i];
    cout << ans << endl;

}
