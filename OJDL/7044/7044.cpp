#include <iostream>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int m, q, a, s, t, d;

void extgcd(int a, int b, int &x, int &y, int &d){
    if(!b){
        x = 1;
        y = 0;
        d = a;
    } else {
        extgcd(b, a % b, x, y, d);
        int newX, newY;
        newX = y;
        newY = x - a/b * y;
        x = newX;
        y = newY;
    }
}

signed main(){
    ericxiao;
    cin >> m >> q;
    while(q--){
        cin >> a;
        extgcd(m, a, s, t, d);
        //ms + at = d
        if(d > 1){
            cout << "jizz" << endl;
            continue;
        }
        //ms + at = 1
        //t mod m
        t -= (t / m) * m;
        t = (t + m) % m;
        cout << t << endl;
    }
}
