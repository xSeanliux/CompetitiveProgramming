#include <iostream>
#include <string.h>
#define int long long int
using namespace std;
string s;

int MOD = 1e9 + 7;

signed main(){
    cin >> s;
    int ans = 0, bs = 0;
    for(int i = s.length() - 1; i >= 0; i--){
        if(s[i] == 'b') bs++;
        if(s[i] == 'a' && bs){
            ans += bs;
            if(ans >= MOD) ans -= MOD;
            bs *= 2;
        }
        if(bs >= MOD) bs -= MOD;
    }
    cout << ans << endl;
}
