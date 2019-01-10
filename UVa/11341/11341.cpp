#include <iostream>
using namespace std;

int T, H, W;

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &H, &W);
        int dp[H + 1][W + 1];
        for(int i = 0; i <= H; i++){
            for(int j = 0; j <= W; j++){
                dp[i][j] = 0;
            }
        }
        double ans = 0;
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                int cg;
                scanf("%d", &cg);
                for(int w = W; cg >= 5 && w >= j; w--){
                    if((j == w && i == 1) || dp[i - 1][w - j]){
                        dp[i][w] = max(dp[i][w], dp[i - 1][w - j] + cg); //if I use the current grade just inputted
                    }
                    if(i == H && dp[i][w] > ans) ans = dp[i][w];
                }
            }
        }
        if(ans){
            printf("Maximal possible average mark - %.2f.\n", (ans + 1e-9)/(H));
        } else {
            printf("Peter, you shouldn't have played billiard that much.\n");
        }
    }
}
