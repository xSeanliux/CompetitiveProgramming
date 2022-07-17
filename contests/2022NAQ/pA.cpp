#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

string s;

int exist[200];

inline int Abs(int x) {
    return x < 0 ? -x : x;
}

bool isAlien(int x) {
    string s = to_string(x);
    for(char c : s) if(exist[c - '0']) return false;
    return true;
}

signed main(){
    cin >> s;
    int N = stoll(s);
    for(char c : s) exist[c - '0'] = 1;
    
    vector<pii> vec;
    for(int l = 0; l < 10; l++) {
        if(exist[l]) continue;
        for(int d = 0; d < 10; d++) {
            if(exist[d]) continue;
            int num = l;
            for(int i = 0; i < 17; i++) {
                vec.emplace_back(Abs(num - N), num);
                num = num * 10 + d;
            }
        }
    }
    if(vec.empty()) {
        cout << "Impossible" << endl;
        return 0;
    }
    sort(vec.begin(), vec.end());
    auto [dist, ans] = vec[0];
    int oth = 2 * N - ans;
    if(isAlien(oth)) cout << min(ans, oth) << " " << max(ans, oth) << endl;
    else cout << ans << endl;
}
