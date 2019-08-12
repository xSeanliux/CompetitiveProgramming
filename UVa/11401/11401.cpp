#include <iostream>
using namespace std;

long long int ans = 0, n;

int main(){
    while(cin >> n){
        ans = 0;
        for(long long int i = 1; i <= n; i++){
            ans += max(0LL, (n - 2 * i) * (i - 1) + i * n - i * (2*n - i + 1)/2;
        }
        printf("%lld\n", ans);
    }
}
