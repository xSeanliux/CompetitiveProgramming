#include <iostream>
using namespace std;

const int maxN = 1e6 + 326, MOD = 1e9 + 7;

inline int add(int a, int b){
    return (a + b >= MOD ? a + b - MOD : a + b);
}

int dp[maxN];

int main(){
    int N, x, c;
    dp[0] = 1;
    cin >> N >> x;
    while(N--){
        cin >> c;
        for(int i = c; i <= x; i++) dp[i] = add(dp[i], dp[i - c]);
    }
    cout << dp[x] << endl;
}
