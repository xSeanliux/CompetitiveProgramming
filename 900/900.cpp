#include <iostream>
using namespace std;

long long int dp[50 + 5], N;

void dpgo(){
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= 50; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int main(){
    dpgo();
    while(cin >> N){
        if(!N) return 0;
        cout << dp[N] << endl;
    }
}
