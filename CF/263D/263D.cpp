#include <iostream>
#include <vector>
using namespace std;

int K, N, M, a, b;
bool isFin = false;
vector<vector<int> > adj;
vector<int> currentAns, t;
vector<bool> visited;

void dfs(int now, int gen){
    //cout << "Running dfs(" << now << ", " << gen << ")" << endl;
    if(isFin) return;
    currentAns[gen] = now;
    t[now] = gen;
    visited[now] = true;
    for(int other : adj[now]){
        if(visited[other] && gen - t[other] >= K && !isFin){ //output
            cout << gen - t[other] + 1 << endl;
            for(int i = t[other]; i <= gen; i++){
                cout << currentAns[i] << " \n"[i == gen];
            }
            isFin = true;
            return;
        }
        if(!visited[other] && !isFin) dfs(other, gen + 1);
    }
}


int main(){
    cin >> N >> M >> K;
    adj.resize(N + 1);
    t.resize(N + 1);
    currentAns.resize(N + 2);
    visited.resize(N + 1);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    fill(visited.begin(), visited.end(), false);
    dfs(1, 0);
}
