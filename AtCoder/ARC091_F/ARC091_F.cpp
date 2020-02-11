#include <iostream>
#define int long long int
using namespace std;

int n, x, k, SG = 0;

signed main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> k;
        SG ^= ((x % k) + (x/k)) % (x/k + 1);
    }
    if(!SG){
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
}
