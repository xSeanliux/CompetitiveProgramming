#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <utility>
#define ericxiao ios_base::sync_with_stdio(0); cin.tie(0);
#define int long long int
using namespace std;

const int INF = 1e15;
vector<int> wei, lastEdge, minDist;
vector<vector<pair<int, int> > > adj;
vector<bool> visited;

int N, M, st;

signed main(){
    ericxiao;
    cin >> N >> M;
    wei.resize(M + 1);
    lastEdge.resize(N + 1);
    minDist.resize(N + 1);
    adj.resize(N + 1);
    visited.resize(N + 1);
    fill(lastEdge.begin(), lastEdge.end(), -1);
    fill(minDist.begin(), minDist.end(), INF);
    fill(visited.begin(), visited.end(), false);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> >  > pq;
    int u, v, w;
    for(int i = 1; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        wei[i] = w;
    }
    cin >> st;
    minDist[st] = 0;
    pq.push({0, st});
    while(!pq.empty()){
        while(pq.size() && visited[pq.top().second]){
            pq.pop();
        }
        if(pq.empty()) break;
        auto t = pq.top();
        pq.pop();
        for(auto e : adj[t.second]){
            if(visited[e.first]) continue; //this is very important, 514ms -> 436ms
            if(minDist[e.first] > minDist[t.second] + wei[e.second]){
                minDist[e.first] = minDist[t.second] + wei[e.second];
                lastEdge[e.first] = e.second;
            } else if(minDist[e.first] == minDist[t.second] + wei[e.second] && wei[lastEdge[e.first]] > wei[e.second]){
                lastEdge[e.first] = e.second;
            }
            pq.push({minDist[e.first], e.first});
        }
        visited[t.second] = true;
    }
    int A = 0;
    for(int i = 1; i <= N; i++){
        if(i != st) A += wei[lastEdge[i]];
    }
    cout << A << endl;
    for(int i = 1; i <= N; i++){
        if(i != st) cout << lastEdge[i]<< " ";
    }
    return 0;
}
