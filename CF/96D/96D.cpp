#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define F first
#define S second
#define pii pair<int,int>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e3, INF = 1e17;


vector<pii> adj[maxN + 10], costadj[maxN + 10];
vector<int> cost, maxdist;

int minDist[maxN + 10][maxN + 10], N, M, s, t;

void getMindist(int start){
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, start});
    bool visited[N];
    fill(visited, visited + N, false);
    fill(minDist[start], minDist[start] + N, INF);
    minDist[start][start] = 0;
    pii p;
    while(pq.size()){
        p = pq.top();
        pq.pop();
        if(visited[p.S]) continue;
        for(pii e : adj[p.S]){
            if(visited[e.F]) continue;
            else if(minDist[start][e.F] > minDist[start][p.S] + e.S){
                minDist[start][e.F] = minDist[start][p.S] + e.S;
                pq.push({minDist[start][e.F], e.F});
            }
        }
        visited[p.S] = true;
    }
}


signed main(){
    ericxiao
    cin >> N >> M >> s >> t;
    cost.resize(N + 1);
    maxdist.resize(N + 1);
    int a, b, c;
    for(int i = 0; i < M; i++){
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i = 0; i < N; i++){
        cin >> maxdist[i] >> cost[i];
    }
    for(int i = 0; i < N; i++){
        getMindist(i);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(maxdist[i] >= minDist[i][j]){
                costadj[i].push_back({j, cost[i]});
                //cout << "I can go to " << j << " from " << i << " with cost " << cost[i] << endl;
            }
        }
    }
    s--;
    t--;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    bool visited[N + 10];
    fill(visited, visited + N, 0);
    pq.push({0, s});
    int dist[N + 10];
    fill(dist, dist + N, INF);
    dist[s] = 0;
    pii p;
    while(pq.size()){
        p = pq.top();
        pq.pop();
        if(visited[p.S]) continue;
        for(pii e : costadj[p.S]){
            if(visited[e.F]) continue;
            if(dist[e.F] > dist[p.S] + e.S){
                dist[e.F] = dist[p.S] + e.S;
                pq.push({dist[e.F], e.F});
            }
        }
        visited[p.S] = true;
    }
    if(dist[t] == INF) cout << -1 << endl;
    else cout << dist[t] << endl;
}


