#include <iostream>
#define int long long int
using namespace std;

const int INF = 1e15;

int N, M, Q, minDist[210][210], a, b, w;

signed main(){
    while(cin >> N >> M >> Q){
        if(!N && !M && !Q) return 0;
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                minDist[i][j] = INF;
            }
            minDist[i][i] = 0;
        }
        for(int i = 0; i < M; i++){
            cin >> a >> b >> w;
            minDist[a][b] = w;
            minDist[b][a] = w;
        }
        for(int k = 1; k <= N; k++){
            for(int i = 1; i <= N; i++){
                for(int j = 1; j <= N; j++){
                    if(i == j || i == k || j == k) continue;
                    minDist[i][j] = min(minDist[i][j], minDist[i][k] + minDist[k][j]);
                }
            }
        }
        for(int i = 0; i < Q; i++){
            cin >> a >> b;
            if(minDist[a][b] == INF) cout << -1 << endl;
            else cout << minDist[a][b] << endl;
        }
    }
}

