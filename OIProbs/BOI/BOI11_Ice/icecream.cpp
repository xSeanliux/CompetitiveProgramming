#include <iostream>
using namespace std;

const int maxN = 226;
int N, M, u, v, ans;
bool adj[maxN][maxN];

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> u >> v;
        adj[u][v] = adj[v][u] = true;
    }
    for(int i = 1; i <= N; i++){
        for(int j = 1; j < i; j++){
            if(adj[i][j]) continue;
            for(int k = 1; k < j; k++){
                ans += (!adj[i][k] && !adj[j][k]);
            }
        }
    }
    cout << ans << endl;
}
