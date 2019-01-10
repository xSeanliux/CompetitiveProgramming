#include <iostream>
using namespace std;

int denoms[11] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
unsigned long long int dp[30005];
double N;

void getTable(){
    dp[0] = 1;
    dp[5] = 1;
    for(int i = 10 ; i <= 30000; i += 5){
        for(int j = 0; j < 11; j++){
            if(denoms[j] <= i){
                dp[i] += dp[i - denoms[j]];
            }
            cout << "dp["<<i<<"] = " << dp[i] << endl;
        }
    }
}


int main(){
    getTable();
    while(cin >> N){
        N *= 100;
        cout << dp[(int)N] << endl;
    }
}
