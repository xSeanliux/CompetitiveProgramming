#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

const int W = 26;

int t;
string s, ans;

bool am[W][W], visited[W];
vector<int> adj[W], shunxu;

void dfs(int p, int u){
    shunxu.push_back(u);
    visited[u] = true;
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(u, v);
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> s;
        shunxu.clear();
        for(int i = 0; i < W; i++){
            visited[i] = 0;
            vector<int>().swap(adj[i]);
            for(int j = 0; j < W; j++) am[i][j] = 0;
        }
        for(int i = 0; i < s.length() - 1; i++){
            am[ s[i] - 'a' ][ s[i + 1] - 'a' ] = am[ s[i + 1] - 'a' ][ s[i] - 'a' ] = 1;
        }
        for(int i = 0; i < W; i++){
            for(int j = 0; j < i; j++){
                if(am[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        bool can = true;
        for(int i = 0; i < W; i++) if(adj[i].size() > 2){
            cout << "NO" << endl;
            can = false;
            break;
        }
        if(!can) continue;
        for(int i = 0; i < W; i++) if(!visited[i] && adj[i].size() <= 1) dfs(i, i);
        if(shunxu.size() < 26){
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        for(int x : shunxu) cout << (char)(x + 'a');
        cout << endl;
    }
}
