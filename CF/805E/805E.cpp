#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 3e5 + 10;

vector<int> has[maxN], adj[maxN], colour;
int N, M, k, x, maxK, maxAt, u, v;
/*
For one person, all that person's numbers will make it such that it's a perfect graph
therefore the min number of colours needed has a lower bound of max k.

We can colour in arbitrary order all of the person with maxk numbers, and then dfs
for every number that we haven't seen yet just assign a colour with label that is least
and haven't been seen yet (which is mex)
*/
void dfs(int p, int u){
    //cout << "Running dfs "  << p << ", " << u << endl;
    vector<int> alreadyColoured;
    alreadyColoured.push_back(0);
    for(int n : has[u]){
        if(colour[n]){
            alreadyColoured.push_back(colour[n]);
            //cout << "Have " << n << endl;
            //cout << "Adding " << colour[n] << endl;
        }
    }
    sort(alreadyColoured.begin(), alreadyColoured.end());
    int sz = unique(alreadyColoured.begin(), alreadyColoured.end()) - alreadyColoured.begin();
    alreadyColoured.resize(sz);
    int pt = 0, ind = 0;
    if(ind < alreadyColoured.size() && alreadyColoured[ind] == pt){
        while(ind < alreadyColoured.size() && alreadyColoured[ind] == pt){
            pt++;
            ind++;
        }
    } else pt++;

    bool f = false;
    for(int n : has[u]){
        if(!colour[n]){
            //cout << "Don't have " << n << endl;
            //cout << "Setting colour[" << n << "] = " << pt << endl;
            colour[n] = pt++;
            if(ind < alreadyColoured.size() && alreadyColoured[ind] == pt){
                while(ind < alreadyColoured.size() && alreadyColoured[ind] == pt){
                    pt++;
                    ind++;
                }
            }

        }
    }
    for(int x : adj[u]){
        if(x == p) continue;
        dfs(u, x);
    }
}

int main(){
    ericxiao;
    cin >> N >> M;
    colour.resize(M + 1);
    for(int i = 1; i <= N; i++){
        cin >> k;
        has[i].resize(k);
        if(maxK < k){
            maxK = k;
            maxAt = i;
        }
        for(int j = 0; j < k; j++) cin >> has[i][j];
    }
    for(int i = 0; i < N - 1; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, maxAt);
    cout << max(1, maxK) << '\n'; //can be 0...
    for(int i = 1; i <= M; i++){
        cout << (colour[i] ? colour[i] : 1) << " ";
    }
}
