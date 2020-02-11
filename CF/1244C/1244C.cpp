#include <iostream>
#define int long long int
using namespace std;

int n, p, w, d, x, y, z;

signed main(){
    cin >> n >> p >> w >> d;
    for(x = p/w; x >= max((int)(-1), p/w - d - 1); x--){
        if(x * w % d == p % d) break;
    }
    if(x < max((int)(-1), p/w - d - 1)){
        cout << -1 << endl;
        return 0;
    }
    y = (p - w * x) / d;
    if(x + y > n || (x == d && d > 1)){
        cout << -1 << endl;
        return 0;
    }
    cout << x << " " << y << " " << n - x - y << endl;
}
