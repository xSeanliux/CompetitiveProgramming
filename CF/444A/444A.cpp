#include <iostream>
#include <iomanip>
#define int long long int
using namespace std;

const int maxN = 526;

int N, M, a, b, c, val[maxN], adj[maxN][maxN], curV, curE, newV, newE;

signed main(){
    cout << fixed << setprecision(10);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> val[i];
    }
    for(int i = 1; i <= M; i++){
        cin >> a >> b >> c;
        adj[a][b] = adj[b][a] = c;
        if(!curE || (val[a] + val[b]) * curE > curV * c){
            curV = val[a] + val[b];
            curE = c;
        }
    }
    cout << (curE ? 1.0 * curV / curE : 0) << endl;
}

