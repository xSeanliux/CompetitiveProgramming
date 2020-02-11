#include <iostream>
#include <string.h>
using namespace std;

int n, m, occ[30][30], dp[(1 << 20) + 10];
string s;

inline int bitCount(int x){
    int r = 0;
    while(x){
        r++;
        x -= (x & -x);
    }
    return r;
}

inline int hasBit(int i, int j){
    return (i & (1 << j)) > 0;
}

int main(){
    cin >> n >> m >> s;
    for(int i = 1; i < n; i++){
        occ[s[i] - 'a'][s[i - 1] - 'a'] = ++occ[s[i - 1] - 'a'][s[i] - 'a'];
    }
    /*
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            cout << "occ[" << (char)(i + 'a') << "][" << (char)(j + 'a') << "] = " << occ[i][j] << endl;
        }
    }
    */
    int lim = (1 << m), pos, cr;
    dp[0] = 0;
    for(int i = 1; i < lim; ++i){
        pos = bitCount(i);
        dp[i] = 1e8;
        for(int j = 0; j < m; ++j){
            if(hasBit(i, j)){
                cr = dp[(i ^ (1 << j))];
                for(int k = 0; k < m; ++k){
                    if(j == k) continue;
                    if(hasBit(i, k)){
                        cr += occ[j][k] * pos;
                    } else {
                        cr -= occ[j][k] * pos;
                    }
                }
                dp[i] = min(dp[i], cr);
            }

        }
        //cout << "dp[" << i << "] = " << dp[i] << endl;
    }
    cout << dp[lim - 1] << endl;
}
