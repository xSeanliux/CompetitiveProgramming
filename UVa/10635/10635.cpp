#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
#include <vector>
#define INF 214748364
using namespace std;

int c, n, p, q;


int main(){
    cin >> c;
    for(int kk = 1; kk <= c; kk++){
        map <int, int> m;
        cin >> n >> p >> q;
        vector<int> target;
        int k;
        for(int i = 0 ; i <= p; i++){
            cin >> k;
            m.insert(pair<int, int>(k, i));
        }
        for(int i = 0 ; i <= q; i++){
            cin >> k;
            if(m.count(k)){
                target.push_back(m[k]);
            }
        }
        int dp[n*n];
        memset(dp, INF, n * n);
        for(int i = 0 ; i < n * n; i++)
            dp[i] = INF;

        for(int i = 0 ; i < target.size(); i++){
            //cout << "t: " << target[i] << ", placed " << lower_bound(dp, dp + q + 1, target[i]) - dp << endl;
            *lower_bound(dp, dp + n * n, target[i]) = target[i];
            /*
            for(int i = 0 ; i <= n * n; i++){
                cout << dp[i] << " ";
            }
            cout << endl;
            */
        }
        printf("Case %d: %d\n", kk, lower_bound(dp, dp + n * n, INF) - dp);
    }
}
