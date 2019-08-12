#include <iostream>
#include <utility>
#define lld long long int
using namespace std;

const int MAXN = 2000000;
int N, K, arr[MAXN + 5], f[MAXN + 5], dp[MAXN + 5];

lld alien(int C){ //return k, dp[n] is the actual value.
    dp[0] = 0; dp[1] = 0; dp[2] = max(0, dp[2] - dp[1]);
    for(int i = 3; i <= N; i++){

    }
}


int main(){
    while(cin >> N >> K){
        for(int i = 1; i <= N; i++) cin >> arr[i];
        int UP = 2e8, LP = 0, MP;
        while(UP > LP + 1){

        }
    }
}
