#include <iostream>
#include <iomanip>
using namespace std;

const int maxIt = 500;
const long double factor = 1e7;

long double f[maxIt][6], n, k, ans;

int main(){
    scanf("%Lf%Lf", &k, &n);
    //cin >> k >> n;
    f[1][1] = factor * 1.0/k;
    f[1][0] = factor * (1.0 - 1.0/k);
    for(int i = 2; i < maxIt; i++){
        f[i][0] = 0;
        for(int j = 0; j < n; j++) f[i][0] += f[i - 1][j];
        f[i][0] *= (1.0 - 1.0/k);
        for(int j = 1; j <= n; j++){
            f[i][j] = f[i - 1][j - 1] * (1.0/k);
        }
        //cout << "f[" << i << "][" << (int)n << "] = " << f[i][(int)n] << endl;
    }
    for(int i = 1; i < maxIt; i++){
        ans += i * f[i][(int)n];
    }
    printf("%.5Lf\n", ans / factor);
}
