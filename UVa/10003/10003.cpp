#include <iostream>
#include <math.h>
#define INF 10000
using namespace std;

int len, sum, ncuts, cuts[69], dp[69][69];

void getDp(){
    for(int x = 2; x <= ncuts + 1; x++){
        for(int i = 0 ; i + x <= ncuts + 1; i++){
            int j = i + x;
            dp[i][j] = INF;
            for(int k = i + 1; k < j; k++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
            }
            //cout << "L: " << cuts[i] << ", R: " << cuts[j] << ", indexes (i, j) = (" << i << ", " << j << ") cost: " << dp[i][j] << endl;

        }

    }
}



int main(){
    while(cin >> len){
        if(!len) return 0;
        sum = 0;
        scanf("%d", &ncuts);
        cuts[0] = 0;
        for(int i = 1 ; i <= ncuts; i++){
            scanf("%d", &cuts[i]);
        }
        cuts[ncuts + 1] = len;
        getDp();
        printf("The minimum cutting is %d.\n", dp[0][ncuts+1]);
    }
}
