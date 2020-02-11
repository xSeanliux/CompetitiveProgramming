#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define int long long int
using namespace std;

const int maxN = 1e4 + 50, INF = 1e17;

priority_queue<pii, vector<pii>, greater<pii> > pq;

int n, m, a, b, c;
vector<int> minDist;
vector<pii> adj[maxN];
vector<bool> visited;

signed main(){
    cin >> n >> m;
    minDist.resize(n + 1);
    visited.resize(n + 1);
    fill(minDist.begin(), minDist.end(), INF);
    fill(visited.begin(), visited.end(), false);
    pq.push({0, 1});
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    pii e;
    minDist[1] = 0;
    for(int i = 0; i < n; i++){
        //cout <<"A" << endl;
        do{
            e = pq.top();
            pq.pop();
        } while(pq.size() && (e.F > minDist[e.S] || visited[e.S]));
        visited[e.S] = true;
        for(auto p : adj[e.S]){
            if(visited[p.F]) continue;
            if(minDist[p.F] > minDist[e.S] + p.S){
                pq.push({minDist[e.S] + p.S, p.F});
                minDist[p.F] = minDist[e.S] + p.S;
            }
        }
        //cout << "O" << endl;
    }
    for(int i = 1; i <= n; i++) cout << minDist[i] << endl;

}
