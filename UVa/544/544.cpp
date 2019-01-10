#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <map>
#define INF 2147483647
using namespace std;

map <string, vector<pair<string, int> > > adj;
map <string, bool> visited;
map <string, int> mL;
int N, M, W, maxAns, sce = 0;
string a, b;

void dfs(string currentNode, int currentMin){
    if(currentMin < maxAns) return;
    if(currentNode == b && currentMin > maxAns) maxAns = currentMin;
    else {
        int l = adj[currentNode].size();
        for(int i = 0 ; i < l; i++){
            if(!visited[adj[currentNode][i].first]){
                visited[adj[currentNode][i].first] = true;
                dfs(adj[currentNode][i].first, min(currentMin, adj[currentNode][i].second));
                visited[adj[currentNode][i].first] = false;
            }
        }
    }
}

int main(){
    while(cin >> N >> M){
        if(!(N || M)) return 0;
        adj = map <string, vector<pair<string, int> > >();
        visited = map <string, bool>();
        queue <string> que;
        mL = map <string, int>();
        for(int i = 0 ; i < M; i++){
            cin >> a >> b >> W;
            if(!adj.count(a)){
                vector <pair<string, int> > v;
                v.push_back(pair<string, int>(b, W));
                adj.insert(pair<string, vector<pair<string, int> > >(a, v));
                visited.insert(pair<string, bool>(a, false));
                mL.insert(pair<string, int>(a, -1));
            } else {
                adj[a].push_back(pair<string, int>(b, W));
            }
            if(!adj.count(b)){
                vector <pair<string, int> > v;
                v.push_back(pair<string, int>(a, W));
                adj.insert(pair<string, vector<pair<string, int> > >(b, v));
                visited.insert(pair<string, bool>(b, false));
                mL.insert(pair<string, int>(b, -1));
            } else {
                adj[b].push_back(pair<string, int>(a, W));
            }
        }
        maxAns = -1;
        cin >> a >> b; //now go for DFS
        que.push(a);
        mL[a] = INF;
        while(!que.empty()){
            while(visited[que.front()])
                que.pop();
            string s = que.front();
            //cout << s << endl;
            int l = adj[s].size();
            for(int i = 0 ; i < l; i++){
                mL[adj[s][i].first] = max(mL[adj[s][i].first], min(mL[s], adj[s][i].second));
                que.push(adj[s][i].first);
                //cout << "pushing " << adj[s][i].first << endl;
            }
            visited[s] = true;
        }
        //cout << "H" << endl;
        printf("Scenario #%d\n%d tons\n\n", ++sce, mL[b]);
    }

}
