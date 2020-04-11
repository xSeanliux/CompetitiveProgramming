#include <iostream>
using namespace std;

const int maxN = 2226, INF = 1e9;

int dp[maxN], nxtdp[maxN], N, h, l, r, x;

inline int isV(int x){
    return l <= x && x <= r;
}

int main(){
    cin >> N >> h >> l >> r;
    fill(dp, dp + h, -INF);
    dp[0] = 0;
    for(int i = 0; i < N; i++){
        cin >> x;
        for(int t = 0; t < h; t++){
            nxtdp[(t + x) % h] = dp[t] + isV((t + x) % h);
        }
        for(int t = 0; t < h; t++){
            nxtdp[(t + x + h - 1) % h] = max(nxtdp[(t + x + h - 1) % h], dp[t] + isV((t + x + h - 1) % h));
        }
        //cout << "i = " << i << endl;
        for(int t = 0; t < h; t++){
            dp[t] = nxtdp[t];
            //if(dp[t] < 0) cout << "- ";
            //else cout << dp[t] << " ";
        }
        //cout << endl;

    }
    int mx = 0;
    for(int i = 0; i < h; i++) mx = max(mx, dp[i]);
    cout << mx << endl;
}
