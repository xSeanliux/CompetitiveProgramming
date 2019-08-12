#include <iostream>
#define int long long int
using namespace std;

const int maxN = 5000;
bool isAll1 = true;
const int INF = 0xdefaced;
int N, K;
int freq[maxN + 10], dp[maxN + 10], p[maxN + 10], arr[maxN + 10];

signed main(){
    cin >> N >> K;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    for(int i = 1; i <= N; i++) cin >> p[i];
    for(int i = 1; i <= K; i++){
        dp[i] = 0;
    }
    int maxAns;
    for(int i = K + 1; i <= N; i++){
        maxAns = -1e15;
        int currentAns = 0;
        fill(freq, freq + N + 1, 0);
        for(int j = i; j >= 1; j--){
            freq[arr[j]]++;
            if(freq[arr[j]] == K){
                currentAns += p[arr[j]];
            }
            maxAns = max(maxAns, dp[j - 1] + currentAns);
        }
        dp[i] = maxAns;

        //cout << "DP[" << i << "] = " << dp[i] << endl;
    }
    cout << dp[N] << endl;
}
