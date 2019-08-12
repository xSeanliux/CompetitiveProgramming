#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;
int N, a, b, k, dp[2005][2005];

inline int add(int a, int b){
    if(a + b >= MOD) return a + b - MOD;
    else return a + b;
}

inline int sub(int a, int b){
    if(a - b < 0) return a - b + MOD;
    else return a - b;
}

int main(){
    cin >> N >> a >> b >> k;
    for(int i = 0; i <= k; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = (!i && j == a);
        }
    }
    /*
    for(int i = 1; i <= N; i++){
        cout << dp[0][i] << " ";
    }
    */
    //cout << endl;
    for(int i = 0; i < k; i++){
        for(int j = 1; j <= N; j++){
            if(j == b) continue;
            if(j < b){
                dp[i + 1][b] = sub(dp[i + 1][b], dp[i][j]);
                dp[i + 1][max(1, j - (b - j) + 1)] = add(dp[i + 1][max(1, j - (b - j) + 1)], dp[i][j]);
            } else if(j > b){
                dp[i + 1][b + 1] = add(dp[i + 1][b + 1], dp[i][j]);
                dp[i + 1][min(N + 1, j + (j - b))] = sub(dp[i + 1][min(N + 1, j + (j - b))], dp[i][j]);
            }

            dp[i + 1][j] = sub(dp[i + 1][j], dp[i][j]);
            dp[i + 1][j + 1] = add(dp[i + 1][j + 1], dp[i][j]);
        }

        //cout << dp[i + 1][1] << " ";
        for(int j = 2; j <= N; j++){
            dp[i + 1][j] = add(dp[i + 1][j], dp[i + 1][j - 1]);
        //    cout << dp[i+1][j] << " ";
        }

    }
    int ans = 0;
    for(int j = 1; j <= N; j++){
        ans = add(ans, dp[k][j]);
    }
    cout << ans << endl;

}
