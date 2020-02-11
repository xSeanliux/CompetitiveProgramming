#include <iostream>
#include <vector>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 1e6 + 10;

vector<int> adj[maxN], radj[maxN], ans;
bool visited[maxN];

int t, n, m, a, b;

void getSz(int x, bool b){ //0 for no reverse, 1 for reverse
    //cout << "Getting to " << x << " with params " << b << endl;
    visited[x] = true;
    ans.push_back(x);
    for(int u : (b ? adj : radj)[x]){
        if(visited[u]) continue;
        getSz(u, b);
    }
}

int main(){
    ericxiao;
    cin >> t;
    while(t--){
        cin >> n >> m;
        fill(visited, visited + n + 1, false);
        for(int i = 1; i <= n; i++){
            adj[i].resize(0);
            radj[i].resize(0);
        }
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            if(a == b) continue;
            adj[a].push_back(b);
            radj[b].push_back(a);
            //cout << "Pushing " << a << ", " << b << endl;
            //cout << "adj[" << a << "].size() = " << adj[a].size() << endl;
        }
        ans.resize(0);
        getSz(1, 0);
        if(ans.size() == n || ans.empty()){
            ans.resize(0);
            fill(visited, visited + n + 1, false);
            getSz(1, 1);
            if(ans.size() == n || ans.empty()){
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
                cout << ans.size() << " " << n - ans.size()  << endl;
                for(int i : ans) cout << i << " ";
                cout << endl;
                for(int i = 1; i <= n; i++){
                    if(!visited[i]) cout << i << " ";
                }
                cout << endl;

            }
        } else {
            cout << "Yes" << endl;
            cout << n - ans.size() << " " << ans.size() << endl;
            for(int i = 1; i <= n; i++){
                if(!visited[i]) cout << i << " ";
            }
            cout << endl;
            for(int i : ans) cout << i << " ";
            cout << endl;
        }
    }
}
