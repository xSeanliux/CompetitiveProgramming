#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int n, m, x, y;
vector<vector<pii> > adj;
vector<vector<int> > inDeg;

bool check(int time){
    //cout << "Check(" << time << ")" << endl;
    vector<int> indeg;
    vector<bool> visited;
    indeg.resize(n + 1);
    visited.resize(n + 1);
    fill(visited.begin(), visited.end(), false);
    for(int i = 1; i <= n; i++){
        indeg[i] = upper_bound(inDeg[i].begin(), inDeg[i].end(), time) - inDeg[i].begin();
        //cout << "indeg[" << i << "] = " << indeg[i] << endl; 
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(!indeg[i]){
            q.push(i);
            if(q.size() > 1){
                return false;
            }
        }
    }
    int f;
    while(q.size()){
        f = q.front();
        visited[f] = true;
        //cout << "F = " << f << endl;
        q.pop();
        for(pii e : adj[f]){
            if(e.F > time) break;
            indeg[e.S]--;
            if(!indeg[e.S]) q.push(e.S);
        }
        //cout << q.size() << endl;
        if(q.size() > 1) return false;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i]) return false;
    }
    return true;
}

int main(){
    ericxiao;
    cin >> n >> m; //n dots and m edges
    adj.resize(n + 5);
    inDeg.resize(n + 5);
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        adj[x].push_back({i + 1, y});
        inDeg[y].push_back(i + 1);
    }
    //cout << check(1) << endl;
    if(!check(m)){
        cout << "-1" << endl;
        return 0;
    }
    int l = 0, r = m, mid = (l + r) / 2;
    while(l + 1 < r){
        if(check(mid)){
            r = mid;
        } else {
            l = mid;
        }
        mid = (l + r) / 2;
    }
    cout << r << endl;
}
