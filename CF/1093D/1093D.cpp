#include <iostream>
#include <vector>
#include <utility>
#include <iomanip>
#define int long long int
using namespace std;

const int MOD = 998244353;

int T, N, M, a, b;
bool canDo;
vector<vector<int> > adj;
vector<int> colour;
vector<bool> visited;

int modexp(int b, int e){
    if(!e) return 1;
    if(e == 1) return b % MOD;
    int res = modexp(b, e/2);
    res = res * res % MOD;
    if(e % 2) res = res * b % MOD;
    return res;
}

pair<int, int> dfs(int current, int c){
    //cout << "Running dfs(" << current + 1<< ", " << c << ")" << endl;
    if(!canDo) return {0, 0};
    colour[current] = c;
    int totalP = 1, totalS = (c == 0);
    for(int e : adj[current]){
        if(!visited[e]){
            visited[e] = true;
            //cout << "GOING TO " << e + 1 << " from " << current + 1 << endl;
            auto ans = dfs(e, (c ? 0 : 1));
            totalP += ans.first;
            totalS += ans.second;
        } else if(colour[e] == c){
            //cout << "NOPE" << endl;
            canDo = false;
            return {0, 0};
        }
    }
    return {totalP, totalS};
}

signed main(){
    cout << fixed;
    cin >> T;
    while(T--){
        cin >> N >> M;
        visited.resize(N);
        adj.clear();
        adj.resize(N);
        colour.clear();
        colour.resize(N);
        fill(colour.begin(), colour.end(), -1); //0, 1
        fill(visited.begin(), visited.end(), false); //0, 1
        for(int i = 0; i < M; i++){
            cin >> a >> b;
            adj[a-1].push_back(b-1);
            adj[b-1].push_back(a-1);
        }
        int ans = 1;
        canDo = true;
        for(int i = 0; i < N && canDo; i++){
            if(!visited[i]){
                visited[i] = true;
                auto p = dfs(i, 0);
                //cout << "P: (" << p.first << ", " << p.second << ")" << endl;
                ans *= ((modexp(2, p.second) + modexp(2, p.first - p.second)) % MOD);
                ans %= MOD;
            }
        }
        if(canDo){
            cout << ans << endl;
        } else {
            cout << 0 << endl;
        }
    }
}
