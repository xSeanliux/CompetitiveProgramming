#include <iostream>
#include <queue>
#include <utility>
#include <fstream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5 + 10;

vector<pii> adj[maxN];
queue<int> que;
pii from[maxN];
int N, M, u, v, w, minDist[maxN];
bool visited[maxN];
vector<int> ans;

int main(){
    fstream infile, outfile;
    infile.open("ideal.in");
    outfile.open("ideal.out");
    ericxiao;
    infile >> N >> M;
    for(int i = 0; i < M; i++){
        infile >> u >> v >> w;
        if(u == v) continue;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for(int i = 1; i <= N; i++){
        sort(adj[i].begin(), adj[i].end(), [=](pii a, pii b){
            return a.S < b.S;
        });
        minDist[i] = maxN;
        visited[i] = false;
        from[i].S = 1e9 + 10;
    }
    que.push(1);
    minDist[1] = 1;
    visited[1] = true;
    while(que.size()){
        int t = que.front();
        que.pop();
        for(auto p : adj[t]){
            if(!visited[p.F]){
                minDist[p.F] = minDist[t] + 1;
                que.push(p.F);
                visited[p.F] = true;
            }
            if(minDist[p.F] == minDist[t] + 1 && from[p.F].S > p.S){
                from[p.F].F = t;
                from[p.F].S = p.S;
            }
        }
    }
    for(int i = 1, x = N; i < minDist[N]; i++, x = from[x].F){
        ans.push_back(from[x].S);
    }
    reverse(ans.begin(), ans.end());
    outfile << minDist[N] - 1 << endl;
    for(int i = 0; i < ans.size(); i++) outfile << ans[i] << " \n"[i == ans.size() - 1];
    infile.close();
    outfile.close();
}

