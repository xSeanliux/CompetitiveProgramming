#include <iostream>
#include <functional>
#include <numeric>
using namespace std;

int ink[3][4], mins[4];

inline void solve(int t) {
    cout << "Case #" << t << ": ";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> ink[i][j];
            mins[j] = (i == 0) ? ink[i][j] : min(mins[j], ink[i][j]);
        }
    }
    int s = accumulate(mins, mins + 4, 0);
    if(s < 1e6) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    int left = 1e6;
    for(int i = 0; i < 4; i++) {
        int take = min(left, mins[i]); 
        cout << take << " ";
        left -= take;
    }
    cout << endl;
}
int main() {
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) solve(i);
}
