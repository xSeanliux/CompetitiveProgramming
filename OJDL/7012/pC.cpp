#include <iostream>
#include <vector>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 1e8;

int q, h, n;
vector<int> hei, dp;

int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> h >> n;
        hei.resize(n);
        dp.resize(n + 1);
        for(int i = 0; i < n; i++){
            cin >> hei[i];
        }
        dp[0] = 0;
        dp[1] = 1;
        hei.push_back(0);
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + 1;
            if(hei[i - 1] - hei[i] == 1) dp[i] = min(dp[i], dp[i - 2]);
        }
        cout << min(dp[n], dp[n - 1]) << endl;
    }
}
