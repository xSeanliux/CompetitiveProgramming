#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <numeric>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 326;
int N, M, K, T, rkl[maxN], rkr[maxN];
bool vis[maxN];
vector<int> arr[maxN], adj[maxN];
vector<pii> lefpre[maxN], rigpre[maxN];

inline void addEdge(int u, int v) {
    //cout << u << " " << v << endl;
    adj[u].push_back(v);
}

void dfs(int u, int &cnt) {
    //cout << "at dfs(" << u << ") = " << endl;
    vis[u] = true;
    cnt++;
    for(int v : adj[u]) if(!vis[v]) dfs(v, cnt);
}

inline void solve() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        vector<int>(M).swap(arr[i]);
        vector<pii>(M).swap(lefpre[i]);
        vector<pii>(M).swap(rigpre[i]);
        for(int j = 0; j < M; j++) {
            cin >> arr[i][j];
            lefpre[i][j] = rigpre[i][j] = {arr[i][j], arr[i][j]};
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 1; j < M; j++) {
            lefpre[i][j] = {min(lefpre[i][j - 1].F, lefpre[i][j].F), max(lefpre[i][j - 1].S, lefpre[i][j].S)};
            rigpre[i][M - 1 - j] = {min(rigpre[i][M - j].F, rigpre[i][M - 1 - j].F), max(rigpre[i][M - j].S, rigpre[i][M - 1 - j].S)};
        }
    }
    vector<int> lef, rig;
    vector<pii> ord = vector<pii>();
    for(int i = 0; i < N; i++) {
        ord.emplace_back(i, 0);
        ord.emplace_back(i, 1);
    }
    lef = vector<int>(N), rig = vector<int>(N);
    iota(lef.begin(), lef.end(), 0);
    iota(rig.begin(), rig.end(), 0);
    for(int k = 0; k < M - 1; k++) {
        //cout << "k = " << k << endl;
        for(int i = 0; i < N; i++) vector<int>().swap(adj[i]);
        fill(vis, vis + N, 0);
        sort(lef.begin(), lef.end(), [=](int i, int j) {
            return lefpre[i][k].S == lefpre[j][k].S ? lefpre[i][k].F > lefpre[j][k].F : lefpre[i][k].S < lefpre[j][k].S;
        });
        sort(rig.begin(), rig.end(), [=](int i, int j) {
            return rigpre[i][k + 1].F == rigpre[j][k + 1].F ? rigpre[i][k + 1].S < rigpre[j][k + 1].S : rigpre[i][k + 1].F > rigpre[j][k + 1].F;
        });
        for(int i = 1; i < N; i++) {
            addEdge(lef[i], lef[i - 1]);
        }
        for(int i = 1; i < N; i++) {
            addEdge(rig[i], rig[i - 1]);
        }
        for(int i = 0; i < N; i++) {
            rkr[rig[i]] = rkl[lef[i]] = i;
        }
        sort(ord.begin(), ord.end(), [=](pii a, pii b){
            int x = (a.S ? lefpre[a.F][k].S : lefpre[a.F][k].F);
            int y = (b.S ? lefpre[b.F][k].S : lefpre[b.F][k].F);
            return x == y ? a.S < b.S : x < y;
        });
        int maxInd = -1;
        for(auto [row, typ] : ord) {
            if(typ == 0) {
                if(maxInd == -1 || rkl[row] > rkl[maxInd]) maxInd = row; 
            } else {
                addEdge(row, maxInd);
            }
        }
        sort(ord.begin(), ord.end(), [=](pii a, pii b){
            int x = (a.S ? rigpre[a.F][k + 1].F : rigpre[a.F][k + 1].S);
            int y = (b.S ? rigpre[b.F][k + 1].F : rigpre[b.F][k + 1].S);
            return x == y ? a.S < b.S : x > y;
        });
        maxInd = -1;
        for(auto [row, typ] : ord) {
            if(typ == 0) {
                if(maxInd == -1 || rkr[row] > rkr[maxInd]) maxInd = row; 
            } else {
                addEdge(row, maxInd);
            }
        }
        int cnt = 0;
        dfs(lef[0], cnt);
        if(cnt < N) {
            cout << "YES\n";
            for(int i = 0; i < N; i++) cout << "RB"[vis[i]];
            cout << endl << k + 1 << endl;
            return;
        }
    }
    cout << "NO\n";
}
int main(){
    ericxiao
    cin >> T;
    while(T--) {
        solve();
    }
}

