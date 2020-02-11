#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> pos, neg, abso, tmp;

int n, t, ans = 0, res;

inline int Abs(int x){
    return (x > 0) ? x : -x;
}

signed main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t;
        if(!t) continue;
        abso.push_back(t);
    }
    sort(abso.begin(), abso.end(), [](const int a, const int b){
        return Abs(a) < Abs(b);
    });
    tmp.clear();

    for(int x : abso){
        x = Abs(x);
        auto pt1 = lower_bound(tmp.begin(), tmp.end(), x);
        res = tmp.end() - pt1;
        //cout << "There are " << res << " numbers with abs value >= " << Abs(x) << endl;
        ans += res;
        tmp.push_back(2 * x);
    }
    cout << ans << endl;
}
