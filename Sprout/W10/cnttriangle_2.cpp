#include <iostream>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <utility>
#define int long long int
using namespace std;


int N, M, K, a, b, trueCnt = 0;
vector<vector<int> > edges, queries;
set<pair<int, int> > allEdges;
vector<int> deg;



bool Query(int a, int b){ //=hasedge
    //cout << "Query(" << a << ", " << b << ") = " << allEdges.count({min(a, b), max(a, b)}) << endl;
    return allEdges.count({min(a, b), max(a, b)});
}

void getQueries(){
    queries.clear();
    queries.resize(N + 1);
    for(int i = 0; i < N; i++){
        //cout << "For dot " << i << " with deg" << deg[i] << ", K = " << K << endl;
        if(deg[i] >= K){ //check all its edges
            //cout << "Checking all edges" << endl;
            for(auto p : allEdges){
                if(p.first != i && p.second != i){
                    trueCnt += (Query(p.first, i) && Query(i, p.second));
                }
            }
        } else { //check all its neibouring thingies
            for(int j = 0; j < edges[i].size(); j++){
                for(int k = j + 1; k < edges[i].size(); k++){
                    trueCnt += Query(edges[i][j], edges[i][k]);
                }
            }
        }
    }
}


signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    K = sqrt(M);
    edges.resize(N + 2);
    deg.resize(N + 1);
    queries.resize(N + 1);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
        deg[a]++, deg[b]++;
        allEdges.insert({min(a, b), max(a, b)});
    }
    getQueries();
    cout << trueCnt/3 << endl;
}
