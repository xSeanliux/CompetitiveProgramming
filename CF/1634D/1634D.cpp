#include <iostream>
using namespace std;

inline void solve() {
    int N;
    cin >> N;
    int bestAt = 3, bestVal = -1, k;
    for(int i = 3; i <= N; i++) {
        cout << "? 1 2 " << i << endl; 
        cin >> k;
        if(k > bestVal) {
            bestVal = k;
            bestAt = i;
        }
    }
    int range = -1, othBest = 1;
    for(int i = 1; i <= N; i++) {
        if(i == 2 || i == bestAt) continue;
        cout << "? 2 " << bestAt << " " << i << endl;
        cin >> k;
        if(k > range) {
            range = k;
            othBest = i;
        }
    }
    //ans is either 2, bestAt, or othBest
    for(int i = 1; i <= N; i++) {
        if(i != 2 && i != bestAt && i != othBest) {
            cout << "? 2 " << bestAt << " " << i << endl;
            cin >> k;
            if(k == range) {
                cout << "! 2 " << bestAt << endl;
                return;
            }
            cout << "? 2 " << othBest << " " << i << endl;
            cin >> k;
            if(k == range) {
                cout << "! 2 " << othBest << endl;
                return;
            }
            cout << "! " << othBest << " " << bestAt << endl;
            return;
        }
    }
}


int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
