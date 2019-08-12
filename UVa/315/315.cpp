#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector< vector<int> > adj;
vector<int> low, depth;
vector<bool> visited, isCut;
string s;
int nodecnt;

void dfs(int id, int nowdepth){
    //printf("Running dfs of %d with depth %d\n", id, nowdepth);
    depth[id] = nowdepth;
    visited[id] = true;
    low[id] = nowdepth;
    isCut[id] = false;
    int sons = 0;
    for(int i : adj[id]){
        if(visited[i]){
            if(depth[i] < low[id]) low[id] = depth[i];
        } else {
            dfs(i, nowdepth + 1);
            sons++;
            if(low[i] < low[id]) low[id] = low[i];
            else if(low[i] >= depth[id]) {
                isCut[id] = true;
                //cout << id << " is a point!" << endl;
            }
            //cout << "low[" << i << "] = " << low[i] << ", low[" << id << "] = " << low[id] << endl;

        }
    }
    if(!nowdepth) isCut[id] = sons > 1;
}

int main(){

    while(cin >> nodecnt){
        if(!nodecnt) return 0;
        //boring init
        adj.clear();
        low.clear();
        depth.clear();
        visited.clear();
        isCut.clear();
        adj.resize(  nodecnt + 1  );
        low.resize(  nodecnt + 1  );
        depth.resize(nodecnt + 1  );
        //actual algorithm
        for(int i = 0; i <= nodecnt; i++){
            isCut.push_back(false);
            visited.push_back(false);
        }
        getline(cin, s);
        stringstream stream(s);
        while(getline(cin, s)){
            stream = stringstream(s);
            if(s == "0") break;
            int startNode;
            stream >> startNode;
            for(int n; stream >> n;){
                adj[    n    ].push_back(startNode);
                adj[startNode].push_back(    n    );
            }
        }
        dfs(1, 0);
        int ans = 0;
        for(int i = 1; i <= nodecnt; i++){
            ans += isCut[i];
        }
        cout << ans << endl;
    }
}
