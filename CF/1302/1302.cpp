#include <iostream>
#include <vector>
#include <queue>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5 + 10;

vector<int> adj[maxN], rev[maxN], path, poss;
queue<int> que;
int N, M, K, u, v, minDist[maxN], f, mnNum, mxNum, nx, x;
bool has;

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    cin >> K;
    path.resize(K);
    for(int i = 0; i < K; i++) cin >> path[i];
    fill(minDist, minDist + maxN, maxN);
    minDist[path[K - 1]] = 0;
    que.push(path[K - 1]);
    while(que.size()){
        f = que.front();
        que.pop();
        for(int v : rev[f]){
            if(minDist[v] != maxN) continue;
            minDist[v] = minDist[f] + 1;
            que.push(v);
        }
    }
    //for(int i = 1; i <= N; i++) cout << minDist[i] << " ";
    //cout << endl;
    for(int i = 0; i < K - 1; i++){
        x = path[i];
        nx = path[i + 1];
        if(x == path[K - 1]) break;
        poss.clear();
        has = false;
        for(int v : adj[x]){
            if(minDist[v] + 1 == minDist[x]){
                poss.push_back(v);
                if(v == nx) has = true;
            }
        }
        //cout << "From " << x << ", pos =";
        //for(int t : poss) cout << " " << t;
        //cout << endl;
        //if path[k] in
        if(!has){
            mnNum++, mxNum++;
        } else{
            if(poss.size() > 1) mxNum++;
        }
    }
    cout << mnNum << " " << mxNum << endl;
}
