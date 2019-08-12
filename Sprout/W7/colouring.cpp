#include <iostream>
using namespace std;

const int maxN = 1e5, MOD = 1e6 + 7;
int T, N, dp1[maxN + 10][3], dp2[maxN + 10][3]; //0, 1, 2: R, G, B;

void dp(){
    dp1[1][0] = dp1[1][1] = dp1[1][2] = 1;
    dp2[1][1] = 1;
    for(int i = 2; i <= maxN; i++){
        dp1[i][0] = (dp1[i-1][0] + dp1[i-1][1] + dp1[i-1][2]) % MOD;
        dp1[i][1] = (dp1[i-1][0] + dp1[i-1][1]) % MOD;
        dp1[i][2] = (dp1[i-1][0] + dp1[i-1][2]) % MOD;
        dp2[i][0] = (dp2[i-1][0] + dp2[i-1][1] + dp2[i-1][2]) % MOD;
        dp2[i][1] = (dp2[i-1][0] + dp2[i-1][1]) % MOD;
        dp2[i][2] = (dp2[i-1][0] + dp2[i-1][2]) % MOD;
    }
}


int main(){
    dp();
    cin >> T;
    while(T--){
        cin >> N;
        cout << (dp1[N][0] + dp1[N][1] + dp1[N][2] - 2 * dp2[N][2] + MOD * 10) % MOD << endl;
    }
}
