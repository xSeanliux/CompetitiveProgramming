#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

const int maxN = 1e3 + 226;
const double eps = 1e-10, INF = 1e10;

int N, l, from[maxN], ans[maxN], m;
double x[maxN], b[maxN], minDist[maxN];

bool check(double r){
    fill(minDist, minDist + N + 1, INF);
    minDist[0] = 0;
    //edge between i & j: sqrt(x[j] - x[i] - l) - r * b[j]
    for(int i = 0; i <= N; i++){
        for(int j = i + 1; j <= N; j++){
            if(minDist[i] + sqrt(abs(x[j] - x[i] - l)) - r * b[j] < minDist[j]){
                minDist[j] = minDist[i] + sqrt(abs(x[j] - x[i] - l)) - r * b[j];
                from[j] = i;
            }
        }
    }
    return minDist[N] <= eps;
}

int main(){
    cin >> N >> l;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> b[i];
    }
    double L = 0, R = INF, M;
    while(R - L > eps){
        M = (L + R) / 2;
        if(check(M)) R = M;
        else L = M;
    }
    for(int i = N; i; i = from[i]) ans[m++] = i;
    for(int i = m - 1; i >= 0; i--) cout << ans[i] << " ";
}
