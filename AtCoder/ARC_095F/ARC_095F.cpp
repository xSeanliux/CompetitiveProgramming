#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
using namespace std;

const int maxN = 2e5 + 10;

int N, u, v;
vector<int> adj[maxN];
vector<int> ans, dia;

pii getFar(int p, int u){
    pii pp = {0, u};
    for(int v : adj[u]){
        if(v == p) continue;
        pp = max(getFar(u, v), pp);
    }
    pp.F++;
    //cout << "Res for u = " << u << ": " << pp.F << ", " << pp.S << endl;
    return pp;
}

inline void getDia(int a){
    int current = a, prev = a;
    dia.push_back(a);
    current = adj[current][0];
    bool hasFound;
    while(true){
        //cout << "Current = " << current << endl;
        dia.push_back(current);
        hasFound = false;
        if(adj[current].size() == 1) break;
        else{
            for(int u : adj[current]){
                if(u == prev) continue;
                if(adj[u].size() > 1){
                    prev = current;
                    current = u;
                    hasFound = true;
                    break;
                }
            }
            if(!hasFound){
                for(int u : adj[current]){
                    if(adj[u].size() == 1){
                        current = u;
                        break;
                    }
                }
            }
        }
    }
}

vector<int> getPer(vector<int> dia){
    bool isRoot = true;
    vector<int> res = vector<int>(N);
    int currentId = 0, cnt = 1, sz, lim;
    for(int u : dia){
        //cout << "Checking u = " << u << endl;
        if(adj[u].size() == 1){
            sz = adj[u].size() - 1;
        } else {
            sz = adj[u].size() - 2;
        }
        //cout << "sz = " << sz << endl;
        res[currentId + sz] = cnt++;
        lim = currentId + sz;
        for(; currentId < lim; currentId++) res[currentId] = cnt++;
        currentId++;
        //for(int u : res) cout << u << " "; cout << endl;
    }
    return res;
}

bool isLess(vector<int> a, vector<int> b){
    for(int i = 0; i < N; i++){
        if(a[i] < b[i]) return true;
        else if(a[i] > b[i]) return false;
    }
}

int main(){
    ericxiao;
    cin >> N;
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pii p1 = getFar(1, 1), p2;
    int a = p1.S;
    p2 = getFar(a, a);
    int b = p2.S;
    // cout << a << " " << b << endl;
    getDia(a);
    int sum = 0;
    for(int u : dia){
        if(adj[u].size() == 1) sum++;
        else sum += adj[u].size() - 1;
    }
    if(sum != N){
        cout << -1 << endl;
        return 0;
    }
    //cout << "DIA: " << endl;
    //for(int u : dia) cout << u << " "; cout << endl;
    vector<int> res1 = getPer(dia);

    for(int u : res1){
        if(!u){
            cout << -1 << endl;
            return 0;
        }
    }
    reverse(dia.begin(), dia.end());
    vector<int> res2 = getPer(dia);
    if(isLess(res1, res2)){
        for(int u : res1) cout << u << " ";
    } else {
        for(int u : res2) cout << u << " ";
    }
    cout << endl;

}
