#include <iostream>
#include <map>
#include <algorithm>
#include <deque>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

int q, n, x, k;

inline int Abs(int x){
    return (x < 0 ? -x : x);
}

void solve(){
    cin >> n >> k;
    vector<int> v;
    map<int, int> frq;
    deque<pii> dq;
    for(int i = 0; i < n; i++){
        cin >> x;
        v.push_back(x);
        frq[x]++;
    }
    sort(v.begin(), v.end());
    int m = v[n / 2], __ans = 0;
    for(int i = 0; i < n; i++){
        __ans += Abs(v[i] - m);
    }
    for(auto p : frq){
        //cout << "Pushing " << p.F << ", " << p.S << endl;
        if(p.S >= k){
            cout << 0 << endl;
            return;
        }
        dq.push_back(p);
    }
    int ans = 0, _ans = 0, t, sum = 0;
    for(auto p : dq){
        sum += p.S;
        if(sum >= k){
            t = p.F;
            break;
        }
    }
    //cout << "First: t = " << t << endl;
    for(auto p : dq){
        if(p.F == t) break;
        ans += (t - p.F) * p.S;
    }
    //cout << "ans = " << ans << endl;
    reverse(dq.begin(), dq.end());
    _ans = 0, sum = 0;
    for(auto p : dq){
        //cout << "Looking at " << p.F << ", " << p.S << endl;
        sum += p.S;

        cout << "Sum = " << sum << endl;
        if(sum >= k){
            t = p.F;
            break;
        }
    }
    cout << "Second: t = " << t << endl;
    for(auto p : dq){
        if(p.F == t) break;
        _ans += (p.F - t) * p.S;
    }
    cout << min(_ans, min(ans, __ans)) << endl;
}

signed main(){
    solve();
}
