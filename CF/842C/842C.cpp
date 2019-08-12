#include <iostream>
#include <vector>
#include <map>
#define ericxiao ios_base::sync_with_stdio(0);
using namespace std;

const int maxN = 2e5;

vector<int> adj[maxN + 10], vals, ans, divs;
map<int, int> divfrq;
int N, a, b;

int gcd(int a, int b){
    return (!b) ? a : gcd(b, a % b);
}

void dfs1(int p, int c){
    if(c){
        ans[c] = gcd(vals[c], ans[p]);
    }
    for(int u : adj[c]){
        if(u == p) continue;
        dfs1(c, u);
    }
}

void dfs2(int p, int c, int dep){
    for(int d : divs){
        if(!(vals[c] % d)){
            divfrq[d]++;
        }
        if(divfrq[d] >= dep - 1){
            ans[c] = max(ans[c], d);
        }
    }
    for(int u : adj[c]){
        if(u == p) continue;
        dfs2(c, u, dep + 1);
    }
    for(int d : divs){
        if(!(vals[c] % d)){
            divfrq[d]--;
        }
    }
}

int main(){
    ericxiao;
    cin >> N;
    vals.resize(N);
    ans.resize(N);
    for(int i = 0; i < N; i++){
        cin >> vals[i];
    }
    for(int i = 0; i < N - 1; i++){
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans[0] = 0;
    for(int i = 1; i*i <= vals[0]; i++){
        if(!(vals[0] % i)){
            divs.push_back(i);
            if(vals[0] != i * i){
                divs.push_back(vals[0] / i);
            }
        }
    }
    dfs1(0, 0);
    dfs2(0, 0, 1);
    for(int i = 0; i < N; i++){
        cout << ans[i] << " \n"[i == N - 1];
    }
}
