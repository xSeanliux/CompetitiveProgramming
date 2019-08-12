#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;

int T, N, M, a, b, c = 0;
vector<vector<int> > adj, rev;
vector<int> ord, head;
bitset<10000> visited, inZero;

void dfs1(int x){
    //cout << "running dfs(" << x << ")" << endl;
    for(int i : adj[x]){
        if(!visited[i]){
            visited[i] = true;
            dfs1(i);
        }
    }
    ord.push_back(x);
}

void dfs2(int x, int ori){
    //cout << x << " ";
    head[x] = ori;
    for(int i : rev[x]){
        if(!visited[i]){
            visited[i] = true;
            dfs2(i, ori);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> M;
        adj.reserve(N + 1);
        rev.reserve(N + 1);
        head.reserve(N + 1);
        for(int i = 1; i <= N; i++){
            adj[i].clear(); rev[i].clear(); //remember to clear the inside otherwise WA
        }
        head.clear();
        ord.clear();
        for(int i = 0; i < M; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            rev[b].push_back(a);
        }
        visited.reset(); //set everything to 0
        for(int i = 1; i <= N; i++)
            if(!visited[i]){
                visited[i] = true;
                dfs1(i);
            }
        visited.reset();
        //for(int i : ord) cout << i << endl;
        for(int i = ord.size() - 1; i >= 0; i--){
            if(!visited[ord[i]]){
                visited[ord[i]] = true;
                dfs2(ord[i], ord[i]);
                //cout << "|" <<  endl;
            }
        }
        inZero.set(); //all in = zero
        for(int i = 1; i <= N; i++){
            for(int j : adj[i]){
                if(head[i] != head[j]) inZero[head[j]] = false;
            }
        }
        int ans = 0;
        for(int i = 1; i <= N; i++){
            if(head[i] == i && inZero[i]) ans++;
        }
        cout << "Case " << ++c << ": " << ans << endl;
    }
}
