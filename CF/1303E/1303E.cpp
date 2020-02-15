#include <iostream>
#include <string.h>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int maxN = 404;

bool dp[maxN][maxN][maxN];

int T;
string s, t;

inline bool can(int d){ //[0, d) is first, [d, len) is second
    dp[0][0][0] = true;
    for(int i = 1; i <= s.length(); i++){
        for(int j = 0; j <= d; j++){
            for(int k = 0; k <= t.length() - d; k++){
                dp[i][j][k] = false;
                if(dp[i - 1][j][k]){
                    dp[i][j][k] = dp[i - 1][j][k];
                    continue;
                }
                if(j && (s[i - 1] == t[j - 1])) dp[i][j][k] |= dp[i - 1][j - 1][k];
                if(k && (s[i - 1] == t[k + d - 1])) dp[i][j][k] |= dp[i - 1][j][k - 1];
            }
        }
    }
    /*
    for(int i = 1; i <= s.length(); i++){
        cout << "i = " << i << endl;
        for(int j = 0; j <= d; j++){
            for(int k = 0; k <= t.length() - d; k++){
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
    }
    */
    return dp[s.length()][d][t.length() - d];
}

int main(){
    cin >> T;
    while(T--){
        cin >> s >> t;
        bool f = false;
        for(int d = 1; d <= t.length(); d++){
            if(can(d)){
                cout << "YES\n";
                f = true;
                break;
            }
        }
        if(!f) cout << "NO\n";
    }
}
