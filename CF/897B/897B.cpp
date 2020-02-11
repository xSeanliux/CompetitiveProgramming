#include <iostream>
#include <string.h>
#include <algorithm>
#define int long long int
using namespace std;

int k, p;

signed main(){
    string s, ns;
    cin >> k >> p;
    int ans = 0, cur;
    for(int i = 1; i <= k; i++){
        s = to_string(i);
        ns = s;
        reverse(ns.begin(), ns.end());
        s = s + ns;
        cur = stoll(s);
        ans = (ans + cur % p) % p;
    }
    cout << ans << endl;
}
