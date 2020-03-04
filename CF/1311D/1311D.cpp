#include <iostream>
using namespace std;

const int INF = 1e9, maxN = 2e4 + 1;
int t, a, b, c;

inline int Abs(int x){
    return x < 0 ? -x : x;
}

inline void solve(){
    int minAns = INF, cans, mA, mB, mC, C;
    for(int m = 1; m < maxN; m++){
        cans = Abs(b - m);
        C = c / m * m;
        if(C < m || Abs(c - (c + m - 1) / m * m) < Abs(C - c)){
            C = (c + m - 1) / m * m;
        }
        cans += Abs(C - c);
        for(int j = 1; j * j <= m; j++){
            if(!(m % j)){
                if(minAns > cans + Abs(j - a)){
                    mA = j;
                    mB = m;
                    mC = C;
                    minAns = cans + Abs(j - a);
                }
                if(minAns > cans + Abs(m/j - a)){
                    mA = m/j;
                    mB = m;
                    mC = C;
                    minAns = cans + Abs(m/j - a);
                }
            }
        }
    }
    cout << minAns << "\n" << mA << " "<< mB << " " << mC << "\n";
}

int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c;
        solve();
    }
}
