#include <iostream>
#include <string.h>
#include <set>
#include <math.h>
#include <vector>
#define int long long int
using namespace std;

int Q, n, k;

signed main(){
    cin >> Q;
    while(Q--){
        cin >> n >> k;
        int ans = 0;
        while(n){
            ans += n % k;
            n -= n % k;
            if(n){
                n /= k;
                ans++;
            }
        }
        cout << ans << endl;
    }
}
