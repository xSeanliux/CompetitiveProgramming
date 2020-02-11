#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
/*
https://www.youtube.com/watch?v=VIkQSuZbbt0
*/
using namespace std;

const int maxN = 2005;

vector<int> adj[maxN], loop, ord, pos;
vector<bool> visited;
vector<pii> edges;
int n, m, a, b;
bool hasLoop = false;

void getLoop(int x, int p){
    //cout << "Visiting " << x << endl;
    if(hasLoop) return;
    visited[x] = true;
    ord[p] = x;
    pos[x] = p;
    //cout << "pos[" << x << "] = " << p << endl;
    for(int u : adj[x]){
        //cout << "Looking at " << u << endl;
        if(visited[u]){ //good, build loop
            //cout << "LOOP" << endl;
            for(int v = pos[u]; v <= p; v++){
                loop.push_back(ord[v]);
            }
            hasLoop = true;
            visited[x] = false;
            return;
        }
        getLoop(u, p + 1);
        if(hasLoop){
            visited[x] = false;
            return;
        }
    }
    visited[x] = false;

}

int main(){
    ericxiao;
    cin >> n >> m;
    loop.clear();
    ord.resize(n + 1);
    pos.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        edges.push_back({a, b});
        adj[a].push_back(b);
    }
    //try to get loop
    fill(visited.begin(), visited.end(), false);
    for(int i = 1; i <= n && !hasLoop; i++){
        ord.clear();
        fill(visited.begin(), visited.end(), false);
        //cout << "GETTINLOOP " << i << endl;
        getLoop(i, 0);
    }
    if(!hasLoop){ //NOT POSSIBLE
        cout << -1 << endl;
        return 0;
    }

    fill(pos.begin(), pos.end(), -1);
    for(int i = 0; i < loop.size(); i++){
        pos[loop[i]] = i;
    }
    //cout << "LOOP: "<<endl;
    //for(int u : loop) cout << u << " "; cout << endl;
    for(pii p : edges){
        //cout << "Looking at " << p.F << ", " << p.S << endl;
        if(pos[p.F] == -1 || pos[p.S] == -1) continue;
        if((pos[p.F] + 1) % loop.size() == pos[p.S] % loop.size()) continue;

        //cout << "pos[" << p.F << "] = " << pos[p.F] << endl;
        //cout << "pos[" << p.S << "] = " << pos[p.S] << endl;
        if(pos[p.F] < pos[p.S]){ //delete (p.F, p.S)
            for(int i = pos[p.F] + 1; i < pos[p.S]; i++){
                if(loop[i] > 0){
                    //cout << "Deleting " << loop[i] << endl;
                    pos[loop[i]] = -1;
                    loop[i] = -1;
                }

            }
        } else { //delete the outside [1, p.S) and (p.F, end]
            for(int i = 0; i < pos[p.S]; i++){
                //cout << "i = " << i << endl;
                if(loop[i] > 0){
                    //cout << "Deleting " << loop[i] << endl;
                    pos[loop[i]] = -1;
                    loop[i] = -1;
                }
            }
            for(int i = pos[p.F] + 1; i < loop.size(); i++){
                if(loop[i] > 0){
                    //cout << "Deleting " << loop[i] << endl;
                    pos[loop[i]] = -1;
                    loop[i] = -1;
                }
            }
        }
    }
    vector<int> ans;
    for(int u : loop) if(u > 0) ans.push_back(u);

    cout << ans.size() << endl;
    for(int u : ans) cout << u << endl;

}
