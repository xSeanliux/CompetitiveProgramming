#include <iostream>
using namespace std;

int denoms[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
unsigned long long int dp[30005];
double N;

void getTable(){
    dp[0] = 1;
    //dp[5] = 1;
    for(int i = 0; i < 11; i++){
        for(int j = 5; j <= 30000; j+=5){
            if(denoms[i] <= j){
                dp[j] += dp[j - denoms[i]];
                //printf("dp[%d] += dp[%d], dp[%d] = %llu\n", j, j - denoms[i], j, dp[j]);
            }
        }
    }
}


int main(){
    getTable();
    while(cin >> N){
        if(!N) return 0;
        N *= 100;
        int ind = (int)(N);
        if(!((ind + 1) % 5)) ind++;
        else if(!((ind - 1) % 5)) ind--;
        //printf("dp[%ld] = %llu\n", (int)ind, dp[(int)ind]);
        printf("%6.2f%17llu\n", ind/100.0, dp[(int)ind]);
    }
}
