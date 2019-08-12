#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

vector<int> dep, ances;
vector<vector<int> > adj;
int N, t, md = 1;

void dfs(int i, int d){
    dep[i] = d;
    md = max(md, d);
    for(int u : adj[i]){
        dfs(u, d + 1);
    }
}

int main(){
    cin >> N;
    dep.resize(N + 1);
    adj.resize(N + 1);
    ances.resize(N + 1);
    fill(dep.begin(), dep.end(), 0);
    for(int i = 1; i <= N; i++){
        cin >> ances[i];
        if(ances[i] != -1) adj[ances[i]].push_back(i);
    }
    for(int i = 1; i <= N; i++){
        if(ances[i] == -1) dfs(i, 1);
    }
    cout << md << endl;
}
