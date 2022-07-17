#include <iostream>
using namespace std;

const int maxC = 26, INF = 1e9;
int t, dist[30][30];

inline void solve(){
    string s, e;
    int K;
    cin >> s >> K;
    for(int i = 0; i < maxC; i++){
        for(int j = 0; j < maxC; j++){
            dist[i][j] = (i == j ? 0 : INF);
        }
    }
    while(K--){
        cin >> e;
        dist[e[0] - 'A'][e[1] - 'A'] = 1;
    }
    for(int k = 0; k < maxC; k++){
        for(int i = 0; i < maxC; i++){
            if(dist[i][k] == INF) continue;
            for(int j = 0; j < maxC; j++){
                if(dist[k][j] == INF) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int ans = INF, res;
    for(char c = 'A'; c <= 'Z'; c++){
        bool can = true;
        res = 0;
        for(char ch : s){
           if(dist[ch - 'A'][c - 'A'] == INF){
               can = false;
           } else res += dist[ch - 'A'][c - 'A'];
        }
        if(can){
            ans = min(ans, res);
        }
    }
    if(ans == INF) ans = -1;
    cout << "Case #" << ++t << ": " << ans << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
}

