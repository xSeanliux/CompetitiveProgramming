#include <iostream>
using namespace std;

inline int ceil(int a, int b){
    return (a + b - 1) / b;
}

int t, a, b, c, d, k, x, y;

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c >> d >> k;
        x = ceil(a, c);
        y = ceil(b, d);
        if(x + y > k) cout << -1 << endl;
        else cout << x << " " << y << endl;
    }
}
