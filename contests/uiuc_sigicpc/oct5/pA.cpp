#include <iostream>
#define int long long int
using namespace std;

int k, n, w;

signed main(){
    cin >> k >> n >> w;
    cout << max(0LL, w * (w + 1) / 2 * k - n) << endl;
}
