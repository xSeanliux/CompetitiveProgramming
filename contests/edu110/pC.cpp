#include <iostream>
#include <deque>
#include <string.h>
#define int long long int
using namespace std;

inline void solve(){
    string s;
    cin >> s;
    int N = s.length();
    int ans = 0;
    deque<char> dq;
    for(int i = 0; i < N; i++){
        if(s[i] != '?'){
            s[i] = (char)(((s[i] - '0') ^ (i & 1)) + '0');
        }
    }
    int lO = -1, lZ = -1;
    for(int i = 0; i < N; i++){
        if(s[i] == '?'){
            ans += i - min(lO, lZ);
        } else if(s[i] == '0'){
            ans += i - lZ;
            lO = i;
        } else {
            ans += i - lO;
            lZ = i;
        }
    }
    cout << ans << endl;
}

signed main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}
