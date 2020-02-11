#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int,int>
#define ppi pair<pii, int>
#define F first
#define S second
#define int long long int
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

int n, minCost = 0;
vector<pii> pos;
vector<int> cost, k;
priority_queue<ppi, vector<ppi>, greater<ppi> > pq;
vector<bool> visited;
vector<pii> con;
vector<int> light;
inline int Abs(int x){
    return x > 0 ? x : -x;
}

inline int getCost(int i, int j){
    return (Abs(pos[i].F - pos[j].F) + Abs(pos[i].S - pos[j].S)) * (k[i] + k[j]);
}

signed main(){
    ericxiao;
    cin >> n;
    pos.resize(n);
    cost.resize(n);
    k.resize(n);
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);
    for(int i = 0; i < n; i++) cin >> pos[i].F >> pos[i].S;
    for(int i = 0; i < n; i++) cin >> cost[i];
    for(int i = 0; i < n; i++) cin >> k[i];
    for(int i = 0; i < n; i++) pq.push({{cost[i], i}, -1}); //{ {minDist, id}, from }
    ppi re;
    int cnt = 0;
    while(cnt < n){
        re = pq.top();
        pq.pop();
        if(visited[re.F.S]) continue;
        visited[re.F.S] = true;
        minCost += re.F.F;
        if(re.S == -1){
            light.push_back(re.F.S);
        } else {
            con.push_back({re.S, re.F.S});
        }
        for(int i = 0; i < n; i++){
            if(visited[i]) continue;
            pq.push({{getCost(i, re.F.S), i}, re.F.S});
        }
        cnt++;
    }
    cout << minCost << endl;
    cout << light.size() << endl;
    for(int l : light) cout << l + 1 << " ";
    cout << endl;
    cout << con.size() << endl;
    for(pii p : con) cout << p.F + 1 << " " << p.S + 1 << endl;
}
