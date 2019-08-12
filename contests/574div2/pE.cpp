#include <iostream>
#include <deque>
#include <utility>
#define pii pair<int,int>
#define int long long int
using namespace std;

const int maxN = 3000, INF = 1e9;
int val[maxN + 10][maxN + 10];

int N, M, a, b, g, x, y, z;

void init(){
    val[0][0] = g;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!i && !j) continue;
            if(!j){
                val[i][j] = (val[i - 1][M - 1] * x + y) % z;
            } else{
                val[i][j] = (val[i][j - 1] * x + y) % z;
            }
        }
    }
}


signed main(){
    cin >> N >> M >> a >> b >> g >> x >> y >> z;
    init();

    deque<pii> dq;
    int minV[N][M];
    pii p;
    for(int j = 0; j < M; j++){
        dq = deque<pii>();
        for(int i = 0; i < N; i++){
            p = {val[i][j], i};
            while(dq.size() && i - dq.front().second >= a){
                dq.pop_front();
            }
            while(dq.size() && val[i][j] <= dq.back().first){
                dq.pop_back();
            }
            dq.push_back(p);
            minV[i][j] = dq.front().first;
        }
    }
    int ans = 0;
    dq = deque<pii>();
    for(int i = a - 1; i < N; i++){
        dq = deque<pii>();
        for(int j = 0; j < M; j++){
            p = {minV[i][j], j};
            while(dq.size() && j - dq.front().second >= b){
                dq.pop_front();
            }
            while(dq.size() && dq.back().first >= minV[i][j]){
                dq.pop_back();
            }
            dq.push_back(p);
            if(j >= b - 1) ans += dq.front().first;
        }


    }
    cout << ans << endl;
}
