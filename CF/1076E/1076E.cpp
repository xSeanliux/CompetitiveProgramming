#include <iostream>
#include <math.h>
#include <vector>
#include <utility>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
using namespace std;

const int maxN = 3e5;
int N, M;
int a, b, v, x, d;
vector<int> bit, ans;
vector<vector<int> > adj;
vector<vector<pii> > ops;


void add(int pos, int val){
    for(int i = pos; i <= N; i += i & -i){
        bit[i] += val;
    }
}

int sum(int pos){
    int res = 0;
    for(int i = pos; i > 0; i -= i & -i){
        res += bit[i];
    }
    return res;
}

void dfs(int parent, int now, int dep){
    for(auto op : ops[now]){
        add(min(N, dep + op.second), op.first);
    }
    ans[now] = sum(N) - sum(dep-1);
    for(int u : adj[now]){
        if(u == parent) continue;
        dfs(now, u, dep + 1);
    }
    for(auto op : ops[now]){
        add(min(N, dep + op.second), -op.first);
    }
}

signed main(){
    ericxiao;
    cin >> N;
    adj.resize(N + 1);
    bit.resize(N + 1);
    ans.resize(N + 1);
    fill(bit.begin(), bit.end(), 0);
    for(int i = 1; i < N; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> M;
    ops.resize(N + 1);
    for(int i = 0; i < M; i++){
        cin >> v >> d >> x;
        ops[v].push_back({x, d});
    }
    dfs(1, 1, 1);
    for(int i = 1; i <= N; i++) cout << ans[i] << " \n"[i == N];
}
