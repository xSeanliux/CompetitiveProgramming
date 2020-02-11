#include <iostream>
#define int long long int
using namespace std;

int t, n;

signed main(){
    cin >> t;
    while(t--){
        cin >> n;
        if(n < 15){
            cout << "NO" << endl;
            continue;
        }
        n %= 14;
        if(1 <= n && n <= 6) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}
