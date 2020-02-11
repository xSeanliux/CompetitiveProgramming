#include <iostream>
#include <vector>
#include <algorithm>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10, INF = 1e16;

int n, a, b, per[3] = {0, 1, 2};
vector<int> vec, c[3], dp[3], col[3], ans;
vector<int> adj[maxN];

signed main(){
    ericxiao;
    cin >> n;
    for(int i = 0; i < 3; i++){
        dp[i].resize(n);
        c[i].resize(n);
        col[i].resize(n);
    }
    ans.resize(n);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < n; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if(adj[a].size() > 2 || adj[b].size() > 2){
            cout << "-1" << endl;
            return 0;
        }
    }
    int s = -1, p;
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 1){
            p = s = i;
            break;
        }
    }
    //cout << "S = " << s << endl;
    vector<int> ord;
    for(int i = 0; i < n; i++){
        ord.push_back(s);
        for(int u : adj[s]){
            if(u == p) continue;
            else {
                //cout << "Going to " << u << endl;
                p = s;
                s = u;
                break;
            }
        }
    }

    int bestcol[3], x = INF, _x;
    do{
        _x = 0;
        for(int i = 0; i < n; i++){
            _x += c[per[i % 3]][ord[i]];
            //cout << "Adding c[" << per[i] << "][" << ord[i] << "] = " << c[per[i]][ord[i]] << endl;
        }
        //for(int i = 0; i < 3; i++) cout << per[i] << " ";
        //cout << "GET: " << _x << endl;
        if(x > _x){
            x = _x;
            for(int i = 0; i < 3; i++) bestcol[i] = per[i];
        }
    } while(next_permutation(per, per + 3));
    for(int i = 0; i < n; i++){
        ans[ord[i]] = bestcol[i % 3] + 1;
    }
    cout << x << endl;
    for(int u : ans) cout << u << " ";

}
