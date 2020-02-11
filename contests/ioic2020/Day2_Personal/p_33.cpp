#include <iostream>
#include <vector>
#include <deque>
using namespace std;

const int maxN = 2e5 + 10;

vector<int> adj[maxN];
vector<int> centroids[maxN];
deque<int> ord;
int sts[maxN], maxChild[maxN], N, u, v;

void dfs1(int p, int u){
    maxChild[u] = -1;
    sts[u] = 1;
    ord.push_front(u);
    for(int v : adj[u]){
        if(v == p) continue;
        dfs1(u, v);
        if(maxChild[u] == -1 || sts[maxChild[u]] < sts[v]) maxChild[u] = v;
        sts[u] += sts[v];
    }


    int beg = lower_bound(ord.begin(), ord.end(), 2 * sts[maxChild[u]], [=](int a, int b){
        return a < (sts[b] + 1) / 2;
    }) - ord.begin();
    int ed = upper_bound(ord.begin(), ord.end(), sts[u], [=](int a, int b){
        return a > (sts[b] + 1) / 2;
    }) - ord.begin();
    for(int i = beg; i < ed; i++){
        if(sts[ord[i]] - sts[u] <= sts[ord[i]] / 2 && sts[maxChild[u]] <= sts[ord[i]] / 2)
            centroids[ord[i]].push_back(u);
    }
    ord.pop_front();
}




int main(){
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 1);
    for(int i = 1; i <= N; i++){
        for(int x : centroids[i]) cout << x << " ";
        cout << '\n';
    }
}
