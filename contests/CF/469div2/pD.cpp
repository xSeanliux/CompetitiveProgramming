#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> status; //1 for win, 0 for draw, -1 for jizz (lose)
vector<bool> visited;
int m, n, c, x, s;

void dfs(int current){
    visited[current] = true;
    int currentThing = -1;
    if(!adj[current].size()){
        cout << current << ": lose" << endl;
        status[current] = -1;
        return;
    }
    for(int i : adj[current]){
        if(visited[i]) currentThing = max(max(0, -status[i]), currentThing);
        else {
            dfs(i);
            currentThing = max(currentThing, -status[i]);
        }
    }
    status[current] = currentThing;
    cout << current << ": " << status[current] << endl;
}

int main(){
    cin >> n >> m;
    adj.resize(n + 1);
    status.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> c;
        adj[i].resize(c);
        for(int j = 0; j < c; j++){
            cin >> adj[i][j];
        }
    }
    cin >> s;
    fill(visited.begin(), visited.end(), false);
    dfs(s);
    if(status[s] == 1) cout << "Win" << endl;
    else if(!status[s]) cout << "Draw" << endl;
    else cout << "Lose" << endl;
}
