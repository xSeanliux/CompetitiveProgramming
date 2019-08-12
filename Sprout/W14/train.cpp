#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int INF = 1e18;
int N, M, Q, u, v, w;
vector<vector<pii> > adj, radj;
vector<int> mS, mE;
vector<bool> visited;

signed main(){
    cin >> N >> M >> Q;
    adj.resize(N + 1);
    radj.resize(N + 1);
    mS.resize(N + 1);
    mE.resize(N + 1);
    visited.resize(N + 1);
    fill(mS.begin(), mS.end(), INF);
    fill(mE.begin(), mE.end(), INF);
    fill(visited.begin(), visited.end(), false);

    for(int i = 0; i < M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        radj[v].push_back({u, w});
    }

    mS[1] = 0, mE[N] = 0;
    priority_queue<pii, vector<pii>, greater<pii> > pq;
    pq.push({0, 1});
    pii p;
    while(pq.size()){
        p = pq.top();
        pq.pop();
        if(visited[p.second]) continue;
        visited[p.second] = true;
        for(auto v : adj[p.second]){
            if(!visited[v.first] && mS[v.first] > p.first + v.second){
                mS[v.first] = p.first + v.second;
                pq.push({mS[v.first], v.first});
            }
        }
    }
    fill(visited.begin(), visited.end(), false);
    pq.push({0, N});
    while(pq.size()){
        p = pq.top();
        pq.pop();
        if(visited[p.second]) continue;
        visited[p.second] = true;
        for(auto v : radj[p.second]){
            if(!visited[v.first] && mE[v.first] > p.first + v.second){
                mE[v.first] = p.first + v.second;
                pq.push({mE[v.first], v.first});
            }
        }
    }
    /*
    cout << "MS:" << endl;
    for(int i : mS){
        cout << i << " ";
    }
    cout << endl << "ME: " << endl;
    for(int i : mE){
        cout << i << " ";
    }
    */
    int minDist = mS[N];
    while(Q--){
        cin >> u >> v;
        cout << min(minDist, mS[u] + mE[v] + 1) << '\n';
    }
}
