#include <iostream>
#include <vector>
#include <string.h>
#include <deque>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e5 + 10;

int n, k, dp[maxN];
deque<pii> dq;
string s;


int main(){
    cin >> n >> k >> s;
    s = '$' + s;
    dp[0] = 0;
    pii p;
    for(int i = 1; i <= n; i++){
        dp[i] = dp[i - 1] + i;
        while(dq.size() && i > k + 1 && dq.front().F < i - k){
            dq.pop_front();
        }
        if(dq.size())
            dp[i] = min(dp[i], dq.front().S);
        if(s[i] == '1'){
            if(i > k + 1){
                dp[i] = min(dp[i], i + dp[i - k - 1]);
            } else {
                dp[i] = min(dp[i], i);
            }
            p = {i, i};
            if(i > k) p.S += dp[i - k - 1];
            while(dq.size() && dq.back().S >= p.S) dq.pop_back();
            dq.push_back(p);
        }
        cout << "DP[" << i << "] = " << dp[i] << endl;
    }
    cout << dp[n] << endl;
}
