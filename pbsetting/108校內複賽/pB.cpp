#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <numeric>
#define ericxiao ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

const int maxN = 1e5;

vector<int> adj[maxN + 10];
vector<int> maxDown, ord;
bool visited[maxN + 10];
int N, t, k, ans = 0;

void getDown(int p, int c){ //love the name lol
    int r = 0;
    for(int u : adj[c]){
        if(u == p) continue;
        getDown(c, u);
        r = max(r, maxDown[u]);
    }
    maxDown[c] = r + 1;
}

void del(int c, int l){
    if(!visited[c]){
        ans++;
        visited[c] = true;
    }
    for(int u : adj[c]){
        if(maxDown[u] == l - 1){
            del(u, l - 1);
            return;
        }
    }
}


int main(){
    ericxiao;
    cin >> N >> k;
    maxDown.resize(N + 1);
    ord.resize(N + 1);
    fill(visited, visited + N + 1, false);
    for(int i = 1; i <= N; i++){
        cin >> t;
        adj[t].push_back(i);
        adj[i].push_back(t);
    }
    getDown(0, 0);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [](int a, int b){
        return maxDown[a] > maxDown[b];
    });
    int ops = 0;
    for(int i = 0; i <= N && ops < k; i++){
        if(!visited[ord[i]]){
            ops++;
            del(ord[i], maxDown[ord[i]]);
        }
    }
    cout << (N + 1) - ans << endl;
}

