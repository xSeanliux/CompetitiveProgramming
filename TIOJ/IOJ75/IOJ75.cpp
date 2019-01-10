#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;

string A, B;

int main(){
    cin >> A >> B;
    int lA = A.length(), lB = B.length();
    int dp[lA + 2][lB + 2];
    for(int i = 0; i <= lA; i++){
        dp[i][0] = i;
    }
    for(int i = 0; i <= lB; i++){
        dp[0][i] = i;
    }
    for(int i = 1; i <= lA; i++){
        for(int j = 1; j <= lB; j++){
            if(A[i-1] == B[j-1]){
                dp[i][j] = dp[i-1][j-1];
            } else {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }
    printf("%d\n", dp[lA][lB]);
}
