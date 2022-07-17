#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include <algorithm>
#include <ctime>
#include <set>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e2 + 10;
int N, M, same[maxN][maxN][maxN], dist[maxN][maxN]; //d(i, k) = d(j, k) for same[i][j][k]
vector<int> adj[maxN];

mt19937 rng;
int randint(int lb, int ub)
{ return uniform_int_distribution<int>(lb,
ub)(rng); }

inline void addEdge(int u, int v) {
    M++;
    adj[u].push_back(v); 
}

void dfs(int p, int u) {
    //cerr << "at dfs(" << p << ", " << u << endl;
    if(M > N - 1) return;
    for(int v = 1; v <= N; v++) if(same[v][p][u]) {
        addEdge(u, v);
        dfs(u, v);
    }
}

bool check(int u, int v) {
    for(int i = 1; i <= N; i++) adj[i].clear();
    M = 0;
    addEdge(u, v);
    dfs(u, v);
    dfs(v, u);
    if(M != N - 1) return false;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) dist[i][j] = dist[j][i] = (int)(i != j) * maxN;
    }
    for(int u = 1; u <= N; u++) for(int v : adj[u]) dist[u][v] = dist[v][u] = 1;
    for(int k = 1; k <= N; k++) for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
    for(int x = 1; x <= N; x++) for(int y = 1; y < x; y++) for(int z = 1; z <= N; z++) {
        if((dist[x][z] == dist[y][z]) ^ same[x][y][z]) return false;
    }
    return true;
}

inline void solve() {
    cin >> N;
    string s;
    vector<pii> indices = vector<pii>();
    set<pii> st;
    for(int i = 1; i < N; i++) for(int j = 1; j <= N - i; j++) {
        cin >> s;
        for(int k = 0; k < N; k++) {
            same[i][i + j][k + 1] = same[i + j][i][k + 1] = s[k] - '0';
        }
    }
    for(int x = 2; x <= N; x++) { 
        if(check(1, x)) {
            //output answer
            cout << "Yes\n";
            for(int i = 1; i <= N; i++) for(int v : adj[i]) cout << i << " " << v << '\n';
            return;
        }
    }
    cout << "No\n";
}

int main() {
    rng = mt19937(time(0));
    int T;
    cin >> T;
    while(T--) solve();
}
