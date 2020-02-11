#include <iostream>
#include <math.h>
#define int unsigned long long int
using namespace std;

int n, H, range = (int)1e7;

inline int cei(int x, int m){
    return (x + m - 1) / m;
}

signed main(){
    cin >> n >> H;
    int z = min(H, 1 + (int)sqrt(1 + 8 * n) / 2);
    int ubound = min(H, z + range);
    int lbound = 1;
    if(z > range) lbound = z - range;
    int ans = n;
    for(int k = lbound; k <= ubound; k++){
        ans = min(ans, k + cei(n - k * (k + 1) / 2, k));
    }
    cout << ans << endl;
}
