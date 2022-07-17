#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 1e3 + 26;
vector<pii> fwd, bk;
bool adj[maxN][maxN];
int N;

int getOther(int u, int v) {
    for(int i = 2; i <= N; i++) {
        if(adj[u][i] && adj[v][i]) {
            return i;
        }
    }
}

void dfs(int l, int r, vector<pii> &res, bool f) {
    //cout << "dfs(" << l << " " << r << ")" << endl;
    if(l + 1 >= r) return;
    int m = getOther(l, r);
    if(f)
        res.emplace_back(l, r);
    else res.emplace_back(1, m);
    adj[l][r] = adj[r][l] = 0;
    adj[1][m] = adj[m][1] = 1;
    dfs(l, m, res, f);
    dfs(m, r, res, f);
}

vector<pii> solve(bool f = true) {
    vector<pii> res;
    vector<int> pos;
    for(int i = 2; i <= N; i++) if(adj[1][i]) pos.push_back(i);
    for(int i = 0; i + 1 < (int)pos.size(); i++) dfs(pos[i], pos[i + 1], res, f);
    return res;
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) adj[i][j] = 0;
    for(int i = 0; i < N - 3; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    for(int i = 1; i < N; i++) {
        adj[i][i + 1] = adj[i + 1][i] = 1;
    }
    adj[1][N] = adj[N][1] = 1;
    //for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) cout << adj[i][j] << " \n"[j == N];
    fwd = solve(true);
    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) adj[i][j] = 0;
    for(int i = 1; i < N; i++) {
        adj[i][i + 1] = adj[i + 1][i] = 1;
    }
    adj[1][N] = adj[N][1] = 1;
    for(int i = 0; i < N - 3; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }
    bk = solve(false);
    reverse(bk.begin(), bk.end()); 
    cout << (fwd.size() + bk.size()) << endl;
    for(auto [a, b] : fwd) cout << a << " " << b << endl;
    for(auto [a, b] : bk)  cout << a << " " << b << endl;
}
