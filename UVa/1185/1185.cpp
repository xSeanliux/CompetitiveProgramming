#include <iostream>
#include <math.h>
using namespace std;

int T, n, currentPoint;
long double ans[10000006];

int main(){
    scanf("%d", &T);
    ans[1] = 0;
    currentPoint = 1;
    while(T--){
        scanf("%d", &n);
        if(currentPoint < n){
            currentPoint++;
            for(;currentPoint <= n; currentPoint++){
                ans[currentPoint] = ans[currentPoint-1] + log10(currentPoint);
            }
            currentPoint--;
        }
        printf("%d\n", (int)(floor(ans[n]) + 1));
    }
}
