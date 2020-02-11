#include <iostream>
#include <math.h>
#define int long long int
using namespace std;

int T, a, b;

signed main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        if(a < b) swap(a, b);
        int t = a - b;
        int k = floor((sqrt(1 + 8 * t) - 1) / 2);
        //cout << "k = " << k << endl;
        for(;; k++){
            if(k*(k + 1) / 2 - t >= 0 && !((k*(k + 1) / 2 - t) % 2)){
                cout << k << endl;
                break;
            }
        }
    }
}
