#include <iostream>
#include <vector>
#include <math.h>
#define int long long int
using namespace std;

const int maxN = 2000;
const double PI = acos(-1);

vector<int> childs[maxN];
int dp[maxN][2][2], parent[maxN];

struct Circ{
    int x, y, r;
    Circ(){}
    Circ(int xx, int yy, int rr): x(xx), y(yy), r(rr){}
} circs[maxN];

bool isIn(Circ a, Circ b){ //a is in b?
    return (b.r >= a.r) && (((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) <= (b.r - a.r) * (b.r - a.r));
}

int N, x, y, r;

void dfs(int v){
    int g[2][2] = {{ 0 }};

    for(int u : childs[v]){
        dfs(u);
        for(int i = 0; i <= 1; i++)
            for(int j = 0; j <= 1; j++)
                g[i][j] += dp[u][i][j];
    }

    for(int i = 0; i <= 1; i++){
        for(int j = 0; j <= 1; j++){
            dp[v][i][j] = max(g[i ^ 1][j] + circs[v].r * circs[v].r * (i == 0 ? 1 : -1), g[i][j ^ 1] + circs[v].r * circs[v].r * (j == 0 ? 1 : -1));
        }
    }
}


signed main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> x >> y >> r;
        circs[i] = Circ(x, y, r);
        parent[i] = -1;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            if(isIn(circs[i], circs[j]) && (parent[i] == -1 || circs[j].r < circs[parent[i]].r)){
                parent[i] = j;
            }
        }
        if(parent[i] != -1)
            childs[parent[i]].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(parent[i] == -1){
            dfs(i);
            ans += dp[i][0][0];
        }
    }
    printf("%.10lf\n", ans * PI);

}
