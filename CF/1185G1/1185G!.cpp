#include <iostream>
using namespace std;

const int maxN = 15, MOD = 1e9 + 7;
int N, T, t, g, dp[(1LL << maxN) + 10][3];

struct Song{
    int time, gen;
    Song(){}
    Song(int t, int g): time(t), gen(g){}
} songs[maxN + 10];

bool hasbit(int x, int l){
    return (x & (1LL << l)) > 0;
}

int flipbit(int x, int l){
    return x ^ (1LL << l);
}

int main(){
    cin >> N >> T;
    for(int i = 0; i < N; i++){
        cin >> t >> g;
        g--;
        songs[i] = Song(t, g);
    }
    int ans = 0, dur;
    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    for(int i = 1; i < (1LL << N); i++){
        dur = 0;
        dp[i][0] = dp[i][1] = dp[i][2] = 0;
        for(int j = 0; j < N; j++){
            if(hasbit(i, j)){
                if(i == (1LL << j)){
                    dp[i][ songs[j].gen ] = 1;
                }
                dur += songs[j].time;
                for(int k = 0; k < 3; k++){
                    if(k == songs[j].gen) continue;
                    dp[i][songs[j].gen] = (dp[i][songs[j].gen] + dp[ flipbit(i, j) ][k]) % MOD;
                }
            }
        }
        if(dur == T){
            ans = (ans + dp[i][0] + dp[i][1] + dp[i][2]) % MOD;
        }
    }
    cout << ans << endl;
}
