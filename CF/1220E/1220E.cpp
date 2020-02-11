#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long int
using namespace std;

const int maxN = 2e5 + 10;

int s, n, m, a, b;
vector<int> adj[maxN];
vector<int> wei;
bool visited[maxN], can[maxN];
int getStarting(int p, int x){
    //cout << "Running f(" << p << ", " << x << ")\n";
    visited[x] = true;
    can[x] = false;
    int res = wei[x], kk;
    for(int u : adj[x]){
        if(u == p) continue;
        if(visited[u]) can[x] = true;
        else {
            kk = getStarting(x, u);
            if(can[u]){
                res += kk;
                can[x] = true;
            }
        }
    }
    return res;
}

int getTree(int p, int x){
    can[x] = true;
    int res = wei[x], kk = 0;
    for(int u : adj[x]){
        if(!can[u]){
            kk = max(kk, getTree(x, u));
        }
    }
    return res + kk;
}

signed main(){
    ericxiao;
    cin >> n >> m;
    wei.resize(n);
    for(int i = 0; i < n; i++) cin >> wei[i];
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> s;
    s--;
    fill(visited, visited + n, false);
    fill(can, can + n, false);
    int ans = max(wei[s], getStarting(s, s)), lc = 0, tt;
    //cout << "Can be reached: " << ans << endl;
    can[s] = true;
    for(int i = 0; i < n; i++){
        if(can[i]){
            tt = getTree(i, i) - wei[i];
            lc = max(lc, tt);
            //cout << i << ": " << tt << endl;
        }
    }
    cout << ans + lc << endl;
}
