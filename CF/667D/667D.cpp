#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > adj, shortestDist;
vector<int> far, fardist;

int N, M, a, b;

void bfs(int x){
    queue<int> q;
    vector<bool> visited;
    shortestDist[x].resize(N + 1);
    fill(visited.begin(), visited.end(), false);
    q.push(0);
    minDist[x][x] = 0;
    visited[x] = true;
    int f, maxd = -1, mind = -1;
    while(q.size()){
        f = q.front();
        q.pop();
        for(int u : adj[f]){
            if(!visited[u]){
                minDist[x][u] = minDist[x][f] + 1;
                if(maxd < minDist[x][u]){
                    maxd = minDist[x][u];
                    mind = u;
                }
                visited[u] = true;
                q.push(u);
            }
        }
    }
    far[x] = mind;
    fardist[x] = maxd;
}

int main(){
    cin >> N >> M;
    adj.resize(N + 1);
    shortestDist.resize(N + 1);
    fardist.resize(N + 1);
    far.resize(N + 1);

}
