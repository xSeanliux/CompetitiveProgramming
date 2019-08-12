#include <iostream>
#include <iomanip>
#define int unsigned long long int
using namespace std;

int cei(int a, int b){
    return (a % b == 0 ? a/b : a/b + 1);
}

int k, d, t;

signed main(){
    cout << fixed << setprecision(0);
    cin >> k >> d >> t;
    t = t << 1;
    //cout << "Need t = " << t << " to cook " << endl;
    d = cei(k, d) * d; //d >= k;, every d minutes it cycles
    //cout << "Cycle len = " << d << endl;
    int gongxian = (k + d); //k + 0.5*(d - k)
    //cout << "Every cycle, hot: " << gongxian << endl;
    int T = 0;
    bool need = false;
    T = t/gongxian * d;
    t %= gongxian;
    //cout << "Then " << t << endl;
    if(t >= 2 * k){
        t -= 2 * k;
        T += k; //hot
        T += t; //warm
        t = 0;
    } else {
        if(t % 2) need = true;
        T += t/2;
    }
    cout << T;
    if(need) cout << ".5" << endl;
    else cout << ".0" << endl;
}
