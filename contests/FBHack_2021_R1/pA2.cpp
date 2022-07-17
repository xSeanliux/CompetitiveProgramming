#include <iostream>
#include <string.h>
#define int long long int
using namespace std;

const int M = 1e9 + 7;

inline int add(int a, int b){
    return (a + b >= M ? a + b - M : a + b);
}
inline void solve(int tc){
    int N;
    string s;
    cin >> N >> s;
    int last = -1, lastType = 0, ans = 0;
    for(int i = 0; i < N; i++){
        char c = s[i];
        if(c == 'O'){
            if(lastType == 2) ans = add(ans, (N - i) * (last + 1) % M);
            last = i;
            lastType = 1;
        } else if(c == 'X'){
            if(lastType == 1) ans = add(ans, (N - i) * (last + 1) % M);
            last = i;
            lastType = 2;
        }
        //cout << "i = " << i << ", ans = " << ans << endl;
    }
    cout << "Case #" << tc << ": " << ans << endl;
}

signed main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++){
        solve(i);
    }
}

