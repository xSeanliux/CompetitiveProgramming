#include <iostream>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int INF = 1e7;

int dp[(1LL << 12) + 10], n, m, a, b, c;
pii keys[1010];

int main(){
    cin >> n >> m;
    int seed = 0;
    for(int i = 0; i < m; i++){
        cin >> keys[i].F >> b;
        seed = 0;
        for(int i = 0; i < b; i++){
            cin >> c;
            c--;
            seed |= (1LL << c);
        }
        keys[i].S = seed;
        //cout << "Cost of " << i << " th key is " << keys[i].F << ", and seed = " << keys[i].S << endl;
    }
    for(int i = 0; i < (1LL << n); i++){
        dp[i] = INF;
    }
    dp[0] = 0;
    //for(int i = 0; i < (1LL << n); i++){
    //    cout << "dp[" << i << "] = " << dp[i] << endl;
    //}

    int nv;

    for(int i = 0; i < (1LL << n); i++){
        if(dp[i] == INF) continue;
        for(int j = 0; j < m; j++){
            //cout << "dp[" << (i | keys[j].S) << "] = " << dp[(i | keys[j].S)] << endl;
            //cout << "Cost of " << j << "th key = " << keys[i].F << endl;
            //cout << "Newvl = " << dp[i] + keys[j].F << endl;
            dp[(i | keys[j].S)] = min(dp[(i | keys[j].S)], dp[i] + keys[j].F);
            //cout << "dp[" << (i | keys[j].S) << "] = " << dp[(i | keys[j].F)] << endl;
        }
    }
    cout << (dp[(1LL << n) - 1] == INF ? -1 : dp[(1LL << n) - 1]) << endl;
}
