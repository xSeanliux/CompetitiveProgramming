#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, a, b, c = 0, cuts;
vector<vector<int> > adj;
vector<int> low, depth, currentComponent;
vector<bool> isCut, visited, used;
set<int> cutSet;

void tarjan(int X, int dep){
    if(!used[X]) return;
    //cout << "Running tarjan(" << X << ", " << dep << ")" << endl;
    //cout << "ST" << endl;
    visited[X] = true;
    depth[X] = dep;
    low[X] = depth[X];
    int sons = 0;
    for(int c : adj[X]){
        if(visited[c]){
            low[X] = min(depth[c], low[X]);
        } else {
            sons++;
            tarjan(c, dep + 1);
            if(low[c] >= depth[X]) isCut[X] = true;
            low[X] = min(low[X], low[c]);
        }
    }
    //cout << "END" << endl;
    if(!dep) isCut[X] = (sons > 1);
}

void dfs(int x){
    visited[x] = true;
    currentComponent.push_back(x);
    if(isCut[x]) return;
    for(int i : adj[x]){
        if(isCut[i]) cutSet.insert(i);
        if(isCut[i] || visited[i]) continue;
        dfs(i);
    }
}

int main(){
    while(scanf("%d", &N)){
        if(!N) return 0;

        //cout << "Done" << endl;
        adj.reserve(N + 2);
        isCut.reserve(N + 2);
        visited.reserve(N + 2);
        used.reserve(N + 2);
        low.reserve(N + 2);
        depth.reserve(N + 2);
        //cout << "Done" << endl;
        for(int i = 0; i <= N + 1; i++){
            adj[i] = vector<int>();
            used[i] = false;
            isCut[i] = false;
            visited[i] = false;
        }
        //cout << "Done" << endl;
        int usedN = 0;
        for(int i = 0; i < N; i++){
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
            used[a] = true; used[b] = true;
        }
        for(int i = 1; i <= N + 1; i++) usedN += used[i];
        //cout << "";
        for(int i = 1; i <= N + 1; i++){
            if(!visited[i] && used[i]) tarjan(i, 0);
        }
        //cout << "Finished tarjan" << endl;
        for(int i = 1; i <= N + 1; i++){
            //if(used[i]){
            //    cout << "isCut[" << i << "] = " << isCut[i] << endl;
            //}
            visited[i] = false;
        }
        long long int cCount = 0, ways = 1;
        bool flag = false;
        for(int i = 1; i <= N + 1; i++){
            if(!visited[i] && !isCut[i]){
                currentComponent.clear();
                cutSet.clear();
                dfs(i);
                //cout << "Found component" << endl;
                //for(int c : currentComponent) cout << c << endl;
                //cout << endl;
                //cout << cuts << " cuts " << endl;
                if (cutSet.size() == 1) {
                    ways *= currentComponent.size();
                    flag = true;
                    cCount++;
                }
            }
        }
        if(!flag) cCount = 2, ways = usedN * (usedN - 1) / 2;
        printf("Case %d: %lld %lld\n", ++c, cCount, ways);
    }
}

