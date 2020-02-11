#include <iostream>
#include <vector>
#define int long long int
using namespace std;

int Kp, Kx, n, t, x;

signed main(){
    cin >> t;
    while(t--){
        cin >> n;
        Kp = Kx = 0;
        for(int i = 0; i < n; i++){
            cin >> x;
            Kp += x;
            Kx ^= x;
        }
        cout << 2 << endl << Kx << " " << Kp + Kx << endl;
    }
}
