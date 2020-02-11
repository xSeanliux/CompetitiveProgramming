#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;
vector<int> go, cost, ord;
vector<bool> visited;
int n, a, b, ans = 0;

void dfs(int x){
    visited[x] = true;
    if(go[x] == x){
        ans += cost[x];
        return;
    }
    ord.push_back(x);
    if(visited[go[x]]){ //return
        int i, minV = 2e9;
        for(i = 0; i < ord.size(); i++){
            if(ord[i] == go[x]) break;
        }
        for(i; i < ord.size(); i++){
            minV = min(minV, cost[ord[i]]);
        }
        if(minV == 2e9) return;
        ans += minV;
        return;
    } else {
        dfs(go[x]);
    }
}


int main(){
    ericxiao;
    cin >> n;
    cost.resize(n + 1);
    go.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
    for(int i = 1; i <= n; i++) cin >> cost[i];
    for(int i = 1; i <= n; i++){
        cin >> go[i];
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            ord.resize(0);
            dfs(i);
        }
    }
    cout << ans << endl;
}
