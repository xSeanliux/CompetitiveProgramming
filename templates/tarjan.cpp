#include <iostream>
#include <vector>
#define N 1000
using namespace std;

class Tarjan{
    vector<int, int> adj;
    int[N] low, disc;

    Tarjan(int N){
        adj.clear();
        adj.resize(N);
    }

    void addEdge(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    void DFS(int c, int p){
        visited[c] = true;
        low[c] = low[p];

    }


};

int main(){

}

