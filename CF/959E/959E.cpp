#include <iostream>
#define int unsigned long long int
using namespace std;

signed main(){
    int n, ans = 0, wei = 1;
    cin >> n;
    while(n > 1){
        ans += n/2 * wei;
        n = (n + 1) / 2;
        wei <<= 1;
    }
    cout << ans << endl;
    //n -> (n + 1) / 2, connecting n/2 edges
}
