#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#define F first
#define S second
#define pii pair<int,int>
#define int unsigned long long int
#define ericxiao ios_base::sync_with_stdio(0);
using namespace std;

const int maxLog = 64, maxN = 1e5;
int N, timestmp[maxN + 10], zc;
bool visited[maxN + 10];
vector<int> bits[maxLog], vec, adj[maxN];

inline bool hasbit(int i, int j){
    return (i & (1ULL << j)) > 0;
}

int dfs(int u, int p, int ct){
    timestmp[u] = ct;
    int res = 10000;
    for(int v : adj[u]){
        if(v == p) continue;
        if(timestmp[v] != -1){
            res = min(res, ct - timestmp[v] + 1);
        } else {
            res = min(res, dfs(v, u, ct + 1));
            timestmp[v] = -1;
        }
    }
    visited[u] = true;
    return res;
}


signed main(){
    ericxiao;
    cin >> N;
    vec.resize(N);
    fill(timestmp, timestmp + N + 10, -1);
    for(int i = 0; i < N; i++){
        cin >> vec[i];
        if(!vec[i]){
            continue;
        }
        visited[i] = false;
        for(int j = 0; j < maxLog; j++){
            if(hasbit(vec[i], j)){
                bits[j].push_back(i);
            }
        }
    }
    for(int j = 0; j < maxLog; j++){
        if(bits[j].size() >= 3){
            cout << 3 << endl;
            return 0;
        } else if(bits[j].size() == 2){
            adj[bits[j][0]].push_back(bits[j][1]);
            adj[bits[j][1]].push_back(bits[j][0]);
        }
    }
    int ans = 10000;
    int k;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            k =dfs(i,i,0);
            //cout << "dfs(" << i << ", " << i << ", 0) = " << k << endl;
            ans = min(ans, k);
        }
    }
    if(ans == 10000) cout << -1 << endl;
    else cout << ans << endl;

}
