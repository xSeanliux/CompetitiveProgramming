#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

const int maxN = 2e5 + 326;
set<int> dagAdj[maxN]; //reversed weights to topo sort

int N, M, H, mainTime[maxN], a, b, ssc[maxN], cnt = 0, w[maxN], dp[maxN], indeg[maxN];
bool dagvis[maxN];
queue<int> que;
vector<int> ans;

struct SSC{
    vector<int> adj[maxN], rev[maxN];
    int cnt, belong[maxN];
    bool vis[maxN];
    vector<int> ord;
    inline void addEdge(int u, int v){
        //cout << "Original Graph: " << u << " -> " << v << endl;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }
    SSC(){
        cnt = 0;
        fill(belong, belong + maxN, 0);
        fill(vis, vis + maxN, 0);
    }
    void dfs(int now){
        vis[now] = true;
        for(int x : adj[now]){
            if(!vis[x]){
                dfs(x);
            }
        }
        ord.push_back(now);
    }
    void revDfs(int now, int num){
        belong[now] = num; 
        vis[now] = true;
        for(int x : rev[now]){
            if(!vis[x]){
                revDfs(x, num);
            }
        }
    }
    inline void run(){
        ord = vector<int>();
        for(int i = 1; i <= N; i++) if(!vis[i]) dfs(i);
        reverse(ord.begin(), ord.end());
        fill(vis, vis + maxN, 0);
        for(int x : ord){
            if(!vis[x]){
                cnt++;
                revDfs(x, cnt);
            }
        }
    }
    void ansDfs(int now){
        ans.push_back(now);
        vis[now] = true;
        for(int x : adj[now]){
            if(!vis[x]) ansDfs(x);
        }
    }
    void getAll(int now){
       fill(vis, vis + maxN, 0); 
       ansDfs(now);
    }
} kosaraju;

int main(){
    cin >> N >> M >> H;
    for(int i = 1; i <= N; i++){
        cin >> mainTime[i];
    }
    for(int i = 0; i < M; i++){
        cin >> a >> b;
        if((mainTime[a] + 1) % H == mainTime[b]){
            kosaraju.addEdge(a, b);
        }
        if((mainTime[b] + 1) % H == mainTime[a]){
            kosaraju.addEdge(b, a);
        }
    }
    kosaraju.run();
    //cout << "SSCs: " << kosaraju.cnt << endl;
    for(int i = 1; i <= N; i++){
        w[kosaraju.belong[i]]++;
        for(int x : kosaraju.adj[i]){
            if(kosaraju.belong[i] != kosaraju.belong[x]){
                if(!dagAdj[kosaraju.belong[x]].count(kosaraju.belong[i])) indeg[kosaraju.belong[i]]++;
                dagAdj[kosaraju.belong[x]].insert(kosaraju.belong[i]);
            }
        }
    }
    int sccN = kosaraju.cnt;
    int minAt = -1;
    for(int i = 1; i <= sccN; i++){
        dp[i] = w[i];
        if(!indeg[i]){
            if(minAt == -1 || w[minAt] > w[i]) minAt = i;
        }
    }
    //for(int i = 1; i <= N; i++){
    //    cout << i << ": " << kosaraju.belong[i] << endl;
    //}
    for(int i = 1; i <= N; i++){
        if(kosaraju.belong[i] == minAt){
            kosaraju.getAll(i);
            break;
        }
    }
    cout << ans.size() << endl;
    for(int x : ans){
        cout << x << " ";
    }
    cout << endl;
}
