#include <iostream>
#include <vector>
#include <algorithm>
#define int unsigned long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 2e18;

int n, q, l, r, ans;
vector<int> s, difpre, difsort;

signed main(){
    ericxiao;
    cin >> n;
    s.resize(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    sort(s.begin(), s.end());
    for(int i = 1; i < n; i++){
        difsort.push_back(s[i] - s[i - 1]);
    }
    difsort.push_back(INF);
    sort(difsort.begin(), difsort.end());
    difpre.push_back(difsort[0]);
    for(int i = 1; i < n - 1; i++){
        difpre.push_back(difsort[i] + difpre[i - 1]);
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        r -= l - 1;
        ans = 0;
        auto it = lower_bound(difsort.begin(), difsort.end(), r);
        if(it - difsort.begin()){
            //cout << "Left: " << difpre[it - difsort.begin() - 1]<< endl;
            ans += difpre[it - difsort.begin() - 1];
        }
        //cout << "Right: " << (difsort.end() - it) << endl;
        ans += r * (difsort.end() - it);
        cout << ans << endl;
    }
}

