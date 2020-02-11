#include <iostream>
#include <vector>
#define int long long int
using namespace std;

const int MOD = 998244353, maxN = 2e3 + 10;

int n, m, dp[maxN][maxN];

vector<int> perm;

signed main(){
    cin >> n >> m;
    perm.resize(n);
    for(int i = 0; i < n; i++) cin >> perm[i];
    for(int i = 0; i <= n; i++) dp[i][i] = 1;
    int minVal, minAt, sl, sr;
    for(int len = 1; len <= n; len++){
        for(int i = 0; i + len <= n; i++){
            minVal = maxN;
            sl = sr = 0;
            for(int j = i; j < i + len; j++){
                if(minVal > perm[j]){
                    minVal = perm[j];
                    minAt = j;
                }
            }
            //cout << "Running dp[" << i << "][" << i + len << "]" << endl;
            //cout << "minval = " << minVal << ", minat = " << minAt << endl;
            for(int j = i; j <= minAt; j++) sl = (sl + (dp[i][j] * dp[j][minAt]) % MOD) % MOD;
            for(int j = minAt + 1; j <= i + len; j++) sr = (sr + (dp[minAt + 1][j] * dp[j][i + len]) % MOD) % MOD;
            dp[i][i + len] = sl * sr % MOD;
            //cout << " = " << dp[i][i + len] << endl;
        }
    }
    cout << dp[0][n] << endl;
}
