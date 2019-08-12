#include <iostream>
#include <algorithm>
using namespace std;

long long int n;
const long long int MAX = 690000;
int main(){
    long long int sum[MAX], _sum = 0, ans[MAX], currentLim = 1;
    ans[1] = 1;
    ans[2] = 2;
    for(int i = 2; currentLim < MAX; i++){
        for(int j = 0; j < ans[i] && currentLim < MAX; j++){
            ans[++currentLim] = i;
        }
    }
    for(int i = 1; i < MAX; i++){
        //printf("f(%5d) = %d\n", i, ans[i]);
        _sum += ans[i];
        sum[i] = _sum;
    }
    while(scanf("%lld", &n)){
        if(!n) return 0;
        printf("%d\n", (int)(lower_bound(sum, sum + MAX, n) - sum));
    }
}
