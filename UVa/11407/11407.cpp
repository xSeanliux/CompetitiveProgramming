#include <iostream>
#define MAX 10000
#define INF 2147483647
using namespace std;

int dp[MAX + 5], T, N;

void getdp(){
    for(int i = 0; i <= MAX; i++)
        dp[i] = INF;
    for(int i = 1; i <= 100; i++){
        dp[i * i] = 1;
        for(int j = i*i + 1; j <= MAX; j++){
            dp[j] = min(dp[j], dp[j-i*i] + 1);
        }
    }
}

int main(){
    getdp();
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        printf("%d\n", dp[N]);
    }
}
