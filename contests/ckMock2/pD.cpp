#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int N, t;
vector <vector <int> > adj;
int weights[5005], xorVal[5005];
bool visited[5005];

void dfs(int currentInd, int currentXor){
    cout << "Running dfs(" << currentInd << ")" << endl;
    xorVal[currentInd] = currentXor ^ weights[currentInd];
    visited[currentInd] = true;
    for(int i = 0; i < adj[currentInd].size(); i++){
        if(!visited[adj[currentInd][i]]){
            dfs(adj[currentInd][i], currentXor ^ weights[currentInd]);
        }
    }
    return;
}

int main(){
    cin >> N;
    adj.clear();
    adj.reserve(N + 2);
    memset(visited, false, N + 1);
    for(int i = 2; i <= N; i++){
        cin >> t;
        adj[i].push_back(t);
        adj[t].push_back(i);
    }
    for(int i = 1; i<= N; i++){
        cin >> t;
        weights[i] = t;
    }
    dfs(1, 0);
    for(int i = 1; i <= N; i++){
        cout << xorVal[i] << endl;
    }

}
