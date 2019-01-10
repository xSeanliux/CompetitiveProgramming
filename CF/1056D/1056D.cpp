#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <vector <int> > adj;

int leafSize[100000 + 1];

void dfs(int ind){
    if(adj[ind].size() == 0){
        leafSize[ind] = 1;
    } else {
        for(int i = 0; i < adj[ind].size(); i++){
            dfs(adj[ind][i]);
            leafSize[ind] += leafSize[adj[ind][i]];
        }
    }
}

int main(){
    int N, to;
    scanf("%d", &N);
    vector<int> v;
    adj.push_back(v);
    for(int i = 1; i <= N; i++){
        leafSize[i] = 0;
        adj.push_back(v);
    }
    for(int i = 2; i <= N; i++){
        scanf("%d", &to);
        adj[to].push_back(i);
    }
    dfs(1); //inits the subtree size
    sort(leafSize + 1, leafSize + N + 1);
    for(int i = 1; i <= N; i++){
        cout << leafSize[i] << " ";
    }

}
