#include <iostream>
using namespace std;

unsigned long long int ans, n, c, a, b;

int main(){
    cin >> c;
    for(int i = 1 ; i <= c; i++){
        cin >> n;
        a = n+1;
        b = n+2;
        if(!(a % 3)) a/=3;
        if(!(b % 3)) b/=3;
        if(!(n%3)) n /=3;
        int ans = n%1000000007;
        printf("%llu\n", ans);
        ans *= a;
        ans %= 1000000007;
        printf("%llu\n", ans);
        ans *= b;
        ans %= 1000000007;
        printf("%llu\n", ans);
        printf("Case %d: %llu\n", i, ans);
    }
}
