#include <iostream>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1504, INF = 2e9;
const long long int LLINF = 1e10;
int N, M, K, arr[maxN][maxN], pre[maxN][maxN], dp1[maxN][maxN], revDp1[maxN][maxN];
long long int revDp2[maxN][maxN], dp2[maxN][maxN], preV[maxN], preH;

inline long long int run(){
    for(int i = 0; i <= N + 1; i++) for(int j = 0; j <= M + 1; j++){
        if(i && j) pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + arr[i][j];
        dp1[i][j] = revDp1[i][j] = -INF;
        dp2[i][j] = revDp2[i][j] = -LLINF;
    }
    fill(preV, preV + M + 1, -LLINF);
    for(int i = K; i <= N; i++){
        preH = -LLINF;
        for(int j = K; j <= M; j++){
            dp1[i][j] = max(dp1[i - 1][j], dp1[i][j - 1]);
            dp2[i][j] = max(dp2[i - 1][j], dp2[i][j - 1]);
            dp1[i][j] = max(dp1[i][j], (pre[i][j] - pre[i][j - K] - pre[i - K][j] + pre[i - K][j - K]));
            dp2[i][j] = max(dp2[i][j], (long long int)(pre[i][j] - pre[i][j - K] - pre[i - K][j] + pre[i - K][j - K]) + (long long int)(max(dp1[i - K][j], dp1[i][j - K])));
            preH = max(preH, (long long int)(pre[i][j] - pre[i][j - K] - pre[i - K][j] + pre[i - K][j - K]));
            preV[j] = max(preV[j], (long long int)(pre[i][j] - pre[i][j - K] - pre[i - K][j] + pre[i - K][j - K]));
            dp2[i][j] = max(dp2[i][j], preH    + dp1[i - K][j]);
            dp2[i][j] = max(dp2[i][j], preV[j] + dp1[i][j - K]);
        }
    }
    fill(preV, preV + M + 1, -LLINF);
    for(int i = N - K + 1; i; i--){
        preH = -LLINF;
        for(int j = M - K + 1; j; j--){
            revDp1[i][j] = max(revDp1[i + 1][j], revDp1[i][j + 1]);
            revDp2[i][j] = max(revDp2[i + 1][j], revDp2[i][j + 1]);
            revDp1[i][j] = max(revDp1[i][j], (pre[i - 1][j - 1] - pre[i - 1][j + K - 1] - pre[i + K - 1][j - 1] + pre[i + K - 1][j + K - 1]));
            revDp2[i][j] = max(revDp2[i][j], (long long int)(pre[i - 1][j - 1] - pre[i - 1][j + K - 1] - pre[i + K - 1][j - 1] + pre[i + K - 1][j + K - 1]) + (long long int)(max(revDp1[i + K][j], revDp1[i][j + K])));
            preH = max(preH, (long long int)(pre[i - 1][j - 1] - pre[i - 1][j + K - 1] - pre[i + K - 1][j - 1] + pre[i + K - 1][j + K - 1]));
            preV[j] = max(preV[j], (long long int)(pre[i - 1][j - 1] - pre[i - 1][j + K - 1] - pre[i + K - 1][j - 1] + pre[i + K - 1][j + K - 1]));
            revDp2[i][j] = max(revDp2[i][j], preH    + revDp1[i + K][j]);
            revDp2[i][j] = max(revDp2[i][j], preV[j] + revDp1[i][j + K]);

        }
    }
    long long int res = -LLINF;
    /*
    for(int i = K; i <= N; i++) for(int j = K; j <= M; j++) cout << dp[i][j][1] << " \n"[j == M];
    cout << endl;
    for(int i = 1; i <= N - K + 1; i++) for(int j = 1; j <= M - K + 1; j++) cout << revDp[i][j][1] << " \n"[j == M - K + 1];
    cout << endl;
    */
    for(int i = K; i < N - K + 1; i++){
        res = max(res, (long long int)dp1[i][M] + (long long int)revDp2[i + 1][1]);
        res = max(res, (long long int)dp2[i][M] + (long long int)revDp1[i + 1][1]);
    }
    return res;
}

signed main(){
    ericxiao;
    cin >> N >> M >> K;
    for(int i = 1; i <= N; i++) for(int j = 1; j <= M; j++){
        cin >> arr[i][j]; 
    }
    long long int ans = run(), L = max(N, M);
    for(int i = 1; i <= L; i++) for(int j = 1; j < i; j++) swap(arr[i][j], arr[j][i]);
    swap(N, M);
    ans = max(ans, run());
    cout << ans << endl;
}
