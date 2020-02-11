#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;


const int LIM = 1e18;
int N, a, b;
vector<pii> ans;
vector<int> adj[40];

inline pii get(int x, int y, int dir, int step){

    if(dir == 0){
        x -= step;
    } else if(dir == 1){
        x += step;
    } else if(dir == 2){
        y -= step;
    } else if(dir == 3){
        y += step;
    }
    pii p = {x, y};
    return p;
}

inline int oppo(int dir){
    if(dir == 0) return 1;
    if(dir == 1) return 0;
    if(dir == 2) return 3;
    if(dir == 3) return 2;
}

void dfs(int p, int c, int dep, int x, int y, int dir){
    //printf("Running dfs(%d %d %d %d %d %d)\n", p, c, dep, x, y, dir);
    ans[c] = {x, y};
    vector<int> dirs = vector<int>();
    dirs.clear();
    if(p != c){
        for(int i = 0; i < 4; i++) if(oppo(dir) != i) dirs.push_back(i);
    } else {
        for(int i = 0; i < 4; i++) dirs.push_back(i);
    }

    //cout << "Dirs: ";
    //for(int d : dirs) cout << d << " ";
    //cout << endl;
    pii togo;
    int cnt = 0, step = ((int)1 << (N - dep));
    for(int i = 0; i < adj[c].size(); i++){
        if(adj[c][i] == p) continue;
        togo = get(x, y, dirs[cnt], step);
        dfs(c, adj[c][i], dep + 1, togo.F, togo.S, dirs[cnt]);
        cnt++;
    }
}

signed main(){
    cin >> N;
    ans.resize(N + 1);
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        if(adj[i].size() > 4){
            cout << "NO" << endl;
            return 0;
        }
    }
    dfs(1, 1, 0, 0, 0, 0);
    cout << "YES" << endl;
    for(int i = 1; i <= N; i++){
        cout << ans[i].F << " " << ans[i].S << endl;
    }
}
