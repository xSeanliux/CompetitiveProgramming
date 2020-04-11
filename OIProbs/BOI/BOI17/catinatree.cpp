#pragma GCC optimize ("O3")
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

int dep[maxN], md[maxN], ans, N, D, x, ord[maxN], root;

vector<int> adj[maxN];
bool isavai[maxN];

void getDep(int p = root, int u = root){
    dep[u] = dep[p] + 1;
    //cout << "Dep[" << u << "] = " << dep[u] << endl;
    for(int v : adj[u]){
        if(v == p) continue;
        getDep(u, v);
    }
}

void upd(int u){ //must use BFS not DFS!
    queue<pii> que;
    md[u] = 0;
    que.push({u, 0});
    while(que.size()){
        pii p = que.front();
        que.pop();
        if(p.S == D - 1) continue;
        for(int v : adj[p.F]){
            if(md[v] > md[p.F] + 1){
                md[v] = md[p.F] + 1;
                isavai[v] = false;
                que.push({v, p.S + 1});
            }
        }
    }
}

int main(){
    ericxiao;
    cin >> N >> D;
    root = (2147483647 % N);
    md[0] = maxN;
    isavai[0] = true;
    //cout << "Root = " << root << endl;
    for(int i = 1; i < N; i++){
        cin >> x;
        ord[i] = i;
        md[i] = maxN;
        //cout << "md[" << i << " = " << md[i] << endl;
        isavai[i] = true;
        adj[x].push_back(i);
        adj[i].push_back(x);
    }
    getDep();
    sort(ord, ord + N, [=](int i, int j){
        return dep[i] > dep[j];
    });
    for(int i = 0; i < N; i++){
        if(!isavai[ord[i]]) continue;
        ans++;
        upd(ord[i]);
    }
    cout << ans << endl;
}
