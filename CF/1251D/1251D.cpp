#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<pii> segs;

int t, n, s, l, r, m;

inline bool check(int cost){
    static vector<pii> sm, bg;
    sm.clear();
    bg.clear();
    for(pii p : segs){
        (p.S < cost ? sm : bg).push_back(p);
    }
    int sum = 0, cnt = sm.size();
    if(sm.size() > n/2) return false;
    for(pii p : sm) sum += p.F;
    sort(bg.begin(), bg.end());
    for(pii p : bg){
        if(cnt < n/2){
            if(p.F > cost) return false;
            sum += min(p.F, cost);
            cnt++;
        } else {
            sum += max(p.F, cost);
        }
    }
    return sum <= s;

}

signed main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> n >> s;
        segs.resize(n);
        for(int i = 0; i < n; ++i){
            cin >> segs[i].F >> segs[i].S;
        }
        sort(segs.begin(), segs.end());
        l = segs[n/2].F, r = 1e9 + 22625, m = (l + r) / 2;
        while(l + 1 < r){
            if(check(m)) l = m;
            else r = m;
            m = (l + r) / 2;
        }
        cout << l << '\n';
    }
}
