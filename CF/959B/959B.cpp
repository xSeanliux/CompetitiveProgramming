#include <iostream>
#include <string.h>
#include <map>
#include <vector>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, INF = 1e10;

int n, k, m, dsu[maxN], cost[maxN], ans = 0, r, _minCost, t;
map<string, int> mp;
vector<int> ids;
string str;

void flat(int x){
    if(dsu[x] == x) return;

}

signed main(){
    ericxiao;
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++){
        cin >> str;
        mp[str] = i;
    }
    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 0; i < k; i++){
        cin >> r;
        _minCost = INF;
        ids.resize(r);
        for(int j = 0; j < r; j++){
            cin >> ids[j];
            ids[j]--;
            _minCost = min(_minCost, cost[ids[j]]);
        }
        for(int d : ids) cost[d] = _minCost;
    }
    for(int i = 0; i < m; i++){
        cin >> str;
        ans += cost[mp[str]];
    }
    cout << ans << endl;
}
