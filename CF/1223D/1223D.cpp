#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 1e6;
int q, n;

vector<pii> v;
vector<int> arr, lis, dp;

int main(){
    ericxiao;
    cin >> q;
    while(q--){
        cin >> n;
        v.clear();
        arr.resize(n);
        lis.resize(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            lis[i] = arr[i];
        }
        sort(lis.begin(), lis.end());
        int m = unique(lis.begin(), lis.end()) - lis.begin();
        for(int &i : arr){
            i = lower_bound(lis.begin(), lis.begin() + m, i) - lis.begin();
        }
        v.resize(m + 1);
        dp.resize(m + 1);
        for(auto &p : v) p = {INF, -INF};
        for(int i = 0; i < n; i++){
            v[arr[i]].F = min(v[arr[i]].F, i);
            v[arr[i]].S = i;
        }
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < m; i++){
            if(v[i].F > v[i - 1].S){
                dp[i] = dp[i - 1] + 1;
            } else dp[i] = 1;
            ans = max(ans, dp[i]);
        }
        cout << m - ans << endl;


    }
}
