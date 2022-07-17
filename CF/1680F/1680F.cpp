#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <numeric>
#include <chrono>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e6 + 326;
vector<int> adj[maxN];
int assign[maxN], skipped, N, M, ord[maxN];

default_random_engine g;
bool dfs(int u) {
    for(int v : adj[u]) {
        if(assign[v] == -1) {
            assign[v] = assign[u] ^ 1;
            if(!dfs(v)) return false;
        } else if(assign[v] == assign[u]) {
            if(skipped == 2) return false;
            skipped++;
        }
    }
    return true;
}

bool trial() {
    fill(assign, assign + N, -1);
    skipped = 0;

    shuffle(ord, ord + N, g);
    for(int i = 0; i < N; i++) {
        shuffle(adj[i].begin(), adj[i].end(), g);
    }
    for(int i = 0; i < N; i++) if(assign[ord[i]] == -1) {
        assign[ord[i]] = 0;
        if(!dfs(ord[i])) {
            return false;
        }
    }
    return true;
}

inline void solve() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) vector<int>().swap(adj[i]);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    iota(ord, ord + N, 0);
    for(int i = 0; i < 50; i++) if(trial()) {
        cout << "YES\n";
        bool toXor = 0;
        for(int u = 0; u < N; u++) {
            for(int v : adj[u]) {
                if(!assign[u] && !assign[v]) toXor = 1;
            }
        }
        for(int i = 0; i < N; i++) cout << (assign[i] ^ toXor);
        cout << '\n';
        return;
    }
    cout << "NO\n";
}

int main() {
    ericxiao;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    g = default_random_engine(seed);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
}
