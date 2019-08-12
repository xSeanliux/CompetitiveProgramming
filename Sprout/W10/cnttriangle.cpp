#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <map>
#include <bitset>
#define F first
#define S second
using namespace std;

vector<int> deg;
map<int, int> heavyInd;
bitset<100000> isAdj; //dynamic
vector<vector<int> > adj;
vector<bitset<100000> > heavyAdj;
vector<pair<int, int> > allEdges;
int N, M, max_deg, a, b;

int main(){
    cin >> N >> M;
    max_deg = 700; //sqrt(M) will MLE
    deg.resize(N);
    adj.resize(N);
    allEdges.resize(M);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        deg[a]++;
        deg[b]++;
        allEdges[i] = {a, b};
    }
    //precompute heavyAdj
    bitset<100000> _v;
    int currentInd = 0;
    for(int i = 0; i < N; i++){
        if(deg[i] >= max_deg){
            heavyInd[i] = currentInd;
            _v.reset();
            for(int u : adj[i]){
                _v[u] = true;
            }
            heavyAdj.push_back(_v);
            currentInd++;
        }
    }
    //cout << "SZ: " << heavyAdj.size() << endl;
    int ans = 0;
    for(int i = 0; i < M; i++){
        if(deg[allEdges[i].F] >= max_deg){ //use allEdges[i].S
            for(int u : adj[allEdges[i].S]){
                //cout << "Checking " << u << " that's connected to " << allEdges[i].S << endl;
                ans += heavyAdj[heavyInd[allEdges[i].F]][u];
            }
        } else if(deg[allEdges[i].S] >= max_deg){
            for(int u : adj[allEdges[i].F]){
                //cout << "Checking " << u << " that's connected to " << allEdges[i].F << endl;
                ans += heavyAdj[heavyInd[allEdges[i].S]][u];
            }
        } else { //light - light
            isAdj.reset();
            for(int u : adj[allEdges[i].F]){
                isAdj[u] = true;
            }
            for(int v : adj[allEdges[i].S]){
                ans += isAdj[v];
            }
        }
    }
    cout << ans/3 << endl;
}

