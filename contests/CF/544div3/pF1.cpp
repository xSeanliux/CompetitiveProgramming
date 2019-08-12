#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2e5;
int N, K, a, b;

int deg[MAXN];
bool visited[MAXN];
vector<vector<int> >adj;
queue<int> que;


int main(){
    cin >> N >> K;
    int md = 0, mdat;
    //adj.resize(N + 1);
    adj.push_back(vector<int>());
    for(int i = 1; i <= N; i++) {
        deg[i] = 0;
        visited[i] = 0;
        adj.push_back(vector<int>());
    }
    for(int i = 0; i < K; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++; deg[b]++;
        if(deg[a] > md){
            md = deg[a];
            mdat = a;
        }
        if(deg[b] > md){
            md = deg[b];
            mdat = b;
        }
    }
    //bfs
    que.push(mdat);
    visited[mdat] = true;
    int top;
    while(!que.empty()){
        int top = que.front();
        for(int i : adj[top]){
            if(!visited[i]){
                cout << i << " " << top << endl;
                que.push(i);
                //cout << "Visited: " << i << endl;
                visited[i] = true;
            }
        }
        que.pop();
    }
}
