#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5;

int sts[maxN + 10], colour[maxN + 10], frq[maxN + 10], howmany[maxN + 10];
long long int sum[maxN + 10], ans[maxN + 10];
vector<int> adj[maxN + 10], stn[maxN + 10];
int N, a, b, c, most = 0;


inline void add(long long int x){
    howmany[frq[x]]--;
    sum[frq[x]] -= x;
    frq[x]++;
    sum[frq[x]] += x;
    howmany[frq[x]]++;
    if(most < frq[x]) most = frq[x];
}

inline void rem(long long int x){
    howmany[frq[x]]--;
    if(howmany[frq[x]] == 0){
        most--;
    }
    sum[frq[x]] -= x;
    frq[x]--;
    sum[frq[x]] += x;
    howmany[frq[x]]++;
}

void getsts(int p, int c){
    sts[c] = 1;
    for(int u : adj[c]){
        if(u == p) continue;
        getsts(c, u); //hey lol don't forget me
        sts[c] += sts[u];
    }
}

void dfs(int p, int c, bool keep){
    int maxSz = -1, ind = -1;
    for(int u : adj[c]){
        if(u != p && sts[u] > maxSz){
            maxSz = sts[u];
            ind = u;
        }
    }
    for(int u : adj[c]){
        if(u == p || u == ind) continue;
        dfs(c, u, 0);
    }

    if(ind != -1){
        dfs(c, ind, 1);
        swap(stn[c], stn[ind]);
    }

    add(colour[c]);
    stn[c].push_back(c);

    for(int u : adj[c]){
        if(u == p || u == ind) continue;
        for(int v : stn[u]){
            add(colour[v]);
            stn[c].push_back(v);
        }
    }

    ans[c] = sum[most];
    if(!keep){
        for(int u : stn[c]){
            rem(colour[u]);
        }
    }
}

signed main(){
    ericxiao
    cin >> N;
    howmany[0] = N;
    for(int i = 1; i <= N; ++i){
        cin >> colour[i];
    }
    for(int i = 0; i < N - 1; ++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    getsts(0, 1);
    dfs(0, 1, 1);
    for(int i = 1; i <= N; ++i){
        cout << ans[i] << " \n"[i == N];
    }
    return 0;
}
