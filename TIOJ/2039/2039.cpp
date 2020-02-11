#include <iostream>
#include <utility>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int MAXN = 2e6;
int N, K, arr[MAXN + 5], f[MAXN + 5], dp[MAXN + 5][2];

void alien(int C){ //return k, dp[n] is the actual value.
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            dp[i][j] = 0;
        }
    }
    int cm = arr[1] + C, from = 1;
    for(int i = 2; i <= N; i++){
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        if(dp[i][0] <= arr[i] - cm){
            dp[i][0] = arr[i] - cm;
            dp[i][1] = dp[from][1] + 1;
        }
        if(arr[i] + C - dp[i - 1][0] < cm){
            cm = arr[i] + C - dp[i - 1][0];
            from = i - 1;
        }
        //cout << "dp[" << i << "][0] = " << dp[i][0] << endl;
        //cout << "dp[" << i << "][1] = " << dp[i][1] << endl;
    }
}


signed main(){
    ericxiao;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    int UP = 1e8, LP = 0, MP = (UP + LP) / 2;
    while(LP + 1 < UP){
        alien(MP);
        //cout << "MP = " << MP << endl;
        //cout << "Answer is " << dp[N][0] << " with " << dp[N][1] << " transactions" << endl;
        if(dp[N][1] > K){
            LP = MP;
        } else {
            UP = MP;
        }
        MP = (UP + LP) / 2;
    }
    alien(UP);
    //cout << "UP = " << UP << endl;
    cout << max(0LL, dp[N][0] + UP * dp[N][1]) << endl;
}
