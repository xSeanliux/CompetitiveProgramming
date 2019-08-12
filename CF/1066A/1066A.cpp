#include <iostream>
#include <math.h>
#define int long long int
using namespace std;

int L, v, l, r, T;

signed main(){
    cin >> T;
    while(T--){
        cin >> L >> v >> l >> r;
        int trains = L/v, s, e;
        s = ceil(l*1.0/v);
        e = r/v;
        trains -= e - s + 1;
        cout << trains << endl;
    }

}
