#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#include <set>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 5e5 + 226;

vector<int> adj[maxN], arr;
vector<pii> ans;
int N, u ,v;

void dfs(int p, int u){
    vector<int> ord;
    for(int v : adj[u]){
        if(v == p) continue;
        ord.push_back(v);
        dfs(u, v);
    }
    reverse(ord.begin(), ord.end());
    arr.push_back(u);
    for(int v : ord) arr.push_back(-v);
}

int main(){
    ericxiao;
    cin >> N;
    arr.push_back(0);
    ans.resize(N + 1);
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    arr.push_back(-1);
    //for(int x : arr) cout << x << " ";
    //cout << endl;
    for(int i = 1; i <= 2 * N; i++){
        if(arr[i] < 0){
            ans[-arr[i]].S = i;
        } else {
            ans[arr[i]].F = i;
        }
    }
    for(int i = 1; i <= N; i++) cout << ans[i].F << " " << ans[i].S << '\n';
}
