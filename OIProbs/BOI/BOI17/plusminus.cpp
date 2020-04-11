#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e5 + 10, MOD = 1e9 + 7;

map<int, bool> mp;
map<int, vector<pii> > xes;
int N, M, K, y, x;
char c;
bool b;

inline int mpow(int b, int e){
    int r = 1, c = b;
    for(int i = 0; i < 30; i++){
        if((e >> i) & 1) r = r * c % MOD;
        c = c * c % MOD;
    }
    return r;
}

int pmchoices(int y){
    //cout << "Checking if " << y << " is valid" << endl;
    if(!xes.count(y)) return 2;
    vector<pii> v = xes[y];
    for(pii p : v){
        //cout << " Coord of " << p.F << " with coord " << p.S << endl;
        if(((p.F - v[0].F) & 1) != (p.S ^ v[0].S)) return 0;
    }
    return 1;
}

int pmF(){
    if(!mp.size()) return 2;
    vector<pii> v;
    for(auto p : mp) v.push_back(p);
    for(pii p : v){
        if(((p.F - v[0].F) & 1) != (p.S ^ v[0].S)) return 0;
    }
    return 1;
}

signed main(){
    cin >> N >> M >> K;
    bool f = true;
    for(int i = 0; i < K; i++){
        cin >> c >> y >> x;
        b = (c == '+');
        b ^= (y & 1);
        if(mp.count(x) && mp[x] != b){
            f = false;
        }
        mp[x] = b;
        if(!xes.count(y)) xes[y] = vector<pii>();
        xes[y].emplace_back(x, (c == '+'));
    }

    int ans = mpow(2, M - mp.size()) * f;
    //cout  << "All: " << ans << endl;
    for(auto &p : xes){
        sort(p.S.begin(), p.S.end());
    }

    if(f) ans -= pmF();
    //cout << ans << " choices of start that is unique" << endl;
    int _a = mpow(2, N - xes.size());
    for(auto p : xes) _a = _a * pmchoices(p.F) % MOD;
    ans = (ans + _a) % MOD;
    cout << ans << endl;
}
