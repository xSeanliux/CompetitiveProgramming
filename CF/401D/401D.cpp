#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

string s;
int m, N, frq[10];

int flipbit(int x, int l){
    return (x ^ (1LL << l));
}

bool hasbit(int x, int l){
    return (x & (1LL << l)) > 0;
}

signed main(){
    cin >> s >> m;
    for(int i = 0; i < 10; i++) frq[i] = 0;
    for(char c : s){
        frq[c - '0']++;
    }
    N = s.length();
    int dp[(1LL << N) + 10][m];
    for(int i = 0; i < m; i++) dp[0][i] = 0;

    dp[0][0] = 1;
    for(int i = 1; i < (1LL << N); i++){
        for(int j = 0; j < m; j++) dp[i][j] = 0;
        //cout << "i = " << i << endl;
        for(int j = 0; j < N; j++){
            if(hasbit(i, j)){
                if((1LL << j) == i && s[j] == '0') continue;
                //cout << "HASBIT: " << j << endl;
                for(int k = 0; k < m; k++){
                    dp[i][ (k * 10 + (s[j] - '0')) % m  ] += dp[ flipbit(i, j) ][k];
                }
            }
        }
    }
    int ans = dp[(1LL << N) - 1][0];
    for(int j = 0; j < 10; j++){
        for(int k = 2; k <= frq[j]; k++){
            ans /= k;
        }
    }
    cout <<  ans << endl;
}
