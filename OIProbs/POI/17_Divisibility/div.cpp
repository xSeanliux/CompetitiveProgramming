#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e6 + 26;

int B, q, a[maxN], x, ds;

struct Obj{
    int dig;
    pii pos;
    Obj(){}
    Obj(int d, int l, int r){
        dig = d;
        pos = {l, r};
    }
    const bool operator<(const int &x) const {
        return pos.S <= x;
    }
};

vector<Obj> objs;

signed main(){
    cin >> B >> q;
    for(int i = 0; i < B; i++){
        cin >> a[i];
        ds = (ds + a[i] * i % (B - 1)) % (B - 1);
    }
    if(ds) a[ds]--;
    int cur = 0;
    for(int i = 0; i < B; i++){
        if(a[i]){
            objs.emplace_back(i, cur, cur + a[i]);
            //cout << cur << " to " << cur + a[i] << " has dig " << i << endl;
            cur += a[i];
        }
    }
    while(q--){
        cin >> x;
        if(cur <= x){
            cout << -1 << endl;
            continue;
        }
        auto r = *lower_bound(objs.begin(), objs.end(), x);
        cout << r.dig << endl;
    }
}
