#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 2e5;
int N, M, a, b, dsu[maxN + 10], sz[maxN + 10];
bool visited[maxN + 10];
set<int> sts[maxN + 10];
set<int> want;

int bfs(int x){
    //cout << "Running dfs(" << x << ")" << endl;
    int res = 1;
    queue<int> q = queue<int>();
    q.push(x);
    visited[x] = true;

    while(q.size()){
        int u = q.front();
        //cout << "u = " << u << endl;
        q.pop();
        vector<int> tmp = vector<int>();
        for(int v : want){
            //cout << "V = " << v << endl;
            if(!sts[u].count(v) && !visited[v]){
                visited[v] = true;
                tmp.push_back(v);
                q.push(v);
                res++;
            }
        }
        for(int i : tmp){
            want.erase(i);
        }
    }
    return res;
}

int main(){
    ericxiao;
    cin >> N >> M;
    fill(visited, visited + N, false);
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        a--;
        b--;
        sts[a].insert(b);
        sts[b].insert(a);
    }

    vector<int> ans;
    for(int i = 0; i < N; i++){
        if(!visited[i]){
            want = set<int>();
            for(int j = 0; j < N; j++){
                if(i != j && !visited[j]){
                    want.insert(j);
                }
            }
            ans.push_back(bfs(i));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int u : ans){
        cout << u << " ";
    }
}
