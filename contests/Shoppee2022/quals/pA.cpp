#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int maxN = 21;

int N, arr[maxN];
map<int, int> lm, rm;

vector<int> L, R;

void dfs(vector<int> &v, int now, int alen, int diff, map<int, int> &mp) {
    if(now == (int)v.size()) {
        if(!mp.count(diff)) mp[diff] = alen;
        mp[diff] = max(mp[diff], alen);
        return;
    }
    dfs(v, now + 1, alen, diff, mp); //neither
    dfs(v, now + 1, alen + v[now], diff + v[now], mp); //A
    dfs(v, now + 1, alen, diff - v[now], mp); //B
}

int main() {
    cin >> N;
    int x;
    int ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> x;
        if(i < N / 2) L.push_back(x);
        else R.push_back(x);
    }
    dfs(L, 0, 0, 0, lm);
    dfs(R, 0, 0, 0, rm);
    for(auto [diff, alen] : lm) {
        if(rm.count(-diff)) ans = max(ans, alen + rm[-diff]);
    }
    cout << ans << endl;
}
