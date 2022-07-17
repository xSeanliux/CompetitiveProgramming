#include <iostream>
#include <math.h>
#include <iomanip>
#define int long long int
#define double long double
using namespace std;

const int maxN = 1e5 + 326;
const double eps = 1e-10; //change?
int N, x[maxN], y[maxN];

inline bool can(double r){
    //cout << "testing r = " << r << endl;
    double L = -1e9, R = 1e9, dx, dy;
    for(int i = 0; i < N; i++){
        dy = abs(r - y[i]);
        //cout << "dy = " << dy << ", r = " << r << endl;
        if(dy - r > -eps) return false;
        dx = sqrt(r * r - dy * dy);
        L = max(L, x[i] - dx);
        R = min(R, x[i] + dx);
        //cout << "i = " << i << endl;
        //cout << x[i] - dx << " " << x[i] + dx << endl;
        //cout << "L = " << L <<", R = " << R << endl;
    }
    return R - L >= -eps;
}

signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x[i] >> y[i];
    }
    for(int i = 1; i < N; i++){
        if(y[i] * y[0] < 0){
            cout << -1 << endl;
            return 0;
        }
    }
    if(y[0] < 0){
        for(int i = 0; i < N; i++) y[i] = -y[i];
    }
    double l = 0, r = 1e16, m;
    for(int i = 0; i < 200; i++){
        m = (l + r) / 2;
        if(can(m)) r = m;
        else l = m;
    }
    cout << fixed << setprecision(15) << m << endl;
}


