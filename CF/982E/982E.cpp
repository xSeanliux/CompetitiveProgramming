#include <iostream>
#define int long long int
using namespace std;

int n, m, sx, sy, vx, vy;

inline int extgcd(int a, int b, int &x, int &y){
    if(!b){
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a % b, x, y);
    //b * x + (a - b * (a / b)) * y = d
    int _x = y;
    int _y = x - (a / b) * y;
    x = _x;
    y = _y;
    return d;
}

inline int crt(int a1, int m1, int a2, int m2){
    a1 = (a1 + m1) % m1;
    a2 = (a2 + m2) % m2;
    if(a1 > a2){
        swap(a1, a2);
        swap(m1, m2);
    }
    //t === a1 mod m1
    //t === a2 mod m2
    //m1 * x + a1 = m2 * y + a2
    //m1 * x + m2 * (-y) = a2 - a1
    int x, y;
    int d = extgcd(m1, m2, x, y);

    if((a2 - a1) % d) return -1;
    x *= (a2 - a1) / d;
    y *= -(a2 - a1) / d;
    /*
    cout << " A solution is " << m1 * x + a1 << endl;
    cout << " or solution is " << m2 * y + a2 << endl;
    cout << m1 * x + a1 << " = " << a1 << " mod " << m1 << endl;
    cout << m1 * x + a1 << " = " << a2 << " mod " << m2 << endl;
    cout << m1 << "*" << x << " - " << m2 << "*" << y << " = " << a2 - a1 << endl;
    */
    x = (x - (x / (m2 / d)) * m2 / d + m2 / d) % (m2 / d);
    return m1 * x + a1;

    //m1 * x - m2 * (y) = a2 - a1
    //k = m2 / d
    //m1 * (x - (m2/d) * t) - m2 * (y + (m1/d) * t)
    //t = m1 * x + a1
}

signed main(){
    cin >> n >> m >> sx >> sy >> vx >> vy;
    if((sx == 0 && sy == 0) || (sx == 0 && sy == m) || (sx == n && sy == 0) || (sx == n && sy == m)){
        cout << sx << " " << sy << endl;
        return 0;
    }
    if(!vx){
        if(sx == 0){
            if(vy == 1){
                cout << "0 " << m << endl;
            } else {
                cout << "0 0\n" << endl;
            }
        } else if(sx == n){
            if(vy == 1){
                cout << n << " " << m << endl;
            } else {
                cout << n << " " << 0 << endl;
            }
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    if(!vy){
        if(sy == 0){
            if(vx == 1){
                cout << n << " 0" << endl;
            } else {
                cout << "0 0\n" << endl;
            }
        } else if(sy == m){
            if(vx == 1){
                cout << n << " " << m << endl;
            } else {
                cout << "0 " << m << endl;
            }
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    int T = crt(n -vx*sx, n, m -vy*sy, m);
    if(T == -1){
        cout << -1 << endl;
        return 0;
    }
    int X = sx + T * vx;
    int Y = sy + T * vy;
    //cout << "T = " << T << endl;
    X = (X < 0 ? -X : X);
    Y = (Y < 0 ? -Y : Y);
    cout << ((X / n) & 1) * n << " " << ((Y / m) & 1) * m << endl;
}
