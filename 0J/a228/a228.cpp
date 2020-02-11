#include <iostream>
using namespace std;

const int maxN = 15, MOD = 1e9 + 7;

int dp[maxN][maxN][(1LL << maxN)], T, N, M, c = 0;
bool mp[maxN][maxN];

inline int add(int a, int b){
    return (a + b > MOD) ? a + b - MOD : a + b;
}

int DP(){
    int r, d;
    for(int i = 0; i <= N; i++) for(int j = 0; j <= M; j++) for(int k = 0; k < (1LL << (M + 1)); k++) dp[i][j][k] = 0;
    dp[0][M][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int S = 0; S < (1LL << (M)); S++) dp[i][0][(S << 1)] = dp[i - 1][M][S];
        for(int j = 1; j <= M; j++){
            for(int S = 0; S < (1LL << (M + 1)); S++){
                r = (1LL << (j));
                d = (1LL << (j - 1));
                if(mp[i][j]){
                    if((S & r) && (S & d)) dp[i][j][S] = dp[i][j - 1][S ^ r ^ d];
                    else if(!(S & r) && !(S & d)) dp[i][j][S] = dp[i][j - 1][S ^ r ^ d];
                    else dp[i][j][S] = add(dp[i][j - 1][S], dp[i][j - 1][S ^ r ^ d]);
                } else{
                    if(!(S & r) && !(S & d)) dp[i][j][S] = dp[i][j - 1][S];
                    else dp[i][j][S] = 0;
                }
            }
        }
    }
    return dp[N][M][0];
}

int main(){
    cin >> T;
    while(T--){
        cin >> N >> M;
        for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++) cin >> mp[i][j];
        cout << "Case " << ++c << ": " << DP() << endl;
    }
}
