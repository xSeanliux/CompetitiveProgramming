#include <iostream>
#include <vector>
#include <utility>
#define pii pair<int,int>
#define F first
#define S second
using namespace std;

const int maxN = 2e3 + 20, INF = 1e8;
int n, m, a, b, c;
vector<int> minDist;
vector<pair<pii, int> > edges;

bool relax(){
    bool res = false;
    for(auto e : edges){
        if(minDist[a] > minDist[b] + e.S || minDist[b] > minDist[a] + e.S) res = true;
        minDist[a] = min(minDist[a], minDist[b] + e.S);
    }
    return res;
}

int main(){
    cin >> n >> m;
    minDist.resize(n + 1);
    edges.resize(m);
    fill(minDist.begin(), minDist.end(), INF);
    minDist[1] = 0;
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        edges[i] = {{a, b}, c};
    }
    for(int i = 0; i < n - 1; i++){
        relax();
    }
    if(relax())
        cout << "YES" << endl;
    else cout << "NO" << endl;
}



