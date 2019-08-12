#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, m, q, e1, s1, e2, s2, z1, z2;

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

signed main(){
    ericxiao;
    cin >> n >> m >> q;
    int g = gcd(n, m);
    //cout << "g = " << g << endl;
    while(q--){
        cin >> s1 >> e1 >> s2 >> e2;
        e1--;
        e2--;
        if(s1 == 1){
            z1 = e1 / (n / g);
        } else {
            z1 = e1 / (m / g);
        }
        if(s2 == 1){
            z2 = e2 / (n / g);
        } else {
            z2 = e2 / (m / g);
        }
        //cout << "z1 = " << z1 << ", z2 = " << z2 << endl;
        cout << ((z1 == z2) ? "YES" : "NO") << endl;
    }
}
