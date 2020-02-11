//#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define int long long
using namespace std;

const int N = 1e5 + 10;
const int K = 288;
const int P = 18;

vector<int> G[N];
vector<pii> adj[N];

int n, q, u, v, we;

int w[N], x[N], y[N], frq[N], howMany[N];
int pin[N], pout[N], lca[P][N], stamp = 0;
int a[2 * N], st[N], used[N], cnt[N], cur_ans = 0, ans[N];

void dfs(int now, int par){
    pin[now] = stamp;
    st[now] = stamp;
    lca[0][now] = par;
    for(int to : G[now]){
        if(to == par) continue;
        a[++stamp] = to;
        dfs(to, now);
        a[++stamp] = to;
    }
    pout[now] = stamp;
}

bool is_anc(int par, int son){
    return pin[par] <= pin[son] && pout[son] <= pout[par];
}

int get_lca(int x, int y){
    if(is_anc(x, y)) return x;
    if(is_anc(y, x)) return y;
    for(int i = P - 1; i >= 0; i--){
        if(!is_anc(lca[i][y], x)){
            y = lca[i][y];
        }
    }
    return lca[0][y];
}

struct Query{
    int L, R, Lid, qid;
    void set_query(int l, int r, int id){
        L = l, R = r, Lid = l/K, qid = id;
    }
} query[N];

bool cmp(Query a, Query b){
    return make_pair(a.Lid, a.R) < make_pair(b.Lid, b.R);
}

void add(int x){
    if(frq[x]){
        howMany[frq[x]]--;
        cur_ans -= howMany[frq[x] * 2];
        if(!(frq[x] % 2)) cur_ans -= howMany[frq[x] / 2];
    }
    frq[x]++;
    howMany[frq[x]]++;
    cur_ans += howMany[frq[x] * 2];
    if(!(frq[x] % 2)) cur_ans += howMany[frq[x] / 2];
}

void sub(int x){
    howMany[frq[x]]--;
    cur_ans -= howMany[frq[x] * 2];
    if(!(frq[x] % 2)) cur_ans -= howMany[frq[x] / 2];
    frq[x]--;
    if(frq[x]){
        howMany[frq[x]]++;
        cur_ans += howMany[frq[x] * 2];
        if(!(frq[x] % 2)) cur_ans += howMany[frq[x] / 2];
    }
}

void modify(int id){
    if(used[id]){
        sub(w[id]);
    } else if(!used[id]){
        add(w[id]);
    }
    used[id] ^= 1;
}

void getW(int p, int u){
    for(pii e : adj[u]){
        if(e.F == p) continue;
        w[e.F] = e.S;
        getW(u, e.F);
    }
}

signed main(){
    ericxiao;
    cin >> n >> q;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v >> we;
        G[u].push_back(v);
        G[v].push_back(u);
        adj[u].emplace_back(v, we);
        adj[v].emplace_back(u, we);
    }
    getW(1, 1);
    dfs(1, 1);
    for(int i = 1; i < P; i++){
        for(int j = 1; j <= n; j++){
            lca[i][j] = lca[i - 1][ lca[i - 1][j] ];
        }
    }
    for(int i = 1; i <= q; i++){
        cin >> x[i] >> y[i];
        query[i].set_query(min(st[x[i]], st[y[i]]) + 1, max(st[x[i]], st[y[i]]), i);
    }
    sort(query + 1, query + 1 + q, cmp);
    for(int i = 1, curL = 1, curR = 0; i <= q; i++){
        while(curR < query[i].R) modify(a[++curR]);
        while(curR > query[i].R) modify(a[curR--]);
        while(curL < query[i].L) modify(a[curL++]);
        while(curL > query[i].L) modify(a[--curL]);
        int qid = query[i].qid;
        int lca = get_lca(x[qid], y[qid]);
        ans[qid] = cur_ans;
    }
    for(int i = 1; i <= q; i++){
        cout << ans[i] << '\n';
    }
}
